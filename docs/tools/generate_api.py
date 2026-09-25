#!/usr/bin/env python3
"""Generate a source-linked catalogue without expanding Congro's C macros."""
from pathlib import Path
import re
import textwrap

ROOT = Path(__file__).resolve().parents[2]
SOURCE = ROOT / 'Codespace/Congro'


def signatures(text):
    text = re.sub(r'/\*.*?\*/', '', text, flags=re.S)
    text = re.sub(r'\\\s*\n', '\n', text)
    found = []
    for match in re.finditer(r'\b(?:inline\s+static|static\s+inline)\s+', text):
        start = match.end()
        cursor = start
        while True:
            opening = text.find('(', cursor)
            if opening < 0 or any(c in text[cursor:opening] for c in ';{#'):
                break
            token = re.search(r'(\w+)\s*$', text[cursor:opening])
            if not token:
                break
            depth = 1
            end = opening + 1
            while end < len(text) and depth:
                depth += (text[end] == '(') - (text[end] == ')')
                end += 1
            after = end
            while after < len(text) and text[after].isspace():
                after += 1
            if after < len(text) and text[after] == '(':
                depth = 1
                end = after + 1
                while end < len(text) and depth:
                    depth += (text[end] == '(') - (text[end] == ')')
                    end += 1
            elif token.group(1).endswith(('_TYPE', '_NODE')):
                cursor = end
                continue
            value = ' '.join(text[start:end].split())
            name = value.split(')(')[0]
            internal = re.search(r'\(\s*_|,\s*_|Internal|INTERNAL|FUNCTION_NAME', name)
            tree_operation = re.search(r'TTREE_FN\(T, (\w+)\)', value)
            public_tree = {'Init', 'Destroy', 'Clear', 'Insert', 'Remove', 'Find',
                           'FindNode', 'Contains', 'MinNode', 'MaxNode', 'Min', 'Max',
                           'Empty', 'Size', 'Begin', 'End', 'Next', 'Prev',
                           'ConstBegin', 'ConstEnd', 'ConstNext', 'ConstPrev'}
            if tree_operation and tree_operation.group(1) not in public_tree:
                internal = True
            if not internal and value not in found:
                found.append(value)
            break
    return found


def macros(text):
    result = []
    text = re.sub(r'/\*.*?\*/', '', text, flags=re.S)
    text = re.sub(r'\\\s*\n', ' ', text)
    for name, args in re.findall(r'^\s*#define\s+(\w+)(\([^)]*\))?', text, re.M):
        if re.search(r'PROTOTYPE|IMPLEMENT|INTERNAL|_IMPL|FUNCTION_TABLE|_STRUCT|VTABLE_FORWARD|API_MEMBER', name):
            continue
        if name == 'X' or re.search(r'_(?:[0-9]+|SELECT|RAW)$', name):
            continue
        value = name + ' '.join(args.split())
        if value not in result:
            result.append(value)
    return result


def generate():
    groups = {'Core': SOURCE / 'Core'}
    groups.update({p.name: p for p in sorted((SOURCE / 'Modules').iterdir()) if p.is_dir()})
    for name, directory in groups.items():
        guide = '../Core.md' if name == 'Core' else f'../modules/{name}.md'
        lines = [f'# {name}: referência de API', '', f'[Guia de uso]({guide}) · [Índice](../INDEX.md)', '',
                 'Catálogo gerado por `docs/tools/generate_api.py`. As assinaturas preservam',
                 'as macros TYPE/FUNC e os parâmetros de geração: TYPE e SUFFIX não são tipos',
                 'literais para copiar. Consulte o guia para instâncias prontas, ownership,',
                 'erros e exemplos compiláveis. Declarações condicionais continuam sujeitas',
                 'ao compilador e às opções do header de origem.', '',
                 'Os links de arquivo incluem tipos, enums, constantes, macros geradoras e',
                 'tabelas completas. Headers de VTable são suporte dos pseudo-métodos;',
                 'não precisam ser incluídos separadamente pelo usuário.', '']
        files = sorted(p for p in directory.rglob('*') if p.suffix in ('.h', '.space'))
        lines += ['## Arquivos e configuração', '', '| Arquivo | Assinaturas extraídas |', '|---|---|']
        for path in files:
            sigs = signatures(path.read_text())
            relative = path.relative_to(directory).as_posix()
            link = '../../' + path.relative_to(ROOT).as_posix()
            lines.append(f'| [{relative}]({link}) | {len(sigs)} |')
        # Functions occasionally live directly in implementation pages without prototypes.
        seen = {re.sub(r'\s+', '', s) for p in files for s in signatures(p.read_text())}
        extras = []
        for path in sorted(directory.rglob('*.impl')):
            direct = [s for s in signatures(path.read_text()) if re.sub(r'\s+', '', s) not in seen]
            if direct:
                extras.append((path, direct))
                seen.update(re.sub(r'\s+', '', s) for s in direct)
        for path, sigs in [(p, signatures(p.read_text())) for p in files] + extras:
            macro_list = macros(path.read_text()) if path.suffix in ('.h', '.space') else []
            if not sigs and not macro_list:
                continue
            relative = path.relative_to(directory).as_posix()
            link = '../../' + path.relative_to(ROOT).as_posix()
            lines += ['', f'## {relative}', '', f'[Declarações e implementação]({link})', '']
            if macro_list:
                lines += ['Macros de seleção, configuração ou geração (consulte o header para expansão):', '']
                lines += ['- `' + macro + '`' for macro in macro_list]
                lines += ['']
            if not sigs:
                continue
            lines += ['```c']
            for sig in sigs:
                lines += textwrap.wrap(sig + ';', width=96, subsequent_indent='    ',
                                       break_long_words=False, break_on_hyphens=False)
                lines.append('')
            lines += ['```']
        out = ROOT / 'docs/api' / f'{name}.md'
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text('\n'.join(lines).rstrip() + '\n')
        print(f'{name}: {len(files)} headers/configurações')


if __name__ == '__main__':
    generate()
