# Math

[Índice](../INDEX.md) · [Referência de assinaturas](../api/Math.md)

Inclua somente os headers necessários em `Congro/Modules/Math`. Os nomes são
compostos por `ARITHMETIC_TYPED_FUNC`, `VALUE_TYPED_FUNC` e
`EQUATION_TYPED_FUNC`. Exemplo: `ARITHMETIC_TYPED_FUNC(Add, I32)`.

## Pacotes

| Header | Operações | Tipos |
|---|---|---|
| `Arithmetic/Basic.h` | `Add`, `Sub`, `Mul`, `Div`, `Mod` | I8/I16/I32/I64 e U8/U16/U32/U64. |
| `Arithmetic/Clamp.h` | `ClampAdd`, `ClampSub`, `ClampMul`, `SaturatingAdd`, `SaturatingSub`, `SaturatingMul` | As mesmas larguras inteiras. |
| `Value/Between.h` | `IsBetween`, `Between` | Inteiros e F32/F64/F128. |
| `Value/Clamp.h` | `Clamp` | Inteiros e F32/F64/F128. |
| `Value/MaxAndMin.h` | `Max`, `Min`, `Smallest`, `Biggest` | Inteiros e F32/F64/F128. |
| `Equation/Linear.h` | `Linear` | F32/F64/F128. |
| `Equation/Quadratic.h` | `QuadraticDiscriminant`, `Quadratic`, `QuadraticComplex` | F32/F64/F128; complexos indisponíveis no caminho MSVC. |

F128 é o sufixo usado para `long double`; ele não promete IEEE binary128 em
qualquer plataforma.

## Aritmética e intervalos

A aritmética básica retorna `OPSTATUS` e escreve em `result`. Verifique
`ARITHMETIC_OVERFLOW`, `DIVISION_BY_ZERO` e `INVALID_ARGUMENT`, além de SUCCESS.
Use o resultado somente após sucesso. Saturating limita ao intervalo do tipo;
ClampAdd/Sub/Mul recebe limites escolhidos pelo chamador.

`IsBetween(value, minimum, maximum)` usa **intervalo aberto**: os extremos
retornam falso. `Between` distingue `LOWER`, `EQUAL_MINIMUM`, `BETWEEN`,
`EQUAL_MAXIMUM` e `HIGHER` via `MATH_RANGE_CONST`. Para classificação,
forneça limites ordenados. `Clamp` devolve um valor dentro do intervalo fechado.
Não trate as comparações como uma política geral para NaN.

`Smallest` e `Biggest` recebem ponteiro de saída, quantidade e argumentos
variádicos. A quantidade deve corresponder aos argumentos; os tipos precisam
seguir as promoções C (`float` vira `double`; inteiros estreitos viram `int`).
Para I64/U64/F128 passe explicitamente valores desses tipos.

## Equações

`Linear` resolve `a*x + b = 0`. `Quadratic` resolve `a*x*x + b*x + c = 0`;
`QuadraticDiscriminant` calcula o discriminante. Além do status operacional,
consulte `TMathSolution`: `MATH_CONST(SOLUTION_NONE/ONE/MULTIPLE/INFINITE)`.
Uma execução bem-sucedida pode indicar nenhuma solução ou infinitas soluções;
não leia raízes como se sempre existissem duas.

`QuadraticComplex` usa tipos `_Complex` quando o compilador os suporta pelo
caminho definido no header. A implementação usa seu próprio cálculo de raiz,
sem exigir `-lm`; isso não implica precisão arbitrária ou equivalência a uma
biblioteca numérica especializada.

## Exemplo

<!-- example: Math.c -->

[Math.c](../examples/Math.c)

```c
#include <assert.h>
#include "Congro/Modules/Math/Arithmetic/Basic.h"
#include "Congro/Modules/Math/Value/Between.h"
#include "Congro/Modules/Math/Value/Clamp.h"

int main(void) {
  int32_t result = 0;
  if (ARITHMETIC_TYPED_FUNC(Add, I32)(20, 22, &result) != STATUS_CONST(SUCCESS))
    return 1;
  assert(result == 42);
  assert(!VALUE_TYPED_FUNC(IsBetween, I32)(0, 0, 10));
  assert(VALUE_TYPED_FUNC(Clamp, I32)(12, 0, 10) == 10);
  assert(ARITHMETIC_TYPED_FUNC(Add, I32)(INT32_MAX, 1, &result) ==
         STATUS_CONST(ARITHMETIC_OVERFLOW));
  return 0;
}
```

[Testes de aritmética, valores e equações](../../Codespace/Tests/Math).
