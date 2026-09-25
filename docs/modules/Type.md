# Type

[Índice](../INDEX.md) · [Referência de assinaturas](../api/Type.md)

Inclua `Fundamental.h`, `TBlock.h`, `TBigint.h` ou `TDecimal.h` de
`Congro/Modules/Type`. As três famílias estendidas têm armazenamento fixo de
128, 256, 512 ou 1024 bits; não são inteiros de precisão ilimitada.

## Famílias e operações

| Família | API | Representação |
|---|---|---|
| Fundamental | Aliases I8/Int8, U8/UInt8, F32/Float32 etc. | Tipos C fundamentais; `LongDouble` segue a plataforma. |
| TBlock | `Clear`, `And`, `Or`, `Xor`, `Not`, `ShiftLeft/Right`, `RotateLeft/Right`, `BitSet/Clear/Check` | Bloco de bits com views `limb` e `byte`. |
| TBigint | Operações de bits, `Init`, `Add/Sub/Mul/Div/Mod`, `DivMod`, `Increment/Decrement`, comparações, `IsZero`, `ToCString`, `ToCStringBase` | Inteiro sem sinal de largura fixa, limbs de 64 bits. |
| TDecimal | Mesma família aritmética e de conversão | Atualmente usa a mesma aritmética binária inteira de limbs; não tem escala ou parte fracionária decimal. |

Selecione tipos com `TBIGINT_TYPE(128)` e funções com
`TBIGINT_FUNC(128, Add)`, usando os equivalentes TDECIMAL/TBLOCK para as outras
famílias. A ordem de limbs usada pela aritmética põe o menos significativo em
`limb[0]`; a view de bytes não é formato de serialização independente de endian.

## Configuração

`TYPE_ENABLE_VTABLE` vale 1 por padrão. Defina 0 antes dos includes para remover
pseudo-métodos; chamadas diretas permanecem. As macros `TBigint`, `TDecimal` e
`TBlock` criam variáveis inicializadas e, quando habilitado, associam `api`.

Em Fundamental, escolha uma macro de cada par antes do include:
`TYPE_ALIAS_SMALL`/`TYPE_ALIAS_COMPLETE` e `TYPE_ALIAS_SAFE`/`TYPE_ALIAS_UNSAFE`.
O padrão é COMPLETE + UNSAFE: aliases longos sem namespace. SAFE aplica
`TYPE_MOD` aos nomes. Não defina simultaneamente os dois membros de um par e
mantenha as escolhas consistentes entre arquivos que trocam esses tipos.

## Erros e mutação

Aritmética geralmente modifica o primeiro operando. `DivMod` recebe dividend,
divisor e ponteiros de saída para quociente/resto; consulte a assinatura para
saídas opcionais. Cheque `OPSTATUS`, inclusive `ARITHMETIC_OVERFLOW`,
`DIVISION_BY_ZERO`, `OUT_OF_RANGE` e `INVALID_ARGUMENT` conforme a operação.
Não há garantia geral de transação: algumas operações de overflow já modificam
limbs. Trabalhe sobre uma cópia se precisar preservar o original em qualquer
falha.

`BitCheck` e `Compare` retornam status e escrevem a resposta em saída; as
consultas `Equal`, `NotEqual`, `LessThan`, `GreaterThan`, `LessOrEqual`,
`GreaterOrEqual` e `IsZero` retornam bool.

`ToCString` usa base 10; `ToCStringBase` aceita bases 2 a 36. O buffer é do
chamador e sua capacidade inclui NUL. Para uma representação binária de N bits,
reserve pelo menos N+1 bytes. Buffer insuficiente resulta em `OUT_OF_RANGE`.
Não há alocação dinâmica para aumentar a largura desses valores.

## Exemplo

<!-- example: Type.c -->

[Type.c](../examples/Type.c)

```c
#include <assert.h>
#include <string.h>
#include "Congro/Modules/Type/TBigint.h"

int main(void) {
  TBIGINT_TYPE(128) value = {0};
  char text[129];
  if (TBIGINT_FUNC(128, Init)(&value) != STATUS_CONST(SUCCESS))
    return 1;
  value.limb[0] = 42;
  if (TBIGINT_FUNC(128, ToCStringBase)(&value, text, sizeof(text), 16) !=
      STATUS_CONST(SUCCESS))
    return 2;
  assert(strcmp(text, "2a") == 0 || strcmp(text, "2A") == 0);
  return 0;
}
```

[Testes de aritmética, bits, formato e configuração](../../Codespace/Tests/Type).
