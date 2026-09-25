# Primeiros passos

[Índice](INDEX.md) · [Arquitetura](Architecture.md) · [Testes](Testing.md)

Congro;Library é uma biblioteca experimental C11, organizada em headers e páginas
de implementação incluídas. Copie ou clone o repositório e adicione `Codespace`
aos diretórios de include. Preserve a árvore `Congro`: os includes internos são
relativos. Não compile `.impl` como arquivos `.c` nem procure uma biblioteca
Congro separada para linkar.

## Primeiro programa

O exemplo completo [examples/Container.c](examples/Container.c) cria um vetor,
insere um valor, consulta-o e libera seus recursos. Na raiz do repositório:

```sh
cc -std=c11 -D_POSIX_C_SOURCE=200809L -Wall -Wextra -Wpedantic -Werror \
  -ICodespace docs/examples/Container.c -o congro-example
./congro-example
```

Troque `cc` por `gcc` ou `clang` para selecionar o compilador. Em POSIX, a macro
`_POSIX_C_SOURCE=200809L` deve ser definida antes do primeiro header de sistema;
prefira a linha de comando. No Windows com MSVC, execute no Developer Command
Prompt, a partir da raiz:

```bat
cl /nologo /TC /std:c11 /W4 /ICodespace docs\examples\Container.c /Fe:congro-example.exe
congro-example.exe
```

Com MinGW, use a forma GCC sem a definição POSIX. Os exemplos não pedem
`-lm`, `-lws2_32` ou `-pthread` nos ambientes modernos usados pelo projeto.
Header-only não significa ausência de dependências do SO: Concurrency usa
pthreads em POSIX, por exemplo; plataformas antigas podem ter contrato de
linkagem diferente. A matriz pretendida é Linux GCC/Clang, macOS Clang e
Windows MinGW/MSVC; confira resultados de CI para o commit utilizado.

## Fluxo de uso

1. Selecione o módulo e seu header público no índice.
2. Defina configurações de namespace e pseudo-métodos antes do primeiro include.
3. Escolha uma instância pronta ou gere uma família com sufixo exclusivo.
4. Inicialize objetos, cheque retornos e mantenha seus recursos vivos.
5. Destrua objetos proprietários ao terminar, inclusive nos caminhos de erro.

`OPSTATUS` com `STATUS_CONST(SUCCESS)` é o padrão de operações falíveis, mas
existem retornos bool, ponteiros e estruturas de resultado em APIs específicas.
Siga o contrato documentado para a função usada, sem presumir uniformidade total.

Os exemplos retornam zero quando verificam o resultado esperado; valores não
zero indicam falha. Não precisam de serviços externos. Para executar todos:

```sh
python3 docs/tools/check_docs.py --compile
```
