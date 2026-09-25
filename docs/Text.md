# Text

Text provides Unicode code-point utilities, UTF-8/UTF-16 encoding and decoding,
terminal-oriented width measurement, and character/attribute grids.

**Root:** `Codespace/Congro/Modules/Text`

Core character aliases:

- `TText_Char16` — `uint16_t`
- `TText_Char32` — `uint32_t`

Result types in `Types.h` report encoding, decoding, measurement, and text
errors without hiding consumed/written lengths.

## Unicode code points

**Header:** `Unicode/Codepoint.h`

| Indirect | Direct | Purpose |
| --- | --- | --- |
| `TEXT_CODEPOINT_NS(IsValid)(cp)` | `Text_Codepoint_IsValid(cp)` | Checks Unicode code-point range validity. |
| `...IsScalar(cp)` | `Text_Codepoint_IsScalar(cp)` | Rejects surrogate code points. |
| `...IsASCII(cp)` | `Text_Codepoint_IsASCII(cp)` | ASCII test. |
| `...IsControl(cp)` | `Text_Codepoint_IsControl(cp)` | Control-character test. |
| `...IsWhitespace(cp)` | `Text_Codepoint_IsWhitespace(cp)` | Whitespace test. |

Example:

```c
TText_Char32 cp = 0x1F600u;
bool scalar = TEXT_CODEPOINT_NS(IsScalar)(cp);
bool same = Text_Codepoint_IsScalar(cp);
```

## UTF-8

**Header:** `Encoding/UTF8.h`

- `TEXT_UTF8_NS(EncodedLength)(cp)` → `Text_UTF8_EncodedLength(cp)`
- `Encode(cp,out,capacity)` → `Text_UTF8_Encode`
- `Decode(input,size)` → `Text_UTF8_Decode`
- `Validate(input,size)` → `Text_UTF8_Validate`
- `Count(input,size)` → `Text_UTF8_Count`

Example:

```c
unsigned char encoded[4];

TText_Encode_Result result =
    TEXT_UTF8_NS(Encode)(0x1F600u, encoded, sizeof(encoded));
```

Direct:

```c
TText_Encode_Result result =
    Text_UTF8_Encode(0x1F600u, encoded, sizeof(encoded));
```

`Count` walks UTF-8 input and returns a measurement result rather than
assuming bytes equal characters.

## UTF-16

**Header:** `Encoding/UTF16.h`

- `EncodedLength` → `Text_UTF16_EncodedLength`
- `Encode` → `Text_UTF16_Encode`
- `Decode` → `Text_UTF16_Decode`
- `Validate` → `Text_UTF16_Validate`

Example:

```c
TText_Char16 output[2];
TText_Encode_Result r =
    TEXT_UTF16_NS(Encode)(0x1F600u, output, 2);
```

Direct: `Text_UTF16_Encode(0x1F600u, output, 2)`.

## Display width

**Header:** `Unicode/Width.h`

- `TEXT_WIDTH_NS(Codepoint)(cp)` → `Text_Width_Codepoint(cp)`
- `TEXT_WIDTH_NS(UTF8)(bytes,size)` → `Text_Width_UTF8(bytes,size)`

This is display-cell width logic, useful for terminal/TUI layout; it is distinct
from byte length and Unicode code-point count.

## Full Text Grid

**Header:** `Grid/Grid.h`

A full grid stores a character and an attribute cell together.

Generated character suffixes:

- `char`
- `char16`
- `char32`

Example type:

```c
TEXT_GRID_TYPE(char)   /* TText_Grid_char */
```

Function family:

```c
TEXT_GRID_FUNC(char, Create)
```

directly:

```text
Text_Grid_char_Create
```

All three suffixes provide:

`IsEmpty`, `IsValid`, `Create`, `Destroy`, `Resize`, `Recreate`,
`Clone`, `Clear`, `ClearWith`, `ReadCell`, `WriteCell`, `Fill`,
`FillRegion`, `Read`, `Write`, `WriteRegion`, `Blit`, `BlitRegion`.

Example:

```c
TEXT_GRID_TYPE(char) grid = {0};
TDUAL_TYPE(uint16) size = {.col = 80, .row = 25};

TEXT_GRID_FUNC(char, Create)(&grid, size);

TEXT_GRID_ATTRIBUTE_TYPE(Cell) style =
    TEXT_GRID_ATTRIBUTE_FUNC(Default)();

TEXT_GRID_FUNC(char, WriteCell)(
    &grid,
    (TDUAL_TYPE(uint16)){.x = 5, .y = 3},
    'A',
    style);

TEXT_GRID_FUNC(char, Destroy)(&grid);
```

Direct function equivalents:

`Text_Grid_char_Create`, `Text_Grid_Attribute_Default`,
`Text_Grid_char_WriteCell`, and `Text_Grid_char_Destroy`.

Regions use `TQuad_uint16`-style rectangle values and positions use
`TDual_uint16`.

## Character-only Grid

**Header:** `Grid/Char.h`

Character grids omit attributes and are generated for the same three suffixes.

Naming:

```c
TEXT_GRID_CHAR_FUNC(char32, WriteCell)
Text_Grid_Char_char32_WriteCell
```

Operations:

`IsEmpty`, `IsValid`, `Create`, `Destroy`, `Resize`, `Recreate`,
`Clone`, `Clear`, `ReadCell`, `WriteCell`, `Fill`, `FillRegion`,
`Read`, `Write`, `WriteRegion`.

## Attribute Grid

**Header:** `Grid/Attribute.h`

Types include attribute cells, attribute grids, RGB colors, and underline
metadata.

Important helpers:

- `TEXT_GRID_ATTRIBUTE_FUNC(Default)()` → `Text_Grid_Attribute_Default()`
- `TEXT_GRID_COLOR_FUNC(WindowsPalette)()` → `Text_Grid_Color_WindowsPalette()`

Attribute-grid operations:

`IsEmpty`, `IsValid`, `Create`, `Destroy`, `Resize`, `Recreate`,
`Clone`, `Clear`, `ClearWith`, `Fill`, `ReadCell`, `WriteCell`,
`FillRegion`, `Read`, `Write`, `WriteRegion`.

The default Windows-style palette exposes the familiar 16 console colors while
the cell representation itself supports richer RGB foreground/background data.

## Grid ownership

Grid creation allocates owned backing storage. Destroy releases it. Clone creates
a distinct grid. Resize/Recreate can change backing storage, so pointers into old
grid storage should not be retained across those operations.
