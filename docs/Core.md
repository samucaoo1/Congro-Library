# Core

Core contains the infrastructure used by every higher-level Congro module:
namespaces, status codes, allocation, arenas, memory operations, comparison,
casting helpers, panic facilities, and preprocessor metaprogramming.

## Namespace

**Header:** `Codespace/Congro/Core/Namespace.h`

Main helpers:

| Macro | Purpose |
| --- | --- |
| `GNS2(scope, name)` | Joins two namespace components with `_`. |
| `GNS3(scope, space, name)` | Three-component symbol. |
| `GNS4(scope, space, subspace, name)` | Four-component symbol. |
| `LIB_PREFIX(space)` | Adds `CONGRO_NAMESPACE` when configured. |
| `CNS2/CNS3/CNS4` | Constant-namespace equivalents. |
| `LIB_PREFIX_CONST(space)` | Adds `CONGRO_NAMESPACE_CONST` to constants. |

Example:

```c
#define CONGRO_NAMESPACE Demo
#include "Congro/Modules/Bit/Bit.h"

/* BIT_FUNC(32, Popcount) expands to Demo_Bit_32_Popcount. */
```

See [Calling conventions](CALLING_CONVENTIONS.md).

## Error / OPSTATUS

**Header:** `Codespace/Congro/Core/Error/Status.h`

`OPSTATUS` is the standard operational status type.

Current values:

`SUCCESS`, `GENERIC_ERROR`, `INVALID_ARGUMENT`, `OUT_OF_RANGE`,
`OUT_OF_MEMORY`, `NOT_FOUND`, `ALREADY_EXISTS`, `NOT_SUPPORTED`,
`NOT_AVAILABLE`, `BUSY`, `WOULD_BLOCK`, `TIMEOUT`, `CANCELLED`,
`ARITHMETIC_OVERFLOW`, and `DIVISION_BY_ZERO`.

Indirect:

```c
if (status == STATUS_CONST(SUCCESS)) {
    /* success */
}
```

Default direct constant:

```c
if (status == CONGRO_STATUS_SUCCESS) {
    /* success */
}
```

### Panic

**Header:** `Codespace/Congro/Core/Error/Panic.h`

`PANIC(message)` captures message, file, line, and function, then routes through
the internal panic trigger. `Panic` is intended for unrecoverable programmer or
runtime failures; normal API errors should use `OPSTATUS`.

## Algorithm / Comparison

**Header:** `Codespace/Congro/Core/Algorithm/Comparison.h`

`TComparisonResult` has three values: lower, equal, and higher.
`TComparator` is the generic comparator callback type.

| Indirect | Direct | Description |
| --- | --- | --- |
| `COMPARISON_FUNC(Bytes)(a, as, b, bs)` | `Comparison_Bytes(a, as, b, bs)` | Lexicographically compares byte ranges, accounting for lengths. |
| `COMPARISON_FUNC(Invoke)(a, b, cmp)` | `Comparison_Invoke(a, b, cmp)` | Calls a generic `TComparator`. |
| `Comparison_Compare(TYPE, a, b)` | generated `Comparison_TYPE(a, b)` | Convenience dispatch to a typed comparison. |

Example:

```c
TComparisonResult result =
    COMPARISON_FUNC(Bytes)("abc", 3, "abd", 3);
```

Direct:

```c
TComparisonResult result =
    Comparison_Bytes("abc", 3, "abd", 3);
```

## Memory / Allocation

**Header:** `Codespace/Congro/Core/Memory/Alloc.h`

| Indirect | Direct | Description |
| --- | --- | --- |
| `ALLOC_FUNC(AllocBytes)(&p, size)` | `Memory_AllocBytes(&p, size)` | Allocates raw bytes. |
| `ALLOC_FUNC(AllocArray)(&p, n, elem)` | `Memory_AllocArray(&p, n, elem)` | Allocates an array with overflow checking. |
| `ALLOC_FUNC(ReallocBytes)(&p, size)` | `Memory_ReallocBytes(&p, size)` | Resizes a raw allocation. |
| `ALLOC_FUNC(ReallocArray)(&p, n, elem)` | `Memory_ReallocArray(&p, n, elem)` | Resizes an array with count/size checks. |
| `ALLOC_FUNC(FreePointer)(&p)` | `Memory_FreePointer(&p)` | Frees through a `void **` and clears the pointer. |
| `Memory_Free(p)` | same macro | Frees a pointer lvalue and sets it to `NULL`. |

Example:

```c
void *memory = NULL;

if (ALLOC_FUNC(AllocArray)(&memory, 64, sizeof(int)) ==
    STATUS_CONST(SUCCESS)) {
    Memory_Free(memory);
}
```

Direct:

```c
if (Memory_AllocArray(&memory, 64, sizeof(int)) ==
    CONGRO_STATUS_SUCCESS) {
    Memory_Free(memory);
}
```

### Memory operations

**Header:** `Codespace/Congro/Core/Memory/Operations.h`

| Indirect | Direct | Description |
| --- | --- | --- |
| `MEMORY_FUNC(Copy)(dst, src, bytes)` | `Memory_Copy(dst, src, bytes)` | Non-overlapping copy. |
| `MEMORY_FUNC(Move)(dst, src, bytes)` | `Memory_Move(dst, src, bytes)` | Overlap-safe move. |
| `MEMORY_FUNC(Set)(dst, value, bytes)` | `Memory_Set(dst, value, bytes)` | Byte fill. |
| `MEMORY_FUNC(Zero)(dst, bytes)` | `Memory_Zero(dst, bytes)` | Zeroes a byte range. |
| `MEMORY_FUNC(CopyArray)(dst, src, n, elem)` | `Memory_CopyArray(...)` | Array-sized copy. |
| `MEMORY_FUNC(MoveArray)(dst, src, n, elem)` | `Memory_MoveArray(...)` | Array-sized move. |
| `MEMORY_FUNC(ZeroArray)(dst, n, elem)` | `Memory_ZeroArray(...)` | Zeroes an array. |

### Swap

**Header:** `Codespace/Congro/Core/Memory/Swap.h`

```c
SWAP_FUNC(Bytes)(&a, &b, sizeof(a));
Memory_Swap(int, a, b);
```

Direct function:

```c
Swap_Bytes(&a, &b, sizeof(a));
```

## Arena

**Header:** `Codespace/Congro/Core/Memory/Arena.h`

`TArena` owns one buffer and advances an offset for allocations.

| Indirect | Direct | Description |
| --- | --- | --- |
| `ARENA_FUNC(Create)(&arena, capacity)` | `Arena_Create(...)` | Creates backing storage. |
| `ARENA_FUNC(Alloc)(&arena, &p, size)` | `Arena_Alloc(...)` | Raw arena allocation. |
| `ARENA_FUNC(AllocAligned)(...)` | `Arena_AllocAligned(...)` | Allocation with explicit alignment. |
| `ARENA_FUNC(AllocArray)(...)` | `Arena_AllocArray(...)` | Array allocation. |
| `ARENA_FUNC(AllocArrayAligned)(...)` | `Arena_AllocArrayAligned(...)` | Aligned array allocation. |
| `ARENA_FUNC(AllocTyped)(...)` | `Arena_AllocTyped(...)` | Typed-pointer publishing helper. |
| `ARENA_FUNC(Reset)(&arena)` | `Arena_Reset(&arena)` | Rewinds the arena without freeing its buffer. |
| `ARENA_FUNC(Destroy)(&arena)` | `Arena_Destroy(&arena)` | Releases backing storage. |
| `Memory_Arena_Alloc(&arena, T, &p, n)` | same macro | Ergonomic typed allocation. |

Example:

```c
TArena arena = {0};
int *values = NULL;

if (ARENA_FUNC(Create)(&arena, 4096) == STATUS_CONST(SUCCESS)) {
    Memory_Arena_Alloc(&arena, int, &values, 32);
    ARENA_FUNC(Reset)(&arena);
    ARENA_FUNC(Destroy)(&arena);
}
```

## Cast

**Header:** `Codespace/Congro/Core/Cast/Cast.space`

Cast naming is generated by:

```c
CAST_TYPE_TO_STRUCT(SUFFIX, TYPE)
CAST_STRUCT_TO_TYPE(TYPE, SUFFIX)
```

For example the Struct module uses these to create conversions between primitive
values and `TPair`, `TDual`, `TTriple`, `TQuad`, and `TPenta`.

## Preprocessor

**Directory:** `Codespace/Congro/Core/Preprocessor`

Public helpers are deliberately small building blocks:

| Family | Main public macros |
| --- | --- |
| Arguments | `PP_ARG_COUNT(...)` |
| Boolean | `PP_BOOL`, `PP_BOOL_NOT`, `PP_BOOL_IF`, `PP_BOOL_IF_ELSE`, `PP_BOOL_AND`, `PP_BOOL_OR`, `PP_BOOL_XOR` |
| Evaluation | `PP_EMPTY`, `PP_DEFER`, `PP_OBSTRUCT`, `PP_EVAL` |
| Iteration | `PP_FOREACH`, `PP_MAP`, `PP_REPEAT`, `PP_WHILE` |
| Sequences | `PP_SEQ_FIRST`, `PP_SEQ_REST`, `PP_SEQ_GET_1...10` |
| Tokens | `PP_TOKEN_EMPTY`, `PP_TOKEN_COMMA`, `PP_TOKEN_LPAREN`, `PP_TOKEN_RPAREN`, `PP_TOKEN_TILDE` |
| Concatenation | `PP_OP_EXPAND`, `PP_OP_CAT2...10` |
| Detection | `COMPILER_*`, `OS_*`, `PROCESSOR_*` |

Example:

```c
#define DECLARE_INT(name) int name;
PP_FOREACH(DECLARE_INT, first, second, third)
```

expands to three declarations.

Detection example:

```c
#if OS_WINDOWS
    /* Windows backend */
#elif OS_POSIX
    /* POSIX backend */
#endif
```
