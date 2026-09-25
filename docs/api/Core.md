# Core: referência de API

[Guia de uso](../Core.md) · [Índice](../INDEX.md)

Catálogo gerado por `docs/tools/generate_api.py`. As assinaturas preservam
as macros TYPE/FUNC e os parâmetros de geração: TYPE e SUFFIX não são tipos
literais para copiar. Consulte o guia para instâncias prontas, ownership,
erros e exemplos compiláveis. Declarações condicionais continuam sujeitas
ao compilador e às opções do header de origem.

Os links de arquivo incluem tipos, enums, constantes, macros geradoras e
tabelas completas. Headers de VTable são suporte dos pseudo-métodos;
não precisam ser incluídos separadamente pelo usuário.

## Arquivos e configuração

| Arquivo | Assinaturas extraídas |
|---|---|
| [Algorithm/Algorithm.space](../../Codespace/Congro/Core/Algorithm/Algorithm.space) | 0 |
| [Algorithm/Comparison.h](../../Codespace/Congro/Core/Algorithm/Comparison.h) | 3 |
| [Cast/Cast.space](../../Codespace/Congro/Core/Cast/Cast.space) | 0 |
| [Error/Error.space](../../Codespace/Congro/Core/Error/Error.space) | 0 |
| [Error/Panic.h](../../Codespace/Congro/Core/Error/Panic.h) | 0 |
| [Error/Status.h](../../Codespace/Congro/Core/Error/Status.h) | 0 |
| [Memory/Alloc.h](../../Codespace/Congro/Core/Memory/Alloc.h) | 5 |
| [Memory/Arena.h](../../Codespace/Congro/Core/Memory/Arena.h) | 8 |
| [Memory/Memory.space](../../Codespace/Congro/Core/Memory/Memory.space) | 0 |
| [Memory/Operations.h](../../Codespace/Congro/Core/Memory/Operations.h) | 7 |
| [Memory/Swap.h](../../Codespace/Congro/Core/Memory/Swap.h) | 2 |
| [Namespace.h](../../Codespace/Congro/Core/Namespace.h) | 0 |
| [Preprocessor/Arguments.h](../../Codespace/Congro/Core/Preprocessor/Arguments.h) | 0 |
| [Preprocessor/Boolean.h](../../Codespace/Congro/Core/Preprocessor/Boolean.h) | 0 |
| [Preprocessor/Detect/Compiler.h](../../Codespace/Congro/Core/Preprocessor/Detect/Compiler.h) | 0 |
| [Preprocessor/Detect/OperationSystem.h](../../Codespace/Congro/Core/Preprocessor/Detect/OperationSystem.h) | 0 |
| [Preprocessor/Detect/Processor.h](../../Codespace/Congro/Core/Preprocessor/Detect/Processor.h) | 0 |
| [Preprocessor/Eval.h](../../Codespace/Congro/Core/Preprocessor/Eval.h) | 0 |
| [Preprocessor/Foreach.h](../../Codespace/Congro/Core/Preprocessor/Foreach.h) | 0 |
| [Preprocessor/Map.h](../../Codespace/Congro/Core/Preprocessor/Map.h) | 0 |
| [Preprocessor/Operations.h](../../Codespace/Congro/Core/Preprocessor/Operations.h) | 0 |
| [Preprocessor/Repeat.h](../../Codespace/Congro/Core/Preprocessor/Repeat.h) | 0 |
| [Preprocessor/Sequence.h](../../Codespace/Congro/Core/Preprocessor/Sequence.h) | 0 |
| [Preprocessor/Tokens.h](../../Codespace/Congro/Core/Preprocessor/Tokens.h) | 0 |
| [Preprocessor/While.h](../../Codespace/Congro/Core/Preprocessor/While.h) | 0 |

## Algorithm/Algorithm.space

[Declarações e implementação](../../Codespace/Congro/Core/Algorithm/Algorithm.space)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `ALGORITHM_NS(NAME)`
- `ALGORITHM_TYPE(NAME)`
- `ALGORITHM_FUNC(NAME)`
- `ALGORITHM_CONST(NAME)`


## Algorithm/Comparison.h

[Declarações e implementação](../../Codespace/Congro/Core/Algorithm/Comparison.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `COMPARISON_TYPE(NAME)`
- `COMPARISON_FUNC(NAME)`
- `COMPARISON_CONST(NAME)`
- `COMPARISON_TABLE(X)`
- `COMPARISON_DECLARE(TYPE, SUFFIX)`
- `COMPARISON_DECLARE_STRING(TYPE, SUFFIX)`
- `Comparison_Compare(TYPE, left, right)`

```c
TComparisonResult COMPARISON_FUNC(SUFFIX)(TYPE left, TYPE right);

TComparisonResult COMPARISON_FUNC(Bytes)( const void *left, size_t leftSize, const void *right,
    size_t rightSize);

TComparisonResult COMPARISON_FUNC(Invoke)( const void *left, const void *right, TComparator
    comparator);

```

## Cast/Cast.space

[Declarações e implementação](../../Codespace/Congro/Core/Cast/Cast.space)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `CAST_NS(NAME)`
- `CAST_TYPE(NAME)`
- `CAST_FUNC(NAME)`


## Error/Error.space

[Declarações e implementação](../../Codespace/Congro/Core/Error/Error.space)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `ERROR_NS(NAME)`
- `ERROR_TYPE(NAME)`
- `ERROR_FUNC(NAME)`
- `ERROR_CONST(NAME)`


## Error/Panic.h

[Declarações e implementação](../../Codespace/Congro/Core/Error/Panic.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `PANIC(message)`
- `PANIC_ASSERT(condition)`


## Error/Status.h

[Declarações e implementação](../../Codespace/Congro/Core/Error/Status.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `STATUS_TYPE(NAME)`
- `STATUS_CONST_PREFIXED(PREFIX, NAME)`
- `STATUS_CONST(NAME)`
- `STATUS_NS(NAME)`
- `OPSTATUS`
- `STATUS_TABLE(X)`
- `STATUS_ENUM_ITEM(NAME, MESSAGE)`


## Memory/Alloc.h

[Declarações e implementação](../../Codespace/Congro/Core/Memory/Alloc.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `ALLOC_FUNC(NAME)`
- `MEMORY_MAX_ALIGNMENT`
- `Memory_Free(pointerLvalue)`

```c
OPSTATUS ALLOC_FUNC(AllocBytes)(void **out, size_t size);

OPSTATUS ALLOC_FUNC(AllocArray)(void **out, size_t count, size_t elementSize);

OPSTATUS ALLOC_FUNC(ReallocBytes)(void **ptr, size_t size);

OPSTATUS ALLOC_FUNC(ReallocArray)(void **ptr, size_t count, size_t elementSize);

OPSTATUS ALLOC_FUNC(FreePointer)(void **ptr);

```

## Memory/Arena.h

[Declarações e implementação](../../Codespace/Congro/Core/Memory/Arena.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `ARENA_TYPE(NAME)`
- `ARENA_FUNC(NAME)`
- `ARENA_CONST(NAME)`
- `ARENA_ALIGNMENT`
- `Memory_Arena_Alloc(arena, type, out, count)`

```c
OPSTATUS ARENA_FUNC(Create)(TArena *arena, size_t capacity);

OPSTATUS ARENA_FUNC(Alloc)(TArena *arena, void **out, size_t size);

OPSTATUS ARENA_FUNC(AllocAligned)(TArena *arena, void **out, size_t size, size_t alignment);

OPSTATUS ARENA_FUNC(AllocArray)(TArena *arena, void **out, size_t count, size_t elementSize);

OPSTATUS ARENA_FUNC(AllocArrayAligned)( TArena *arena, void **out, size_t count, size_t
    elementSize, size_t alignment);

OPSTATUS ARENA_FUNC(AllocTyped)( TArena *arena, void *outPointerObject, size_t count, size_t
    elementSize, size_t alignment);

OPSTATUS ARENA_FUNC(Reset)(TArena *arena);

OPSTATUS ARENA_FUNC(Destroy)(TArena *arena);

```

## Memory/Memory.space

[Declarações e implementação](../../Codespace/Congro/Core/Memory/Memory.space)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `MEMORY_NS(NAME)`
- `MEMORY_TYPE(NAME)`
- `MEMORY_FUNC(NAME)`
- `MEMORY_CONST(NAME)`


## Memory/Operations.h

[Declarações e implementação](../../Codespace/Congro/Core/Memory/Operations.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `Memory_CopyTyped(type, destination, source, count)`
- `Memory_MoveTyped(type, destination, source, count)`
- `Memory_ZeroTyped(type, destination, count)`

```c
OPSTATUS MEMORY_FUNC(Copy)(void *destination, const void *source, size_t size);

OPSTATUS MEMORY_FUNC(Move)(void *destination, const void *source, size_t size);

OPSTATUS MEMORY_FUNC(Set)(void *destination, int value, size_t size);

OPSTATUS MEMORY_FUNC(Zero)(void *destination, size_t size);

OPSTATUS MEMORY_FUNC(CopyArray)( void *destination, const void *source, size_t count, size_t
    elementSize);

OPSTATUS MEMORY_FUNC(MoveArray)( void *destination, const void *source, size_t count, size_t
    elementSize);

OPSTATUS MEMORY_FUNC(ZeroArray)( void *destination, size_t count, size_t elementSize);

```

## Memory/Swap.h

[Declarações e implementação](../../Codespace/Congro/Core/Memory/Swap.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `SWAP_FUNC(NAME)`
- `SWAP_CONST(NAME)`
- `SWAP_BLOCK_SIZE`
- `SWAP_DECLARE(TYPE, SUFFIX)`
- `Memory_Swap(TYPE, LEFT, RIGHT)`

```c
OPSTATUS SWAP_FUNC(Bytes)(void *left, void *right, size_t size);

void SWAP_FUNC(SUFFIX)(TYPE *left, TYPE *right);

```

## Namespace.h

[Declarações e implementação](../../Codespace/Congro/Core/Namespace.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `CONGRO_SEPARATOR_TOKEN`
- `CONGRO_SEPARATOR(NAME)`
- `CONGRO_NAMESPACE_JOIN(SCOPE, NAME)`
- `GNS2(SCOPE, NAME)`
- `GNS3(SCOPE, SPACE, NAME)`
- `GNS4(SCOPE, SPACE, SUBSPACE, NAME)`
- `LIB_PREFIX(SPACE)`
- `CNS2(SCOPE, NAME)`
- `CNS3(SCOPE, SPACE, NAME)`
- `CNS4(SCOPE, SPACE, SUBSPACE, NAME)`
- `LIB_PREFIX_CONST(SPACE)`


## Preprocessor/Arguments.h

[Declarações e implementação](../../Codespace/Congro/Core/Preprocessor/Arguments.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `PP_ARG_RSEQ()`
- `PP_ARG_COUNT(...)`


## Preprocessor/Boolean.h

[Declarações e implementação](../../Codespace/Congro/Core/Preprocessor/Boolean.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `PP_BOOL(x)`
- `PP_BOOL_NOT(x)`
- `PP_BOOL_IF(cond)`
- `PP_BOOL_IF_ELSE(cond)`
- `PP_BOOL_AND(a, b)`
- `PP_BOOL_OR(a, b)`
- `PP_BOOL_XOR(a, b)`


## Preprocessor/Detect/Compiler.h

[Declarações e implementação](../../Codespace/Congro/Core/Preprocessor/Detect/Compiler.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `COMPILER_INTEL`
- `COMPILER_CLANG`
- `COMPILER_MSVC`
- `COMPILER_GCC`
- `COMPILER_KNOWN`


## Preprocessor/Detect/OperationSystem.h

[Declarações e implementação](../../Codespace/Congro/Core/Preprocessor/Detect/OperationSystem.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `OS_WINDOWS`
- `WIN32_LEAN_AND_MEAN`
- `OS_MAC`
- `OS_LINUX`
- `OS_FREEBSD`
- `OS_UNIX`
- `OS_POSIX`
- `OS_KNOWN`


## Preprocessor/Detect/Processor.h

[Declarações e implementação](../../Codespace/Congro/Core/Preprocessor/Detect/Processor.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `PROCESSOR_X86`
- `PROCESSOR_X64`
- `PROCESSOR_ARM`
- `PROCESSOR_ARM64`
- `PROCESSOR_RISCV`
- `PROCESSOR_KNOWN`


## Preprocessor/Eval.h

[Declarações e implementação](../../Codespace/Congro/Core/Preprocessor/Eval.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `PP_EMPTY()`
- `PP_DEFER(id)`
- `PP_OBSTRUCT(...)`
- `PP_EVAL(...)`
- `PP_EVAL1(...)`
- `PP_EVAL2(...)`
- `PP_EVAL3(...)`


## Preprocessor/Foreach.h

[Declarações e implementação](../../Codespace/Congro/Core/Preprocessor/Foreach.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `PP_FOREACH(macro, ...)`


## Preprocessor/Map.h

[Declarações e implementação](../../Codespace/Congro/Core/Preprocessor/Map.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `PP_MAP(macro, ...)`


## Preprocessor/Operations.h

[Declarações e implementação](../../Codespace/Congro/Core/Preprocessor/Operations.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `PP_OP_EXPAND(...)`
- `PP_OP_CAT(a, b)`
- `PP_OP_CAT2(a, b)`
- `PP_OP_CAT3(a, b, c)`
- `PP_OP_CAT4(a, b, c, d)`
- `PP_OP_CAT5(a, b, c, d, e)`
- `PP_OP_CAT6(a, b, c, d, e, f)`
- `PP_OP_CAT7(a, b, c, d, e, f, g)`
- `PP_OP_CAT8(a, b, c, d, e, f, g, h)`
- `PP_OP_CAT9(a, b, c, d, e, f, g, h, i)`
- `PP_OP_CAT10(a, b, c, d, e, f, g, h, i, j)`


## Preprocessor/Repeat.h

[Declarações e implementação](../../Codespace/Congro/Core/Preprocessor/Repeat.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `PP_REPEAT(count, macro)`
- `PP_DEC(x)`


## Preprocessor/Sequence.h

[Declarações e implementação](../../Codespace/Congro/Core/Preprocessor/Sequence.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `PP_SEQ_FIRST(first, ...)`
- `PP_SEQ_REST(first, ...)`


## Preprocessor/Tokens.h

[Declarações e implementação](../../Codespace/Congro/Core/Preprocessor/Tokens.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `PP_TOKEN_EMPTY()`
- `PP_TOKEN_COMMA()`
- `PP_TOKEN_LPAREN()`
- `PP_TOKEN_RPAREN()`
- `PP_TOKEN_TILDE()`


## Preprocessor/While.h

[Declarações e implementação](../../Codespace/Congro/Core/Preprocessor/While.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `PP_WHILE(pred, op, state)`
- `PP_WHILE_INDIRECT()`
