# Testes e manutenção da documentação

[Índice](INDEX.md)

## Documentação

Na raiz do repositório:

```sh
python3 docs/tools/check_docs.py
python3 docs/tools/check_docs.py --compile
```

O primeiro comando verifica links locais, cobertura dos diretórios de módulos e
sincronização dos exemplos incorporados nos guias. O segundo também compila e
executa cada exemplo com GCC e Clang disponíveis, em C11 estrito. Ele falha se
nenhum compilador estiver disponível. Executáveis temporários ficam fora da
árvore do projeto. Essa verificação não executa a matriz Windows/macOS.

A referência de assinaturas é derivada dos headers e páginas `.impl`/`.space`
que expõem funções diretamente. Ela preserva parâmetros genéricos, como TYPE e
SUFFIX; não é uma lista de todas as expansões concretas do pré-processador.
As condições de plataforma e configuração continuam definidas no header
vinculado. Para atualizar após modificar a API:

```sh
python3 docs/tools/generate_api.py
python3 docs/tools/check_docs.py --compile
```

Revise também o texto do guia: geração de assinaturas não infere ownership,
limitações, complexidade ou comportamento de erros. Edite exemplos `.c` e o
bloco correspondente no guia juntos; a verificação detecta divergência.

## Testes do projeto

Há um Makefile por diretório de testes. Exemplo:

```sh
make -C Codespace/Tests/Bit CC=gcc run
make -C Codespace/Tests/Bit CC=clang BUILD=.build-clang run
```

Leia o Makefile do módulo para alvos específicos e arquivos incluídos. A
[configuração CI](../.github/workflows/ci.yml) é a fonte dos comandos da matriz;
[o script MSVC](../.github/scripts/test-msvc.ps1) cobre o caminho Windows.
[o teste de headers públicos](../.github/scripts/test-public-headers.py) verifica
inclusão independente. Passar exemplos de documentação não equivale a testar
todas as funções da biblioteca em todas as plataformas.

## Outros documentos do projeto

| Documento | Conteúdo |
|---|---|
| [README](../README.md) | Visão geral e entrada pública. |
| [ROADMAP](../ROADMAP.md) | Metas e domínios futuros. |
| [Version](../Version.md) | Histórico de alterações. |
| [ENTROPY](../ENTROPY.md) | Versionamento por entropia e seu cálculo. |
| [LICENSE](../LICENSE) e [LICENSING](../LICENSING.md) | Texto da licença e justificativa do projeto. |
| [SECURITY](../SECURITY.md) | Relato de vulnerabilidades. |
| [CODE_OF_CONDUCT](../CODE_OF_CONDUCT.md) | Convivência e conduta. |
| [AUTHORS](../AUTHORS.md) | Autoria e créditos. |
| [CITATION.cff](../CITATION.cff) | Metadados de citação. |
| [Translations](../Translations) | Documentos traduzidos existentes. |

A licença declarada atualmente pelo repositório é EUPL-1.2-only. Use os
arquivos de licença como fonte autoritativa. Os novos guias de uso estão em
português brasileiro; os identificadores C permanecem exatamente como na API.
