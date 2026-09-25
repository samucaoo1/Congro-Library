# Bit

[Índice](../INDEX.md) · [Referência de assinaturas](../api/Bit.md)

Operações sobre inteiros sem sinal de 8, 16, 32 e 64 bits. Inclua
`Congro/Modules/Bit/Bit.h`. `BIT_FUNC(32, Set)` seleciona a operação para
`uint32_t`; o sufixo é a largura, não `uint32` nem `U32`.

## Operações

| Família | Chamadas | Comportamento |
|---|---|---|
| Bit individual | `Set`, `Clear`, `Flip`, `Check` | Posição zero é o bit menos significativo; as três primeiras modificam o valor apontado. |
| Máscaras | `MaskSet`, `MaskClear`, `MaskFlip` | Aplicam uma máscara da mesma largura ao valor apontado. |
| Consulta de máscaras | `MaskCheckAll`, `MaskCheckAny` | Testam todos ou pelo menos um dos bits selecionados. |
| Contagem | `Popcount`, `IsPowerOfTwo` | Contam bits ligados e verificam potência de dois. Zero não é potência de dois. |
| Índices | `IndexLSB`, `IndexMSB` | Localizam o bit ligado menos/mais significativo. Consulte o caso zero abaixo. |
| Rotação | `RotateLeft`, `RotateRight` | Rotacionam bits dentro da largura do tipo. |
| Campos | `Extract`, `Insert` | Recebem `high, low`, nessa ordem, com extremos inclusivos. |

## Contrato

Passe ponteiros válidos às operações de bit e máscara: elas não oferecem uma
política uniforme de validação de `NULL`. Índices fora da largura não modificam
um bit individual; `Check` retorna falso. Para campos inválidos, `Extract`
retorna zero e `Insert` não altera o destino. Isso não distingue um erro de
um campo cujo valor é realmente zero.

`IndexLSB(0)` e `IndexMSB(0)` retornam o maior valor do tipo sem sinal
(por exemplo, `UINT32_MAX` na família de 32 bits).

`Insert` descarta bits de `field_value` que não cabem no campo. `Extract` desloca
o campo para a posição zero. As operações não alocam memória e não retornam
`OPSTATUS`. Use [Math](Math.md) para aritmética inteira com detecção de overflow.

## Exemplo

<!-- example: Bit.c -->

[Bit.c](../examples/Bit.c)

```c
#include <assert.h>
#include "Congro/Modules/Bit/Bit.h"

int main(void) {
  uint32_t flags = 0;
  BIT_FUNC(32, Set)(&flags, 3);
  assert(BIT_FUNC(32, Check)(&flags, 3));
  BIT_FUNC(32, Insert)(&flags, 7, 4, 10);
  assert(BIT_FUNC(32, Extract)(&flags, 7, 4) == 10);
  assert(BIT_FUNC(32, Popcount)(flags) == 3);
  return 0;
}
```

## Extensão e verificação

`BIT_DECLARE(TYPE, SUFFIX, LITERAL)` gera a família; as quatro larguras suportadas
já são instanciadas pelo header. Prefira essas instâncias para preservar as
premissas de largura dos algoritmos. Os testes estão em
[Codespace/Tests/Bit](../../Codespace/Tests/Bit).
