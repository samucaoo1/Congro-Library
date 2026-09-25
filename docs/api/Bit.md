# Bit: referência de API

[Guia de uso](../modules/Bit.md) · [Índice](../INDEX.md)

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
| [Bit.h](../../Codespace/Congro/Modules/Bit/Bit.h) | 17 |
| [Bit.space](../../Codespace/Congro/Modules/Bit/Bit.space) | 0 |

## Bit.h

[Declarações e implementação](../../Codespace/Congro/Modules/Bit/Bit.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `BIT_DECLARE(TYPE, SUFFIX, LITERAL)`

```c
void BIT_FUNC(SUFFIX, Set)(TYPE *value, uint8_t bit);

void BIT_FUNC(SUFFIX, Clear)(TYPE *value, uint8_t bit);

void BIT_FUNC(SUFFIX, Flip)(TYPE *value, uint8_t bit);

bool BIT_FUNC(SUFFIX, Check)(const TYPE *value, uint8_t bit);

void BIT_FUNC(SUFFIX, MaskSet)(TYPE *value, TYPE mask);

void BIT_FUNC(SUFFIX, MaskClear)(TYPE *value, TYPE mask);

void BIT_FUNC(SUFFIX, MaskFlip)(TYPE *value, TYPE mask);

bool BIT_FUNC(SUFFIX, MaskCheckAll)(const TYPE *value, TYPE mask);

bool BIT_FUNC(SUFFIX, MaskCheckAny)(const TYPE *value, TYPE mask);

uint64_t BIT_FUNC(SUFFIX, Popcount)(TYPE value);

bool BIT_FUNC(SUFFIX, IsPowerOfTwo)(TYPE value);

TYPE BIT_FUNC(SUFFIX, IndexLSB)(TYPE value);

TYPE BIT_FUNC(SUFFIX, IndexMSB)(TYPE value);

TYPE BIT_FUNC(SUFFIX, RotateLeft)(TYPE value, TYPE shift);

TYPE BIT_FUNC(SUFFIX, RotateRight)(TYPE value, TYPE shift);

TYPE BIT_FUNC(SUFFIX, Extract)(const TYPE *value, uint8_t high, uint8_t low);

void BIT_FUNC(SUFFIX, Insert)(TYPE *value, uint8_t high, uint8_t low, TYPE field_value);

```

## Bit.space

[Declarações e implementação](../../Codespace/Congro/Modules/Bit/Bit.space)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `BIT_MOD(NAME)`
- `BIT_TYPE(SUFFIX)`
- `BIT_FUNC(SUFFIX, FUNC)`
