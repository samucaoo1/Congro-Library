# Bit

Bit manipulation utilities for fixed-width unsigned integers.

**Header:** `Codespace/Congro/Modules/Bit/Bit.h`

Supported widths: `8`, `16`, `32`, and `64`, corresponding to
`uint8_t`, `uint16_t`, `uint32_t`, and `uint64_t`.

For every function below, replace `32` with another supported width when needed.

## Quick example

Indirect form:

```c
#include "Congro/Modules/Bit/Bit.h"

uint32_t flags = 0;

BIT_FUNC(32, Set)(&flags, 5);
bool enabled = BIT_FUNC(32, Check)(&flags, 5);
uint64_t bits = BIT_FUNC(32, Popcount)(flags);
```

Direct form:

```c
#include "Congro/Modules/Bit/Bit.h"

uint32_t flags = 0;

Bit_32_Set(&flags, 5);
bool enabled = Bit_32_Check(&flags, 5);
uint64_t bits = Bit_32_Popcount(flags);
```

## Single-bit operations

| Indirect | Direct | Return | Description |
| --- | --- | --- | --- |
| `BIT_FUNC(32, Set)(&value, bit)` | `Bit_32_Set(&value, bit)` | `void` | Sets one bit. Out-of-range bit indices are ignored. |
| `BIT_FUNC(32, Clear)(&value, bit)` | `Bit_32_Clear(&value, bit)` | `void` | Clears one bit. Out-of-range indices are ignored. |
| `BIT_FUNC(32, Flip)(&value, bit)` | `Bit_32_Flip(&value, bit)` | `void` | Toggles one bit. Out-of-range indices are ignored. |
| `BIT_FUNC(32, Check)(&value, bit)` | `Bit_32_Check(&value, bit)` | `bool` | Returns whether the bit is set; invalid indices return `false`. |

Example:

```c
uint32_t permissions = 0;

BIT_FUNC(32, Set)(&permissions, 2);
BIT_FUNC(32, Flip)(&permissions, 4);

if (BIT_FUNC(32, Check)(&permissions, 2)) {
    /* bit 2 is set */
}

BIT_FUNC(32, Clear)(&permissions, 2);
```

Direct symbols: `Bit_32_Set`, `Bit_32_Flip`, `Bit_32_Check`,
`Bit_32_Clear`.

## Mask operations

| Indirect | Direct | Return | Description |
| --- | --- | --- | --- |
| `BIT_FUNC(32, MaskSet)(&value, mask)` | `Bit_32_MaskSet(&value, mask)` | `void` | Sets all bits selected by `mask`. |
| `BIT_FUNC(32, MaskClear)(&value, mask)` | `Bit_32_MaskClear(&value, mask)` | `void` | Clears all bits selected by `mask`. |
| `BIT_FUNC(32, MaskFlip)(&value, mask)` | `Bit_32_MaskFlip(&value, mask)` | `void` | Toggles all selected bits. |
| `BIT_FUNC(32, MaskCheckAll)(&value, mask)` | `Bit_32_MaskCheckAll(&value, mask)` | `bool` | True only if every bit in the mask is present. |
| `BIT_FUNC(32, MaskCheckAny)(&value, mask)` | `Bit_32_MaskCheckAny(&value, mask)` | `bool` | True if at least one masked bit is present. |

Example:

```c
uint32_t flags = 0x10u;
uint32_t required = 0x30u;

BIT_FUNC(32, MaskSet)(&flags, 0x20u);

bool all = BIT_FUNC(32, MaskCheckAll)(&flags, required);
bool any = BIT_FUNC(32, MaskCheckAny)(&flags, 0x80u);
```

Direct form:

```c
Bit_32_MaskSet(&flags, 0x20u);

bool all = Bit_32_MaskCheckAll(&flags, required);
bool any = Bit_32_MaskCheckAny(&flags, 0x80u);
```

## Bit counting and position

| Indirect | Direct | Return | Description |
| --- | --- | --- | --- |
| `BIT_FUNC(32, Popcount)(value)` | `Bit_32_Popcount(value)` | `uint64_t` | Counts set bits. |
| `BIT_FUNC(32, IsPowerOfTwo)(value)` | `Bit_32_IsPowerOfTwo(value)` | `bool` | True for non-zero powers of two. |
| `BIT_FUNC(32, IndexLSB)(value)` | `Bit_32_IndexLSB(value)` | `uint32_t` | Index of the least-significant set bit. For zero, returns all bits set in the width type. |
| `BIT_FUNC(32, IndexMSB)(value)` | `Bit_32_IndexMSB(value)` | `uint32_t` | Index of the most-significant set bit. For zero, returns all bits set in the width type. |

Example:

```c
uint32_t value = 0x48u; /* 0100 1000 */

uint64_t count = BIT_FUNC(32, Popcount)(value); /* 2 */
uint32_t lsb = BIT_FUNC(32, IndexLSB)(value);   /* 3 */
uint32_t msb = BIT_FUNC(32, IndexMSB)(value);   /* 6 */
```

Direct form:

```c
uint64_t count = Bit_32_Popcount(value);
uint32_t lsb = Bit_32_IndexLSB(value);
uint32_t msb = Bit_32_IndexMSB(value);
```

## Rotation

| Indirect | Direct | Description |
| --- | --- | --- |
| `BIT_FUNC(32, RotateLeft)(value, shift)` | `Bit_32_RotateLeft(value, shift)` | Circular left rotation. Shift is reduced modulo the bit width. |
| `BIT_FUNC(32, RotateRight)(value, shift)` | `Bit_32_RotateRight(value, shift)` | Circular right rotation. Shift is reduced modulo the bit width. |

```c
uint32_t x = 0x80000001u;
uint32_t left = BIT_FUNC(32, RotateLeft)(x, 1);
uint32_t right = BIT_FUNC(32, RotateRight)(x, 1);
```

Equivalent direct calls:

```c
uint32_t left = Bit_32_RotateLeft(x, 1);
uint32_t right = Bit_32_RotateRight(x, 1);
```

## Bit fields

`high` and `low` are inclusive indices.

| Indirect | Direct | Description |
| --- | --- | --- |
| `BIT_FUNC(32, Extract)(&value, high, low)` | `Bit_32_Extract(&value, high, low)` | Extracts a field and right-aligns it. Invalid ranges return zero. |
| `BIT_FUNC(32, Insert)(&value, high, low, field)` | `Bit_32_Insert(&value, high, low, field)` | Replaces the selected field. Invalid ranges are ignored. Excess source bits are masked away. |

Example:

```c
uint32_t word = 0xABCD1234u;

uint32_t byte = BIT_FUNC(32, Extract)(&word, 15, 8);

BIT_FUNC(32, Insert)(&word, 15, 8, 0x5Au);
```

Direct form:

```c
uint32_t byte = Bit_32_Extract(&word, 15, 8);
Bit_32_Insert(&word, 15, 8, 0x5Au);
```

## Width reference

| Width suffix | C type | Example direct symbol |
| ---: | --- | --- |
| `8` | `uint8_t` | `Bit_8_Popcount` |
| `16` | `uint16_t` | `Bit_16_Popcount` |
| `32` | `uint32_t` | `Bit_32_Popcount` |
| `64` | `uint64_t` | `Bit_64_Popcount` |
