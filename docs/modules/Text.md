# Text

[Índice](../INDEX.md) · [Referência de assinaturas](../api/Text.md)

Inclua `Congro/Modules/Text/Text.h` ou os headers específicos. O módulo contém
codificação UTF-8/UTF-16, consultas de codepoints/largura e grids de caracteres
e atributos. Ainda não é um renderizador de terminal ou um toolkit de widgets.

## Codificação e Unicode

| Pacote | Operações | Unidades |
|---|---|---|
| `Encoding/UTF8.h` | `EncodedLength`, `Encode`, `Decode`, `Validate`, `Count` | Bytes (`unsigned char`). |
| `Encoding/UTF16.h` | `EncodedLength`, `Encode`, `Decode`, `Validate` | Unidades de 16 bits (`TText_Char16`), não bytes. |
| `Unicode/Codepoint.h` | `IsValid`, `IsScalar`, `IsASCII`, `IsControl`, `IsWhitespace` | Escalares `TText_Char32`. |
| `Unicode/Width.h` | `Codepoint`, `UTF8` | Estimativa de colunas para exibição. |

`Decode` processa o próximo codepoint e informa quantas unidades consumiu.
`Encode` informa quantas escreveu; não presuma que acrescente NUL. Recebem tamanho
explícito, sem necessidade de string terminada. Diferencie sequência inválida,
sequência incompleta e buffer insuficiente.

Esta parte da API retorna `TText_Decode_Result`, `TText_Encode_Result` e
`TText_Measure_Result`, com campo `error` de `TText_Error`. É uma exceção ao
padrão `OPSTATUS` usado nos grids; o guia descreve a API existente. Confira
`TEXT_ERROR_NONE` antes de usar as saídas. Contar codepoints ou somar larguras
não equivale a segmentar grafemas, aplicar shaping ou reproduzir todo terminal.

## Grids

| Camada | Seleção | Conteúdo |
|---|---|---|
| Char | `TEXT_GRID_CHAR_TYPE(SUFFIX)` | Buffer proprietário de `char`, `char16` ou `char32`. |
| Attribute | `TEXT_GRID_ATTRIBUTE_TYPE(Grid)` | Buffer proprietário de atributos de célula. |
| Grid | `TEXT_GRID_TYPE(SUFFIX)` | Grids de caracteres e atributos com dimensões correspondentes. |

Use `TEXT_GRID_FUNC(SUFFIX, Operation)` para a grade composta. Operações:
`IsEmpty`, `IsValid`, `Create`, `Destroy`, `Resize`, `Recreate`, `Clone`, `Clear`,
`ClearWith`, `ReadCell`, `WriteCell`, `Fill`, `FillRegion`, `Read`, `Write`,
`WriteRegion`, `Blit` e `BlitRegion`. As camadas Char e Attribute têm famílias
análogas descritas na referência.

Inicialize o objeto com `{0}`. `Create` estabelece dimensões, `Destroy` libera
buffers, `Clone` copia conteúdo para outro objeto válido. Não duplique ownership
por atribuição de structs; use Clone. Os buffers são internos: não os libere
separadamente. Os grids retornam `OPSTATUS`; cheque falhas de memória e faixa.

## Coordenadas, regiões e atributos

Dimensões e posições usam `TDUAL_TYPE(uint16)`, com `col/row` ou `x/y`.
Posições começam em zero. Regiões usam `TQUAD_TYPE(uint16)` com
`left/right/top/bottom`, **todos inclusivos**: `{.left=5, .right=5, .top=3,
.bottom=3}` é uma célula. A largura é `right-left+1`. Dimensões são contagens;
um grid com 10 colunas tem última coluna 9.

Atributos têm RGB de 24 bits por cor, flags e estilo de sublinhado.
`TEXT_GRID_COLOR_RGB` monta a cor; as macros RED/GREEN/BLUE extraem canais.
`WindowsPalette` fornece as 16 cores e há constantes `WINDOWS_*`.
Use `TEXT_GRID_ATTRIBUTE_FUNC(Default)` como ponto de partida.

Flags incluem BOLD, FAINT, ITALIC, BLINK, INVERSE, HIDDEN, STRIKE, OVERLINE,
TRANSPARENT_BACKGROUND, CODE_UNIT_CONTINUATION e cores default. Escolha BOLD
ou FAINT, evitando combiná-los. HIDDEN expressa ocultação do glifo;
TRANSPARENT_BACKGROUND expressa transparência do fundo. `Write` copia conteúdo;
`Blit` aplica a composição implementada pelos flags. O armazenamento por si só
não produz efeitos visuais: um consumidor precisa interpretar os atributos.

Uma célula char/char16 guarda uma unidade de código, não necessariamente um
caractere Unicode inteiro. char32 guarda um codepoint, que ainda pode ser parte
de um grafema. Limpar caracteres grava NUL; não transforma a grade em strings
C independentes por linha.

## Exemplos

<!-- example: Text.c -->

[Text.c](../examples/Text.c)

```c
#include <assert.h>
#include "Congro/Modules/Text/Encoding/UTF8.h"

int main(void) {
  unsigned char bytes[4];
  TText_Encode_Result encoded = TEXT_UTF8_NS(Encode)(0x00E1, bytes, sizeof(bytes));
  if (encoded.error != TEXT_ERROR_NONE)
    return 1;
  TText_Decode_Result decoded = TEXT_UTF8_NS(Decode)(bytes, encoded.units);
  if (decoded.error != TEXT_ERROR_NONE)
    return 2;
  assert(decoded.codepoint == 0x00E1 && decoded.units == 2);
  return 0;
}
```

<!-- example: TextGrid.c -->

[TextGrid.c](../examples/TextGrid.c)

```c
#include <assert.h>
#include "Congro/Modules/Text/Grid/Grid.h"

int main(void) {
  TEXT_GRID_TYPE(char32) grid = {0};
  TDUAL_TYPE(uint16) size = {.col = 10, .row = 5};
  TDUAL_TYPE(uint16) position = {.x = 5, .y = 3};
  TEXT_GRID_ATTRIBUTE_TYPE(Cell) attribute = TEXT_GRID_ATTRIBUTE_FUNC(Default)();
  TText_Char32 character = 0;
  OPSTATUS status = TEXT_GRID_FUNC(char32, Create)(&grid, size);
  if (status != STATUS_CONST(SUCCESS))
    return 1;
  status = TEXT_GRID_FUNC(char32, WriteCell)(&grid, position, 'A', attribute);
  if (status == STATUS_CONST(SUCCESS))
    status = TEXT_GRID_FUNC(char32, ReadCell)(&grid, position, &character, &attribute);
  if (status == STATUS_CONST(SUCCESS))
    assert(character == 'A');
  OPSTATUS destroyed = TEXT_GRID_FUNC(char32, Destroy)(&grid);
  return status == STATUS_CONST(SUCCESS) && destroyed == STATUS_CONST(SUCCESS) ? 0 : 2;
}
```

[Testes de Unicode, encoding e grids](../../Codespace/Tests/Text).
