# Text: referência de API

[Guia de uso](../modules/Text.md) · [Índice](../INDEX.md)

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
| [Encoding/UTF16.h](../../Codespace/Congro/Modules/Text/Encoding/UTF16.h) | 4 |
| [Encoding/UTF8.h](../../Codespace/Congro/Modules/Text/Encoding/UTF8.h) | 5 |
| [Grid/Attribute.h](../../Codespace/Congro/Modules/Text/Grid/Attribute.h) | 18 |
| [Grid/Char.h](../../Codespace/Congro/Modules/Text/Grid/Char.h) | 15 |
| [Grid/Grid.h](../../Codespace/Congro/Modules/Text/Grid/Grid.h) | 18 |
| [Text.h](../../Codespace/Congro/Modules/Text/Text.h) | 0 |
| [Text.space](../../Codespace/Congro/Modules/Text/Text.space) | 0 |
| [Types.h](../../Codespace/Congro/Modules/Text/Types.h) | 0 |
| [Unicode/Codepoint.h](../../Codespace/Congro/Modules/Text/Unicode/Codepoint.h) | 5 |
| [Unicode/Width.h](../../Codespace/Congro/Modules/Text/Unicode/Width.h) | 2 |

## Encoding/UTF16.h

[Declarações e implementação](../../Codespace/Congro/Modules/Text/Encoding/UTF16.h)

```c
size_t TEXT_UTF16_NS(EncodedLength)(TText_Char32 codepoint);

TText_Encode_Result TEXT_UTF16_NS(Encode)(TText_Char32 codepoint, TText_Char16 *output, size_t
    capacity);

TText_Decode_Result TEXT_UTF16_NS(Decode)(const TText_Char16 *input, size_t size);

bool TEXT_UTF16_NS(Validate)(const TText_Char16 *input, size_t size);

```

## Encoding/UTF8.h

[Declarações e implementação](../../Codespace/Congro/Modules/Text/Encoding/UTF8.h)

```c
size_t TEXT_UTF8_NS(EncodedLength)(TText_Char32 codepoint);

TText_Encode_Result TEXT_UTF8_NS(Encode)(TText_Char32 codepoint, unsigned char *output, size_t
    capacity);

TText_Decode_Result TEXT_UTF8_NS(Decode)(const unsigned char *input, size_t size);

bool TEXT_UTF8_NS(Validate)(const unsigned char *input, size_t size);

TText_Measure_Result TEXT_UTF8_NS(Count)( const unsigned char *input, size_t size);

```

## Grid/Attribute.h

[Declarações e implementação](../../Codespace/Congro/Modules/Text/Grid/Attribute.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TEXT_GRID_COLOR_RGB_MASK`
- `TEXT_GRID_COLOR_RGB(RED, GREEN, BLUE)`
- `TEXT_GRID_COLOR_RED(COLOR)`
- `TEXT_GRID_COLOR_GREEN(COLOR)`
- `TEXT_GRID_COLOR_BLUE(COLOR)`
- `TEXT_GRID_WINDOWS_COLOR_TABLE`

```c
TEXT_GRID_ATTRIBUTE_TYPE(Cell) TEXT_GRID_ATTRIBUTE_FUNC(Default)(void);

const TEXT_GRID_COLOR_TYPE(RGB) * TEXT_GRID_COLOR_FUNC(WindowsPalette)(void);

bool TEXT_GRID_ATTRIBUTE_FUNC(IsEmpty)( const TEXT_GRID_ATTRIBUTE_TYPE(Grid) *grid);

bool TEXT_GRID_ATTRIBUTE_FUNC(IsValid)( const TEXT_GRID_ATTRIBUTE_TYPE(Grid) *grid);

OPSTATUS TEXT_GRID_ATTRIBUTE_FUNC(Create)( TEXT_GRID_ATTRIBUTE_TYPE(Grid) *grid,
    TDUAL_TYPE(uint16) size);

OPSTATUS TEXT_GRID_ATTRIBUTE_FUNC(Destroy)( TEXT_GRID_ATTRIBUTE_TYPE(Grid) *grid);

OPSTATUS TEXT_GRID_ATTRIBUTE_FUNC(Resize)( TEXT_GRID_ATTRIBUTE_TYPE(Grid) *grid,
    TDUAL_TYPE(uint16) size);

OPSTATUS TEXT_GRID_ATTRIBUTE_FUNC(Recreate)( TEXT_GRID_ATTRIBUTE_TYPE(Grid) *grid,
    TDUAL_TYPE(uint16) size);

OPSTATUS TEXT_GRID_ATTRIBUTE_FUNC(Clone)( TEXT_GRID_ATTRIBUTE_TYPE(Grid) *destination, const
    TEXT_GRID_ATTRIBUTE_TYPE(Grid) *source);

OPSTATUS TEXT_GRID_ATTRIBUTE_FUNC(Clear)( TEXT_GRID_ATTRIBUTE_TYPE(Grid) *grid);

OPSTATUS TEXT_GRID_ATTRIBUTE_FUNC(ClearWith)( TEXT_GRID_ATTRIBUTE_TYPE(Grid) *grid,
    TEXT_GRID_ATTRIBUTE_TYPE(Cell) attribute);

OPSTATUS TEXT_GRID_ATTRIBUTE_FUNC(Fill)( TEXT_GRID_ATTRIBUTE_TYPE(Grid) *grid,
    TEXT_GRID_ATTRIBUTE_TYPE(Cell) attribute);

OPSTATUS TEXT_GRID_ATTRIBUTE_FUNC(ReadCell)( const TEXT_GRID_ATTRIBUTE_TYPE(Grid) *grid,
    TDUAL_TYPE(uint16) position, TEXT_GRID_ATTRIBUTE_TYPE(Cell) *attribute);

OPSTATUS TEXT_GRID_ATTRIBUTE_FUNC(WriteCell)( TEXT_GRID_ATTRIBUTE_TYPE(Grid) *grid,
    TDUAL_TYPE(uint16) position, TEXT_GRID_ATTRIBUTE_TYPE(Cell) attribute);

OPSTATUS TEXT_GRID_ATTRIBUTE_FUNC(FillRegion)( TEXT_GRID_ATTRIBUTE_TYPE(Grid) *grid,
    TQUAD_TYPE(uint16) region, TEXT_GRID_ATTRIBUTE_TYPE(Cell) attribute);

OPSTATUS TEXT_GRID_ATTRIBUTE_FUNC(Read)( const TEXT_GRID_ATTRIBUTE_TYPE(Grid) *source,
    TQUAD_TYPE(uint16) region, TEXT_GRID_ATTRIBUTE_TYPE(Grid) *destination);

OPSTATUS TEXT_GRID_ATTRIBUTE_FUNC(Write)( TEXT_GRID_ATTRIBUTE_TYPE(Grid) *destination,
    TDUAL_TYPE(uint16) destinationPosition, const TEXT_GRID_ATTRIBUTE_TYPE(Grid) *source);

OPSTATUS TEXT_GRID_ATTRIBUTE_FUNC(WriteRegion)( TEXT_GRID_ATTRIBUTE_TYPE(Grid) *destination,
    TDUAL_TYPE(uint16) destinationPosition, const TEXT_GRID_ATTRIBUTE_TYPE(Grid) *source,
    TQUAD_TYPE(uint16) sourceRegion);

```

## Grid/Char.h

[Declarações e implementação](../../Codespace/Congro/Modules/Text/Grid/Char.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TEXT_GRID_CHAR_DECLARE(TYPE, SUFFIX)`

```c
bool TEXT_GRID_CHAR_FUNC(SUFFIX, IsEmpty)( const TEXT_GRID_CHAR_TYPE(SUFFIX) *grid);

bool TEXT_GRID_CHAR_FUNC(SUFFIX, IsValid)( const TEXT_GRID_CHAR_TYPE(SUFFIX) *grid);

OPSTATUS TEXT_GRID_CHAR_FUNC(SUFFIX, Create)( TEXT_GRID_CHAR_TYPE(SUFFIX) *grid,
    TDUAL_TYPE(uint16) size);

OPSTATUS TEXT_GRID_CHAR_FUNC(SUFFIX, Destroy)( TEXT_GRID_CHAR_TYPE(SUFFIX) *grid);

OPSTATUS TEXT_GRID_CHAR_FUNC(SUFFIX, Resize)( TEXT_GRID_CHAR_TYPE(SUFFIX) *grid,
    TDUAL_TYPE(uint16) size);

OPSTATUS TEXT_GRID_CHAR_FUNC(SUFFIX, Recreate)( TEXT_GRID_CHAR_TYPE(SUFFIX) *grid,
    TDUAL_TYPE(uint16) size);

OPSTATUS TEXT_GRID_CHAR_FUNC(SUFFIX, Clone)( TEXT_GRID_CHAR_TYPE(SUFFIX) *destination, const
    TEXT_GRID_CHAR_TYPE(SUFFIX) *source);

OPSTATUS TEXT_GRID_CHAR_FUNC(SUFFIX, Clear)( TEXT_GRID_CHAR_TYPE(SUFFIX) *grid);

OPSTATUS TEXT_GRID_CHAR_FUNC(SUFFIX, ReadCell)( const TEXT_GRID_CHAR_TYPE(SUFFIX) *grid,
    TDUAL_TYPE(uint16) position, TYPE *character);

OPSTATUS TEXT_GRID_CHAR_FUNC(SUFFIX, WriteCell)( TEXT_GRID_CHAR_TYPE(SUFFIX) *grid,
    TDUAL_TYPE(uint16) position, TYPE character);

OPSTATUS TEXT_GRID_CHAR_FUNC(SUFFIX, Fill)( TEXT_GRID_CHAR_TYPE(SUFFIX) *grid, TYPE character);

OPSTATUS TEXT_GRID_CHAR_FUNC(SUFFIX, FillRegion)( TEXT_GRID_CHAR_TYPE(SUFFIX) *grid,
    TQUAD_TYPE(uint16) region, TYPE character);

OPSTATUS TEXT_GRID_CHAR_FUNC(SUFFIX, Read)( const TEXT_GRID_CHAR_TYPE(SUFFIX) *source,
    TQUAD_TYPE(uint16) region, TEXT_GRID_CHAR_TYPE(SUFFIX) *destination);

OPSTATUS TEXT_GRID_CHAR_FUNC(SUFFIX, Write)( TEXT_GRID_CHAR_TYPE(SUFFIX) *destination,
    TDUAL_TYPE(uint16) destinationPosition, const TEXT_GRID_CHAR_TYPE(SUFFIX) *source);

OPSTATUS TEXT_GRID_CHAR_FUNC(SUFFIX, WriteRegion)( TEXT_GRID_CHAR_TYPE(SUFFIX) *destination,
    TDUAL_TYPE(uint16) destinationPosition, const TEXT_GRID_CHAR_TYPE(SUFFIX) *source,
    TQUAD_TYPE(uint16) sourceRegion);

```

## Grid/Grid.h

[Declarações e implementação](../../Codespace/Congro/Modules/Text/Grid/Grid.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TEXT_GRID_DECLARE(TYPE, SUFFIX)`

```c
bool TEXT_GRID_FUNC(SUFFIX, IsEmpty)( const TEXT_GRID_TYPE(SUFFIX) *grid);

bool TEXT_GRID_FUNC(SUFFIX, IsValid)( const TEXT_GRID_TYPE(SUFFIX) *grid);

OPSTATUS TEXT_GRID_FUNC(SUFFIX, Create)( TEXT_GRID_TYPE(SUFFIX) *grid, TDUAL_TYPE(uint16) size);

OPSTATUS TEXT_GRID_FUNC(SUFFIX, Destroy)( TEXT_GRID_TYPE(SUFFIX) *grid);

OPSTATUS TEXT_GRID_FUNC(SUFFIX, Resize)( TEXT_GRID_TYPE(SUFFIX) *grid, TDUAL_TYPE(uint16) size);

OPSTATUS TEXT_GRID_FUNC(SUFFIX, Recreate)( TEXT_GRID_TYPE(SUFFIX) *grid, TDUAL_TYPE(uint16)
    size);

OPSTATUS TEXT_GRID_FUNC(SUFFIX, Clone)( TEXT_GRID_TYPE(SUFFIX) *destination, const
    TEXT_GRID_TYPE(SUFFIX) *source);

OPSTATUS TEXT_GRID_FUNC(SUFFIX, Clear)( TEXT_GRID_TYPE(SUFFIX) *grid);

OPSTATUS TEXT_GRID_FUNC(SUFFIX, ClearWith)( TEXT_GRID_TYPE(SUFFIX) *grid,
    TEXT_GRID_ATTRIBUTE_TYPE(Cell) attribute);

OPSTATUS TEXT_GRID_FUNC(SUFFIX, ReadCell)( const TEXT_GRID_TYPE(SUFFIX) *grid,
    TDUAL_TYPE(uint16) position, TYPE *character, TEXT_GRID_ATTRIBUTE_TYPE(Cell) *attribute);

OPSTATUS TEXT_GRID_FUNC(SUFFIX, WriteCell)( TEXT_GRID_TYPE(SUFFIX) *grid, TDUAL_TYPE(uint16)
    position, TYPE character, TEXT_GRID_ATTRIBUTE_TYPE(Cell) attribute);

OPSTATUS TEXT_GRID_FUNC(SUFFIX, Fill)( TEXT_GRID_TYPE(SUFFIX) *grid, TYPE character,
    TEXT_GRID_ATTRIBUTE_TYPE(Cell) attribute);

OPSTATUS TEXT_GRID_FUNC(SUFFIX, FillRegion)( TEXT_GRID_TYPE(SUFFIX) *grid, TQUAD_TYPE(uint16)
    region, TYPE character, TEXT_GRID_ATTRIBUTE_TYPE(Cell) attribute);

OPSTATUS TEXT_GRID_FUNC(SUFFIX, Read)( const TEXT_GRID_TYPE(SUFFIX) *source, TQUAD_TYPE(uint16)
    region, TEXT_GRID_TYPE(SUFFIX) *destination);

OPSTATUS TEXT_GRID_FUNC(SUFFIX, Write)( TEXT_GRID_TYPE(SUFFIX) *destination, TDUAL_TYPE(uint16)
    destination_position, const TEXT_GRID_TYPE(SUFFIX) *source);

OPSTATUS TEXT_GRID_FUNC(SUFFIX, WriteRegion)( TEXT_GRID_TYPE(SUFFIX) *destination,
    TDUAL_TYPE(uint16) destination_position, const TEXT_GRID_TYPE(SUFFIX) *source,
    TQUAD_TYPE(uint16) source_region);

OPSTATUS TEXT_GRID_FUNC(SUFFIX, Blit)( TEXT_GRID_TYPE(SUFFIX) *destination, TDUAL_TYPE(uint16)
    destination_position, const TEXT_GRID_TYPE(SUFFIX) *source);

OPSTATUS TEXT_GRID_FUNC(SUFFIX, BlitRegion)( TEXT_GRID_TYPE(SUFFIX) *destination,
    TDUAL_TYPE(uint16) destination_position, const TEXT_GRID_TYPE(SUFFIX) *source,
    TQUAD_TYPE(uint16) source_region);

```

## Text.space

[Declarações e implementação](../../Codespace/Congro/Modules/Text/Text.space)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TEXT_MOD(NAME)`
- `TEXT_NS(MODULE, NAME)`
- `TEXT_TYPE(NAME)`
- `TEXT_CODEPOINT_NS(NAME)`
- `TEXT_UTF8_NS(NAME)`
- `TEXT_UTF16_NS(NAME)`
- `TEXT_WIDTH_NS(NAME)`
- `TEXT_GRID_NS(NAME)`
- `TEXT_GRID_TYPE(SUFFIX)`
- `TEXT_GRID_FUNC(SUFFIX, FUNCTION)`
- `TEXT_GRID_CHAR_TYPE(SUFFIX)`
- `TEXT_GRID_CHAR_FUNC(SUFFIX, FUNCTION)`
- `TEXT_GRID_ATTRIBUTE_TYPE(NAME)`
- `TEXT_GRID_ATTRIBUTE_NS(NAME)`
- `TEXT_GRID_ATTRIBUTE_FUNC(FUNCTION)`
- `TEXT_GRID_UNDERLINE_TYPE(NAME)`
- `TEXT_GRID_UNDERLINE_NS(NAME)`
- `TEXT_GRID_COLOR_TYPE(NAME)`
- `TEXT_GRID_COLOR_NS(NAME)`
- `TEXT_GRID_COLOR_FUNC(FUNCTION)`
- `TEXT_GRID_CHARACTER_TABLE`


## Unicode/Codepoint.h

[Declarações e implementação](../../Codespace/Congro/Modules/Text/Unicode/Codepoint.h)

```c
bool TEXT_CODEPOINT_NS(IsValid)(TText_Char32 codepoint);

bool TEXT_CODEPOINT_NS(IsScalar)(TText_Char32 codepoint);

bool TEXT_CODEPOINT_NS(IsASCII)(TText_Char32 codepoint);

bool TEXT_CODEPOINT_NS(IsControl)(TText_Char32 codepoint);

bool TEXT_CODEPOINT_NS(IsWhitespace)(TText_Char32 codepoint);

```

## Unicode/Width.h

[Declarações e implementação](../../Codespace/Congro/Modules/Text/Unicode/Width.h)

```c
int TEXT_WIDTH_NS(Codepoint)(TText_Char32 codepoint);

TText_Measure_Result TEXT_WIDTH_NS(UTF8)( const unsigned char *input, size_t size);

```

## Unicode/Impl/Width.impl

[Declarações e implementação](../../Codespace/Congro/Modules/Text/Unicode/Impl/Width.impl)

```c
bool TEXT_WIDTH_NS(InIntervals)( uint_least32_t value, const InternalType_TextWidthInterval
    *intervals, size_t count);

```
