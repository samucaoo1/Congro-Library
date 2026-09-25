# Struct

[Índice](../INDEX.md) · [Referência de assinaturas](../api/Struct.md)

Estruturas pequenas de valores homogêneos, com nomes alternativos para as mesmas
posições. Inclua os headers necessários de `Congro/Modules/Struct`.

## Famílias

| Header | Macro do tipo | Valores | Uso típico |
|---|---|---|---|
| `TPair.h` | `TPAIR_TYPE(SUFFIX)` | 2 | Par genérico, `first/second`, `x/y`. |
| `TDual.h` | `TDUAL_TYPE(SUFFIX)` | 2 | Coordenadas, `col/row`, `real/imaginary`, `begin/end`. |
| `TTriple.h` | `TTRIPLE_TYPE(SUFFIX)` | 3 | Trio de componentes. |
| `TQuad.h` | `TQUAD_TYPE(SUFFIX)` | 4 | Quatro componentes ou limites `left/right/top/bottom`. |
| `TPenta.h` | `TPENTA_TYPE(SUFFIX)` | 5 | Cinco componentes. |

Os aliases são membros de unions: escrever `x` altera a mesma posição observada
por `col` em TDual. Não são campos independentes. O significado geométrico é da
API consumidora: em Text, um TQuad representa região inclusiva; Struct sozinho
não impõe essa semântica.

## Tipos e conversões

Os headers instanciam larguras inteiras assinadas e sem sinal, `float`, `double`
e `longdouble`. Consulte cada header antes de assumir um sufixo adicional;
TDual também fornece `size` e variantes complexas fora do caminho MSVC.

`TDUAL_DECLARE(TYPE, SUFFIX)` e os equivalentes de cada família geram o tipo e
conversões; `*_TYPE_DECLARE` gera somente o tipo. Use um sufixo exclusivo para
uma nova instância. `CAST_TYPE_TO_STRUCT(SUFFIX, TDual)` constrói a partir dos
componentes; `CAST_STRUCT_TO_TYPE(TDual, SUFFIX)` escreve componentes em
ponteiros de saída. Forneça saídas válidas. Consulte a referência para a aridade
de cada família.

Não há alocação, destrutor ou verificação de faixa dos componentes. Copiar por
valor é apropriado para componentes escalares; componentes ponteiro preservam
apenas o endereço. Não serialize a representação da union/struct como formato
portável: layout e padding dependem da implementação C.

## Exemplo

<!-- example: Struct.c -->

[Struct.c](../examples/Struct.c)

```c
#include <assert.h>
#include "Congro/Modules/Struct/TDual.h"
#include "Congro/Modules/Struct/TQuad.h"

int main(void) {
  TDUAL_TYPE(uint16) position = {.x = 5, .y = 3};
  TQUAD_TYPE(uint16) cell = {
      .left = position.x, .right = position.x,
      .top = position.y, .bottom = position.y};
  assert(position.col == 5 && position.row == 3);
  assert(cell.right - cell.left + 1 == 1);
  return 0;
}
```

[Testes de tipos, aliases e conversões](../../Codespace/Tests/Struct).
