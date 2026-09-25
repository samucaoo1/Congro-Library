# Type: referência de API

[Guia de uso](../modules/Type.md) · [Índice](../INDEX.md)

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
| [Fundamental.h](../../Codespace/Congro/Modules/Type/Fundamental.h) | 0 |
| [TBigint.h](../../Codespace/Congro/Modules/Type/TBigint.h) | 31 |
| [TBlock.h](../../Codespace/Congro/Modules/Type/TBlock.h) | 12 |
| [TDecimal.h](../../Codespace/Congro/Modules/Type/TDecimal.h) | 31 |
| [Type.space](../../Codespace/Congro/Modules/Type/Type.space) | 0 |
| [VTable/TBigint.h](../../Codespace/Congro/Modules/Type/VTable/TBigint.h) | 0 |
| [VTable/TBlock.h](../../Codespace/Congro/Modules/Type/VTable/TBlock.h) | 0 |
| [VTable/TDecimal.h](../../Codespace/Congro/Modules/Type/VTable/TDecimal.h) | 0 |

## Fundamental.h

[Declarações e implementação](../../Codespace/Congro/Modules/Type/Fundamental.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TYPE_ALIAS_COMPLETE`
- `TYPE_ALIAS_UNSAFE`
- `TYPE_ALIAS_APPLY(NAME)`
- `TYPE_ALIAS(SMALL, COMPLETE)`


## TBigint.h

[Declarações e implementação](../../Codespace/Congro/Modules/Type/TBigint.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TBIGINT_TYPE(SUFFIX)`
- `TBIGINT_FUNC(SUFFIX, FUNCTION)`
- `TYPE_VTABLE_DECLARE_TBIGINT(SUFFIX)`
- `TBIGINT_DECLARE(SUFFIX, TYPE, WORD_COUNT, SIZE_IN_BYTES)`
- `TBigint(SUFFIX, NAME)`

```c
OPSTATUS TBIGINT_FUNC(SUFFIX, Clear)(TBIGINT_TYPE(SUFFIX) * bigint);

OPSTATUS TBIGINT_FUNC(SUFFIX, Init)(TBIGINT_TYPE(SUFFIX) * bigint);

OPSTATUS TBIGINT_FUNC(SUFFIX, Add)( TBIGINT_TYPE(SUFFIX) * destinationBigint, const
    TBIGINT_TYPE(SUFFIX) * sourceBigint);

OPSTATUS TBIGINT_FUNC(SUFFIX, Sub)( TBIGINT_TYPE(SUFFIX) * destinationBigint, const
    TBIGINT_TYPE(SUFFIX) * sourceBigint);

OPSTATUS TBIGINT_FUNC(SUFFIX, Mul)( TBIGINT_TYPE(SUFFIX) * destinationBigint, const
    TBIGINT_TYPE(SUFFIX) * sourceBigint);

OPSTATUS TBIGINT_FUNC(SUFFIX, DivMod)( const TBIGINT_TYPE(SUFFIX) *dividend, const
    TBIGINT_TYPE(SUFFIX) *divisor, TBIGINT_TYPE(SUFFIX) *quotient, TBIGINT_TYPE(SUFFIX)
    *remainder);

OPSTATUS TBIGINT_FUNC(SUFFIX, Div)( TBIGINT_TYPE(SUFFIX) * dividendBigint, const
    TBIGINT_TYPE(SUFFIX) * divisorBigint);

OPSTATUS TBIGINT_FUNC(SUFFIX, Mod)( TBIGINT_TYPE(SUFFIX) * dividendBigint, const
    TBIGINT_TYPE(SUFFIX) * divisorBigint);

OPSTATUS TBIGINT_FUNC(SUFFIX, Increment)(TBIGINT_TYPE(SUFFIX) * targetBigint);

OPSTATUS TBIGINT_FUNC(SUFFIX, Decrement)(TBIGINT_TYPE(SUFFIX) * targetBigint);

OPSTATUS TBIGINT_FUNC(SUFFIX, And)( TBIGINT_TYPE(SUFFIX) * destinationBigint, const
    TBIGINT_TYPE(SUFFIX) * sourceBigint);

OPSTATUS TBIGINT_FUNC(SUFFIX, Or)( TBIGINT_TYPE(SUFFIX) * destinationBigint, const
    TBIGINT_TYPE(SUFFIX) * sourceBigint);

OPSTATUS TBIGINT_FUNC(SUFFIX, Xor)( TBIGINT_TYPE(SUFFIX) * destinationBigint, const
    TBIGINT_TYPE(SUFFIX) * sourceBigint);

OPSTATUS TBIGINT_FUNC(SUFFIX, Not)(TBIGINT_TYPE(SUFFIX) * targetBigint);

OPSTATUS TBIGINT_FUNC(SUFFIX, ShiftLeft)( TBIGINT_TYPE(SUFFIX) * targetBigint, unsigned
    bitCount);

OPSTATUS TBIGINT_FUNC(SUFFIX, ShiftRight)( TBIGINT_TYPE(SUFFIX) * targetBigint, unsigned
    bitCount);

OPSTATUS TBIGINT_FUNC(SUFFIX, RotateLeft)( TBIGINT_TYPE(SUFFIX) * targetBigint, unsigned
    bitCount);

OPSTATUS TBIGINT_FUNC(SUFFIX, RotateRight)( TBIGINT_TYPE(SUFFIX) * targetBigint, unsigned
    bitCount);

OPSTATUS TBIGINT_FUNC(SUFFIX, BitSet)( TBIGINT_TYPE(SUFFIX) * bigint, uint32_t bit);

OPSTATUS TBIGINT_FUNC(SUFFIX, BitClear)( TBIGINT_TYPE(SUFFIX) * bigint, uint32_t bit);

OPSTATUS TBIGINT_FUNC(SUFFIX, BitCheck)( const TBIGINT_TYPE(SUFFIX) *bigint, uint32_t bit, bool
    *result);

OPSTATUS TBIGINT_FUNC(SUFFIX, Compare)( const TBIGINT_TYPE(SUFFIX) * leftBigint, const
    TBIGINT_TYPE(SUFFIX) * rightBigint, TComparisonResult *result);

bool TBIGINT_FUNC(SUFFIX, Equal)( const TBIGINT_TYPE(SUFFIX) * leftBigint, const
    TBIGINT_TYPE(SUFFIX) * rightBigint);

bool TBIGINT_FUNC(SUFFIX, NotEqual)( const TBIGINT_TYPE(SUFFIX) * leftBigint, const
    TBIGINT_TYPE(SUFFIX) * rightBigint);

bool TBIGINT_FUNC(SUFFIX, LessThan)( const TBIGINT_TYPE(SUFFIX) * leftBigint, const
    TBIGINT_TYPE(SUFFIX) * rightBigint);

bool TBIGINT_FUNC(SUFFIX, GreaterThan)( const TBIGINT_TYPE(SUFFIX) * leftBigint, const
    TBIGINT_TYPE(SUFFIX) * rightBigint);

bool TBIGINT_FUNC(SUFFIX, LessOrEqual)( const TBIGINT_TYPE(SUFFIX) * leftBigint, const
    TBIGINT_TYPE(SUFFIX) * rightBigint);

bool TBIGINT_FUNC(SUFFIX, GreaterOrEqual)( const TBIGINT_TYPE(SUFFIX) * leftBigint, const
    TBIGINT_TYPE(SUFFIX) * rightBigint);

OPSTATUS TBIGINT_FUNC(SUFFIX, ToCStringBase)( const TBIGINT_TYPE(SUFFIX) *value, char *buffer,
    size_t bufferSize, unsigned base);

OPSTATUS TBIGINT_FUNC(SUFFIX, ToCString)( const TBIGINT_TYPE(SUFFIX) *value, char *buffer,
    size_t bufferSize);

bool TBIGINT_FUNC(SUFFIX, IsZero)(const TBIGINT_TYPE(SUFFIX) * targetBigint);

```

## TBlock.h

[Declarações e implementação](../../Codespace/Congro/Modules/Type/TBlock.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TBLOCK_TYPE(SUFFIX)`
- `TBLOCK_FUNC(SUFFIX, FUNCTION)`
- `TYPE_VTABLE_DECLARE_TBLOCK(SUFFIX)`
- `TBLOCK_DECLARE(SUFFIX, TYPE, WORD_COUNT, SIZE_IN_BYTES, BIT_SUFFIX)`
- `TBlock(SUFFIX, NAME)`

```c
OPSTATUS TBLOCK_FUNC(SUFFIX, Clear)(TBLOCK_TYPE(SUFFIX) * block);

OPSTATUS TBLOCK_FUNC(SUFFIX, And)( TBLOCK_TYPE(SUFFIX) * destinationBlock, const
    TBLOCK_TYPE(SUFFIX) * sourceBlock);

OPSTATUS TBLOCK_FUNC(SUFFIX, Or)(TBLOCK_TYPE(SUFFIX) * destinationBlock, const
    TBLOCK_TYPE(SUFFIX) * sourceBlock);

OPSTATUS TBLOCK_FUNC(SUFFIX, Xor)( TBLOCK_TYPE(SUFFIX) * destinationBlock, const
    TBLOCK_TYPE(SUFFIX) * sourceBlock);

OPSTATUS TBLOCK_FUNC(SUFFIX, Not)(TBLOCK_TYPE(SUFFIX) * targetBlock);

OPSTATUS TBLOCK_FUNC(SUFFIX, ShiftLeft)( TBLOCK_TYPE(SUFFIX) * targetBlock, unsigned bitCount);

OPSTATUS TBLOCK_FUNC(SUFFIX, ShiftRight)( TBLOCK_TYPE(SUFFIX) * targetBlock, unsigned bitCount);

OPSTATUS TBLOCK_FUNC(SUFFIX, RotateLeft)( TBLOCK_TYPE(SUFFIX) * targetBlock, unsigned bitCount);

OPSTATUS TBLOCK_FUNC(SUFFIX, RotateRight)( TBLOCK_TYPE(SUFFIX) * targetBlock, unsigned
    bitCount);

OPSTATUS TBLOCK_FUNC(SUFFIX, BitSet)(TBLOCK_TYPE(SUFFIX) * block, uint32_t bit);

OPSTATUS TBLOCK_FUNC(SUFFIX, BitClear)( TBLOCK_TYPE(SUFFIX) * block, uint32_t bit);

OPSTATUS TBLOCK_FUNC(SUFFIX, BitCheck)( const TBLOCK_TYPE(SUFFIX) *block, uint32_t bit, bool
    *result);

```

## TDecimal.h

[Declarações e implementação](../../Codespace/Congro/Modules/Type/TDecimal.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TDECIMAL_TYPE(SUFFIX)`
- `TDECIMAL_FUNC(SUFFIX, FUNCTION)`
- `TYPE_VTABLE_DECLARE_TDECIMAL(SUFFIX)`
- `TDECIMAL_DECLARE(SUFFIX, TYPE, WORD_COUNT, SIZE_IN_BYTES)`
- `TDecimal(SUFFIX, NAME)`

```c
OPSTATUS TDECIMAL_FUNC(SUFFIX, Clear)(TDECIMAL_TYPE(SUFFIX) * decimal);

OPSTATUS TDECIMAL_FUNC(SUFFIX, Init)(TDECIMAL_TYPE(SUFFIX) * decimal);

OPSTATUS TDECIMAL_FUNC(SUFFIX, Add)( TDECIMAL_TYPE(SUFFIX) * destinationDecimal, const
    TDECIMAL_TYPE(SUFFIX) * sourceDecimal);

OPSTATUS TDECIMAL_FUNC(SUFFIX, Sub)( TDECIMAL_TYPE(SUFFIX) * destinationDecimal, const
    TDECIMAL_TYPE(SUFFIX) * sourceDecimal);

OPSTATUS TDECIMAL_FUNC(SUFFIX, Mul)( TDECIMAL_TYPE(SUFFIX) * destinationDecimal, const
    TDECIMAL_TYPE(SUFFIX) * sourceDecimal);

OPSTATUS TDECIMAL_FUNC(SUFFIX, DivMod)( const TDECIMAL_TYPE(SUFFIX) *dividend, const
    TDECIMAL_TYPE(SUFFIX) *divisor, TDECIMAL_TYPE(SUFFIX) *quotient, TDECIMAL_TYPE(SUFFIX)
    *remainder);

OPSTATUS TDECIMAL_FUNC(SUFFIX, Div)( TDECIMAL_TYPE(SUFFIX) * dividendDecimal, const
    TDECIMAL_TYPE(SUFFIX) * divisorDecimal);

OPSTATUS TDECIMAL_FUNC(SUFFIX, Mod)( TDECIMAL_TYPE(SUFFIX) * dividendDecimal, const
    TDECIMAL_TYPE(SUFFIX) * divisorDecimal);

OPSTATUS TDECIMAL_FUNC(SUFFIX, Increment)(TDECIMAL_TYPE(SUFFIX) * targetDecimal);

OPSTATUS TDECIMAL_FUNC(SUFFIX, Decrement)(TDECIMAL_TYPE(SUFFIX) * targetDecimal);

OPSTATUS TDECIMAL_FUNC(SUFFIX, And)( TDECIMAL_TYPE(SUFFIX) * destinationDecimal, const
    TDECIMAL_TYPE(SUFFIX) * sourceDecimal);

OPSTATUS TDECIMAL_FUNC(SUFFIX, Or)( TDECIMAL_TYPE(SUFFIX) * destinationDecimal, const
    TDECIMAL_TYPE(SUFFIX) * sourceDecimal);

OPSTATUS TDECIMAL_FUNC(SUFFIX, Xor)( TDECIMAL_TYPE(SUFFIX) * destinationDecimal, const
    TDECIMAL_TYPE(SUFFIX) * sourceDecimal);

OPSTATUS TDECIMAL_FUNC(SUFFIX, Not)(TDECIMAL_TYPE(SUFFIX) * targetDecimal);

OPSTATUS TDECIMAL_FUNC(SUFFIX, ShiftLeft)( TDECIMAL_TYPE(SUFFIX) * targetDecimal, unsigned
    bitCount);

OPSTATUS TDECIMAL_FUNC(SUFFIX, ShiftRight)( TDECIMAL_TYPE(SUFFIX) * targetDecimal, unsigned
    bitCount);

OPSTATUS TDECIMAL_FUNC(SUFFIX, RotateLeft)( TDECIMAL_TYPE(SUFFIX) * targetDecimal, unsigned
    bitCount);

OPSTATUS TDECIMAL_FUNC(SUFFIX, RotateRight)( TDECIMAL_TYPE(SUFFIX) * targetDecimal, unsigned
    bitCount);

OPSTATUS TDECIMAL_FUNC(SUFFIX, BitSet)( TDECIMAL_TYPE(SUFFIX) * decimal, uint32_t bit);

OPSTATUS TDECIMAL_FUNC(SUFFIX, BitClear)( TDECIMAL_TYPE(SUFFIX) * decimal, uint32_t bit);

OPSTATUS TDECIMAL_FUNC(SUFFIX, BitCheck)( const TDECIMAL_TYPE(SUFFIX) *decimal, uint32_t bit,
    bool *result);

OPSTATUS TDECIMAL_FUNC(SUFFIX, Compare)( const TDECIMAL_TYPE(SUFFIX) * leftDecimal, const
    TDECIMAL_TYPE(SUFFIX) * rightDecimal, TComparisonResult *result);

bool TDECIMAL_FUNC(SUFFIX, Equal)( const TDECIMAL_TYPE(SUFFIX) * leftDecimal, const
    TDECIMAL_TYPE(SUFFIX) * rightDecimal);

bool TDECIMAL_FUNC(SUFFIX, NotEqual)( const TDECIMAL_TYPE(SUFFIX) * leftDecimal, const
    TDECIMAL_TYPE(SUFFIX) * rightDecimal);

bool TDECIMAL_FUNC(SUFFIX, LessThan)( const TDECIMAL_TYPE(SUFFIX) * leftDecimal, const
    TDECIMAL_TYPE(SUFFIX) * rightDecimal);

bool TDECIMAL_FUNC(SUFFIX, GreaterThan)( const TDECIMAL_TYPE(SUFFIX) * leftDecimal, const
    TDECIMAL_TYPE(SUFFIX) * rightDecimal);

bool TDECIMAL_FUNC(SUFFIX, LessOrEqual)( const TDECIMAL_TYPE(SUFFIX) * leftDecimal, const
    TDECIMAL_TYPE(SUFFIX) * rightDecimal);

bool TDECIMAL_FUNC(SUFFIX, GreaterOrEqual)( const TDECIMAL_TYPE(SUFFIX) * leftDecimal, const
    TDECIMAL_TYPE(SUFFIX) * rightDecimal);

OPSTATUS TDECIMAL_FUNC(SUFFIX, ToCStringBase)( const TDECIMAL_TYPE(SUFFIX) *value, char *buffer,
    size_t bufferSize, unsigned base);

OPSTATUS TDECIMAL_FUNC(SUFFIX, ToCString)( const TDECIMAL_TYPE(SUFFIX) *value, char *buffer,
    size_t bufferSize);

bool TDECIMAL_FUNC(SUFFIX, IsZero)( const TDECIMAL_TYPE(SUFFIX) * targetDecimal);

```

## Type.space

[Declarações e implementação](../../Codespace/Congro/Modules/Type/Type.space)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TYPE_MOD(NAME)`
- `TYPE_TYPE(NAME, SUFFIX)`
- `TYPE_FUNC(NAME, SUFFIX, FUNCTION)`
- `TYPE_ENABLE_VTABLE`


## Impl/TBigint.impl

[Declarações e implementação](../../Codespace/Congro/Modules/Type/Impl/TBigint.impl)

```c
OPSTATUS TBIGINT_FUNC(SUFFIX, Div)( TBIGINT_TYPE(SUFFIX) *dividend, const TBIGINT_TYPE(SUFFIX)
    *divisor);

OPSTATUS TBIGINT_FUNC(SUFFIX, Mod)( TBIGINT_TYPE(SUFFIX) *dividend, const TBIGINT_TYPE(SUFFIX)
    *divisor);

```

## Impl/TDecimal.impl

[Declarações e implementação](../../Codespace/Congro/Modules/Type/Impl/TDecimal.impl)

```c
OPSTATUS TDECIMAL_FUNC(SUFFIX, Div)( TDECIMAL_TYPE(SUFFIX) *dividend, const
    TDECIMAL_TYPE(SUFFIX) *divisor);

OPSTATUS TDECIMAL_FUNC(SUFFIX, Mod)( TDECIMAL_TYPE(SUFFIX) *dividend, const
    TDECIMAL_TYPE(SUFFIX) *divisor);

```
