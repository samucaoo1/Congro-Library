# Math: referência de API

[Guia de uso](../modules/Math.md) · [Índice](../INDEX.md)

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
| [Arithmetic/Basic.h](../../Codespace/Congro/Modules/Math/Arithmetic/Basic.h) | 5 |
| [Arithmetic/Clamp.h](../../Codespace/Congro/Modules/Math/Arithmetic/Clamp.h) | 6 |
| [Equation/Linear.h](../../Codespace/Congro/Modules/Math/Equation/Linear.h) | 1 |
| [Equation/Quadratic.h](../../Codespace/Congro/Modules/Math/Equation/Quadratic.h) | 3 |
| [Math.space](../../Codespace/Congro/Modules/Math/Math.space) | 0 |
| [Value/Between.h](../../Codespace/Congro/Modules/Math/Value/Between.h) | 2 |
| [Value/Clamp.h](../../Codespace/Congro/Modules/Math/Value/Clamp.h) | 1 |
| [Value/MaxAndMin.h](../../Codespace/Congro/Modules/Math/Value/MaxAndMin.h) | 4 |

## Arithmetic/Basic.h

[Declarações e implementação](../../Codespace/Congro/Modules/Math/Arithmetic/Basic.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `MATH_ARITHMETIC_BASIC_SIGNED_INSTANTIATE( TYPE, SUFFIX, MINIMUM, MAXIMUM)`
- `MATH_ARITHMETIC_BASIC_UNSIGNED_INSTANTIATE( TYPE, SUFFIX, MAXIMUM)`

```c
OPSTATUS ARITHMETIC_TYPED_FUNC(Add, SUFFIX)( TYPE a, TYPE b, TYPE *result);

OPSTATUS ARITHMETIC_TYPED_FUNC(Sub, SUFFIX)( TYPE a, TYPE b, TYPE *result);

OPSTATUS ARITHMETIC_TYPED_FUNC(Mul, SUFFIX)( TYPE a, TYPE b, TYPE *result);

OPSTATUS ARITHMETIC_TYPED_FUNC(Div, SUFFIX)( TYPE a, TYPE b, TYPE *result);

OPSTATUS ARITHMETIC_TYPED_FUNC(Mod, SUFFIX)( TYPE a, TYPE b, TYPE *result);

```

## Arithmetic/Clamp.h

[Declarações e implementação](../../Codespace/Congro/Modules/Math/Arithmetic/Clamp.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `MATH_ARITHMETIC_CLAMP_SIGNED_INSTANTIATE(TYPE, SUFFIX, MINIMUM, MAXIMUM)`
- `MATH_ARITHMETIC_CLAMP_UNSIGNED_INSTANTIATE(TYPE, SUFFIX, MAXIMUM)`

```c
TYPE ARITHMETIC_TYPED_FUNC(ClampAdd, SUFFIX)( TYPE a, TYPE b, TYPE minimum, TYPE maximum);

TYPE ARITHMETIC_TYPED_FUNC(ClampSub, SUFFIX)( TYPE a, TYPE b, TYPE minimum, TYPE maximum);

TYPE ARITHMETIC_TYPED_FUNC(ClampMul, SUFFIX)( TYPE a, TYPE b, TYPE minimum, TYPE maximum);

TYPE ARITHMETIC_TYPED_FUNC(SaturatingAdd, SUFFIX)( TYPE a, TYPE b);

TYPE ARITHMETIC_TYPED_FUNC(SaturatingSub, SUFFIX)( TYPE a, TYPE b);

TYPE ARITHMETIC_TYPED_FUNC(SaturatingMul, SUFFIX)( TYPE a, TYPE b);

```

## Equation/Linear.h

[Declarações e implementação](../../Codespace/Congro/Modules/Math/Equation/Linear.h)

```c
OPSTATUS EQUATION_TYPED_FUNC(Linear, SUFFIX)( TYPE a, TYPE b, TYPE *result, TMathSolution
    *solution);

```

## Equation/Quadratic.h

[Declarações e implementação](../../Codespace/Congro/Modules/Math/Equation/Quadratic.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `MATH_EQUATION_QUADRATIC_INSTANTIATE(TYPE, SUFFIX)`

```c
TYPE EQUATION_TYPED_FUNC(QuadraticDiscriminant, SUFFIX)( TYPE a, TYPE b, TYPE c);

OPSTATUS EQUATION_TYPED_FUNC(Quadratic, SUFFIX)( TYPE a, TYPE b, TYPE c, TYPE *result1, TYPE
    *result2, TMathSolution *solution);

OPSTATUS EQUATION_TYPED_FUNC(QuadraticComplex, SUFFIX)( TYPE a, TYPE b, TYPE c, COMPLEX_TYPE
    *result1, COMPLEX_TYPE *result2, TMathSolution *solution);

```

## Math.space

[Declarações e implementação](../../Codespace/Congro/Modules/Math/Math.space)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `MATH_MOD(NAME)`
- `MATH_TYPE(NAME)`
- `MATH_FUNC(SPACE, NAME)`
- `MATH_TYPED_FUNC(SPACE, NAME, SUFFIX)`
- `MATH_CONST(NAME)`
- `MATH_RANGE_CONST(NAME)`
- `ARITHMETIC_FUNC(NAME)`
- `ARITHMETIC_TYPED_FUNC(NAME, SUFFIX)`
- `VALUE_FUNC(NAME)`
- `VALUE_TYPED_FUNC(NAME, SUFFIX)`
- `EQUATION_FUNC(NAME)`
- `EQUATION_TYPED_FUNC(NAME, SUFFIX)`


## Value/Between.h

[Declarações e implementação](../../Codespace/Congro/Modules/Math/Value/Between.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `MATH_VALUE_BETWEEN_INSTANTIATE(TYPE, SUFFIX)`

```c
bool VALUE_TYPED_FUNC(IsBetween, SUFFIX)( TYPE value, TYPE minimum, TYPE maximum);

TMathRangeResult VALUE_TYPED_FUNC(Between, SUFFIX)( TYPE value, TYPE minimum, TYPE maximum);

```

## Value/Clamp.h

[Declarações e implementação](../../Codespace/Congro/Modules/Math/Value/Clamp.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `MATH_VALUE_CLAMP_INSTANTIATE(TYPE, SUFFIX)`

```c
TYPE VALUE_TYPED_FUNC(Clamp, SUFFIX)( TYPE value, TYPE minimum, TYPE maximum);

```

## Value/MaxAndMin.h

[Declarações e implementação](../../Codespace/Congro/Modules/Math/Value/MaxAndMin.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `MATH_VALUE_MAX_MIN_INSTANTIATE(TYPE, SUFFIX, VA_ARG_TYPE)`

```c
TYPE VALUE_TYPED_FUNC(Max, SUFFIX)( TYPE a, TYPE b);

TYPE VALUE_TYPED_FUNC(Min, SUFFIX)( TYPE a, TYPE b);

OPSTATUS VALUE_TYPED_FUNC(Smallest, SUFFIX)( TYPE *result, size_t size, ...);

OPSTATUS VALUE_TYPED_FUNC(Biggest, SUFFIX)( TYPE *result, size_t size, ...);

```
