# Type

Type supplies fundamental aliases and fixed-width extended value families:
`TBlock`, `TBigint`, and `TDecimal`.

**Root:** `Codespace/Congro/Modules/Type`

## Fundamental aliases

**Header:** `Fundamental.h`

There are two independent configuration axes.

Name size:

- `TYPE_ALIAS_COMPLETE` — default: `Int32`, `UInt64`, `Float32`, etc.
- `TYPE_ALIAS_SMALL` — `I32`, `U64`, `F32`, etc.

Namespace safety:

- `TYPE_ALIAS_UNSAFE` — default: aliases are unprefixed.
- `TYPE_ALIAS_SAFE` — aliases are placed under the Type namespace.

The paired settings are mutually exclusive within each axis.

Available aliases cover signed/unsigned 8/16/32/64-bit integers, float/double/
long double, and 8/16/32-bit character storage.

## Extended-type naming

For a 256-bit bigint:

```c
TBIGINT_TYPE(256)
```

expands to:

```text
Type_TBigint256
```

and:

```c
TBIGINT_FUNC(256, Add)
```

expands to:

```text
Type_TBigint256_Add
```

The same rule applies to `TBlock` and `TDecimal`.

Available widths: `128`, `256`, `512`, `1024`.

## TBlock

**Header:** `TBlock.h`

`TBlock` is a fixed-width raw bit block. It focuses on bitwise operations
rather than arithmetic interpretation.

Declaration:

```c
TBlock(256, block);
```

Equivalent type initialization:

```c
Type_TBlock256 block = {0};
```

Operations:

| Indirect | Direct |
| --- | --- |
| `TBLOCK_FUNC(256, Clear)(&x)` | `Type_TBlock256_Clear(&x)` |
| `...And(&x,&y)` | `Type_TBlock256_And(...)` |
| `...Or(&x,&y)` | `Type_TBlock256_Or(...)` |
| `...Xor(&x,&y)` | `Type_TBlock256_Xor(...)` |
| `...Not(&x)` | `Type_TBlock256_Not(&x)` |
| `...ShiftLeft(&x,n)` | `Type_TBlock256_ShiftLeft(...)` |
| `...ShiftRight(&x,n)` | `Type_TBlock256_ShiftRight(...)` |
| `...RotateLeft(&x,n)` | `Type_TBlock256_RotateLeft(...)` |
| `...RotateRight(&x,n)` | `Type_TBlock256_RotateRight(...)` |
| `...BitSet(&x,bit)` | `Type_TBlock256_BitSet(...)` |
| `...BitClear(&x,bit)` | `Type_TBlock256_BitClear(...)` |
| `...BitCheck(&x,bit,&set)` | `Type_TBlock256_BitCheck(...)` |

Most operations return `OPSTATUS` so invalid bit indices/arguments can be
reported instead of silently discarded.

## TBigint

**Header:** `TBigint.h`

Fixed-width arbitrary-large integer storage and operations.

Declaration:

```c
TBigint(256, a);
TBigint(256, b);
```

### Lifecycle/value state

- `TBIGINT_FUNC(256, Init)` → `Type_TBigint256_Init`
- `Clear` → `Type_TBigint256_Clear`
- `IsZero` → `Type_TBigint256_IsZero`

### Arithmetic

- `Add`, `Sub`, `Mul`
- `DivMod(dividend,divisor,quotient,remainder)`
- `Div`, `Mod`
- `Increment`, `Decrement`

Direct family prefix: `Type_TBigint256_`.

Example:

```c
TBIGINT_FUNC(256, Add)(&a, &b);
/* direct */
Type_TBigint256_Add(&a, &b);
```

The destination-mutating binary operations use the first bigint as the target.

### Bitwise

`And`, `Or`, `Xor`, `Not`, `ShiftLeft`, `ShiftRight`,
`RotateLeft`, `RotateRight`, `BitSet`, `BitClear`, `BitCheck`.

### Comparison

- `Compare(&a,&b,&result)` writes `TComparisonResult`
- `Equal`, `NotEqual`
- `LessThan`, `GreaterThan`
- `LessOrEqual`, `GreaterOrEqual`

### Formatting

```c
char text[128];
TBIGINT_FUNC(256, ToCString)(&a, text, sizeof(text));
TBIGINT_FUNC(256, ToCStringBase)(&a, text, sizeof(text), 16);
```

Direct:

```c
Type_TBigint256_ToCString(&a, text, sizeof(text));
Type_TBigint256_ToCStringBase(&a, text, sizeof(text), 16);
```

## TDecimal

**Header:** `TDecimal.h`

TDecimal exposes the same broad operational surface as TBigint for fixed-width
decimal-oriented values.

Widths: 128, 256, 512, 1024.

Declaration:

```c
TDecimal(128, value);
```

Direct type: `Type_TDecimal128`.

Functions:

`Init`, `Clear`, `Add`, `Sub`, `Mul`, `DivMod`, `Div`, `Mod`,
`Increment`, `Decrement`, `And`, `Or`, `Xor`, `Not`, `ShiftLeft`,
`ShiftRight`, `RotateLeft`, `RotateRight`, `BitSet`, `BitClear`,
`BitCheck`, `Compare`, `Equal`, `NotEqual`, `LessThan`,
`GreaterThan`, `LessOrEqual`, `GreaterOrEqual`, `ToCStringBase`,
`ToCString`, `IsZero`.

Example pair:

```c
TDECIMAL_FUNC(128, Mul)(&value, &factor);
Type_TDecimal128_Mul(&value, &factor);
```

## Optional vtables

`TYPE_ENABLE_VTABLE` defaults to `1`. Setting it to `0` removes optional
pseudo-method tables while preserving direct functions.

```c
#define TYPE_ENABLE_VTABLE 0
#include "Congro/Modules/Type/TBigint.h"
```

For portable/library-facing code, the generated direct function names are the
most explicit surface and do not depend on pseudo-method support.
