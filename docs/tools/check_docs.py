#!/usr/bin/env python3
"""Validate documentation coverage, local links, example copies and C programs."""
import argparse
from pathlib import Path
import re
import shutil
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[2]
DOCS = ROOT / 'docs'


def check():
    errors = []
    modules = ROOT / 'Codespace/Congro/Modules'
    for module in sorted(p.name for p in modules.iterdir() if p.is_dir()):
        for subdir in ('modules', 'api'):
            if not (DOCS / subdir / f'{module}.md').is_file():
                errors.append(f'Missing {subdir}/{module}.md')
    for page in sorted(DOCS.rglob('*.md')):
        text = page.read_text()
        for target in re.findall(r'\]\(([^\s]+)\)', text):
            if target.startswith(('http:', 'https:', 'mailto:', '#')):
                continue
            target = target.split('#')[0]
            if target and not (page.parent / target).exists():
                errors.append(f'{page.relative_to(ROOT)}: missing {target}')
        for match in re.finditer(r'<!-- example: ([\w]+\.c) -->\s*\[[^\]]+\]\([^)]+\)\s*```c\n(.*?)\n```', text, re.S):
            name, code = match.groups()
            source = DOCS / 'examples' / name
            if not source.is_file() or source.read_text().strip() != code.strip():
                errors.append(f'{page.relative_to(ROOT)}: example {name} differs')
        markers = re.findall(r'<!-- example: ([\w]+\.c) -->', text)
        rendered = re.findall(r'<!-- example: ([\w]+\.c) -->\s*\[', text)
        if markers != rendered:
            errors.append(f'{page.relative_to(ROOT)}: unrendered example')
    for example in sorted((DOCS / 'examples').glob('*.c')):
        marker = f'<!-- example: {example.name} -->'
        if not any(marker in p.read_text() for p in DOCS.rglob('*.md')):
            errors.append(f'Unlinked example: {example.name}')
    if errors:
        raise SystemExit('\n'.join(errors))
    print('Links, cobertura de módulos e exemplos: OK', flush=True)


def compile_examples():
    compilers = [cc for cc in ('gcc', 'clang') if shutil.which(cc)]
    if not compilers:
        raise SystemExit('GCC/Clang não encontrado')
    with tempfile.TemporaryDirectory(prefix='congro-docs-') as temporary:
        for cc in compilers:
            for source in sorted((DOCS / 'examples').glob('*.c')):
                binary = Path(temporary) / (cc + '-' + source.stem)
                subprocess.run([cc, '-std=c11', '-D_POSIX_C_SOURCE=200809L',
                                '-Wall', '-Wextra', '-Wpedantic', '-Werror',
                                '-I' + str(ROOT / 'Codespace'), str(source),
                                '-o', str(binary)], check=True, timeout=60)
                subprocess.run([str(binary)], check=True, timeout=15)
                print(f'{cc}: {source.name}: OK', flush=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--compile', action='store_true', help='Build and run C examples')
    args = parser.parse_args()
    check()
    if args.compile:
        compile_examples()
