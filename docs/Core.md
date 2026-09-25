# Core

[Índice](INDEX.md) · [Referência de assinaturas e macros](api/Core.md)

Core reúne a infraestrutura compartilhada pelos módulos. Inclua headers de
`Congro/Core` conforme a necessidade; não existe um `Core.h` agregador.

## Algorithm

`Algorithm/Comparison.h` define `TComparisonResult`, `TComparator`,
`COMPARISON_CONST(LOWER/EQUAL/HIGHER)` e as famílias de comparação. A ordenação
usa -1, 0 e 1. `COMPARISON_DECLARE` gera comparações de valores;
`COMPARISON_DECLARE_STRING` gera comparação de strings. `COMPARISON_FUNC(Bytes)`
recebe dois buffers e seus tamanhos; `Invoke` delega para um comparador.
`Comparison_Compare(TYPE, left, right)` seleciona a função pelo sufixo.

Essas comparações não assumem propriedade dos objetos. Comparar bytes de uma
struct com padding não substitui um comparador semântico; strings precisam
estar terminadas e válidas para a operação escolhida.

## Cast

`Cast/Cast.space` define nomes: `CAST_NS`, `CAST_TYPE`, `CAST_FUNC`,
`CAST_TYPE_TO_STRUCT` e `CAST_STRUCT_TO_TYPE`. Não implementa sozinho um catálogo
de conversões numéricas. As conversões concretas para tuplas são geradas pelos
headers de [Struct](modules/Struct.md).

## Error

`Error/Status.h` define `OPSTATUS` e `STATUS_CONST(NAME)`. O sucesso é
`STATUS_CONST(SUCCESS)`; compare pelo nome, não por um número literal.
`STATUS_NS` é alias de compatibilidade; prefira `STATUS_CONST` em código novo.

| Status | Significado |
|---|---|
| SUCCESS | Operação concluída. |
| GENERIC_ERROR | Falha sem classificação mais específica no contrato da chamada. |
| INVALID_ARGUMENT | Argumento inválido, como ponteiro obrigatório ausente. |
| OUT_OF_RANGE | Índice, tamanho ou valor fora do intervalo permitido. |
| OUT_OF_MEMORY | Falha de alocação. |
| NOT_FOUND / ALREADY_EXISTS | Ausência ou duplicidade de elemento. |
| NOT_SUPPORTED / NOT_AVAILABLE | Recurso não suportado ou indisponível. |
| BUSY / WOULD_BLOCK | Recurso ocupado ou operação que não pode progredir imediatamente. |
| TIMEOUT / CANCELLED | Tempo esgotado ou operação cancelada. |
| ARITHMETIC_OVERFLOW / DIVISION_BY_ZERO | Falha aritmética. |

Nem toda função retorna todos esses códigos. Consulte o módulo e a implementação
quando a distinção influenciar recuperação. Não há promessa global de manter
saídas intactas em caso de erro.

`Error/Panic.h` fornece `PANIC(message)` e `PANIC_ASSERT(condition)`, que registram
local de chamada e encerram por panic quando necessário. Não substituem tratamento
de erro recuperável. Stacktrace depende do backend e dos símbolos disponíveis.

## Memory

| Header | Operações | Contrato |
|---|---|---|
| `Memory/Alloc.h` | `AllocBytes`, `AllocArray`, `ReallocBytes`, `ReallocArray`, `FreePointer` via `ALLOC_FUNC` | Recebem `void **`; variantes Array verificam multiplicação de tamanho. |
| `Memory/Operations.h` | `Copy`, `Move`, `Set`, `Zero`, `CopyArray`, `MoveArray`, `ZeroArray` via `MEMORY_FUNC` | Tamanho em bytes ou contagem e tamanho de elemento. Move aceita sobreposição. |
| `Memory/Swap.h` | `SWAP_FUNC(Bytes)`, `SWAP_DECLARE`, `Memory_Swap` | Troca bytes ou valores de um tipo. |
| `Memory/Arena.h` | `Create`, `Alloc`, `AllocAligned`, `AllocArray`, `AllocArrayAligned`, `AllocTyped`, `Reset`, `Destroy` via `ARENA_FUNC` | Alocação linear em capacidade fixa, sem free individual. |

Para alocação tipada, use um temporário `void *` e publique o ponteiro tipado
somente após sucesso. Converter `T **` para `void **` não é a alternativa correta.
`Memory_Free(pointerLvalue)` recebe o próprio ponteiro e o zera; `FreePointer`
recebe seu endereço como `void **`. Zerar esse ponteiro não zera outros aliases.

Copy não deve receber regiões sobrepostas; use Move. Operações de bytes não
fazem cópia profunda, construtores ou validação do tamanho real de uma alocação.

A arena possui seu buffer. `Reset` permite reutilização e invalida logicamente
todas as alocações anteriores; não libera o buffer. `Destroy` libera o conjunto.
Use alinhamentos de tipos suportados, no máximo `ARENA_ALIGNMENT`; para tipos
sobrealinhados, não presuma suporte. Esgotar a capacidade retorna `OUT_OF_RANGE`.

<!-- example: Core.c -->

[Core.c](examples/Core.c)

```c
#include <assert.h>
#include "Congro/Core/Memory/Alloc.h"

int main(void) {
  void *storage = NULL;
  OPSTATUS status = ALLOC_FUNC(AllocArray)(&storage, 4, sizeof(int));
  if (status != STATUS_CONST(SUCCESS))
    return 1;
  int *values = storage;
  values[0] = 42;
  assert(values[0] == 42);
  Memory_Free(values);
  storage = NULL;
  assert(values == NULL);
  return 0;
}
```

## Namespace

`Namespace.h` compõe tokens com `GNS2`, `GNS3`, `GNS4`, `CNS2`, `CNS3` e `CNS4`.
`LIB_PREFIX` considera `CONGRO_NAMESPACE`; constantes têm
`CONGRO_NAMESPACE_CONST` e `LIB_PREFIX_CONST` separados. Defina ambos antes do
primeiro header quando quiser prefixos personalizados.

As macros TYPE/FUNC/CONST de cada módulo evitam escrever expansões manualmente.
Alguns aliases públicos históricos continuam sem prefixo: configuração de
namespace não é garantia de isolamento de absolutamente todos os identificadores.
Veja [arquitetura](Architecture.md) para configuração entre unidades de tradução.

## Preprocessor

| Header | Finalidade |
|---|---|
| `Arguments.h` | `PP_ARG_COUNT` e seleção de argumentos, com limite definido pela tabela. |
| `Boolean.h` | Condicionais e lógica no pré-processador. |
| `Operations.h`, `Tokens.h` | Concatenação e manipulação de tokens. |
| `Eval.h` | Expansão adiada e avaliação usada em macros recursivas. |
| `Foreach.h`, `Map.h` | Aplicação de macro a uma sequência de argumentos; `PP_MAP` usa `PP_FOREACH`. |
| `Repeat.h` | `PP_REPEAT` de 0 a 5; emite índices em ordem decrescente, de count a 1. |
| `Sequence.h` | `PP_SEQ_FIRST`, `PP_SEQ_REST`, seletores de 1 a 10. |
| `While.h` | Iteração por predicado/operação, limitada pela expansão do pré-processador. |
| `Detect/Compiler.h` | Macros de detecção de compilador. |
| `Detect/OperationSystem.h` | Macros de SO e família POSIX/Windows. |
| `Detect/Processor.h` | Macros de arquitetura de processador. |

Não são laços de runtime e não oferecem expansão ilimitada. Consulte os testes
antes de usar listas vazias, argumentos com vírgulas internas ou limites extremos.
[Compiling.inc](../Codespace/Congro/Core/Preprocessor/Compiling.inc) é infraestrutura
de compilação incluída pelos headers.

[Testes do Core](../Codespace/Tests/Core).
