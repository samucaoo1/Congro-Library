# Struct: referência de API

[Guia de uso](../modules/Struct.md) · [Índice](../INDEX.md)

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
| [Struct.space](../../Codespace/Congro/Modules/Struct/Struct.space) | 0 |
| [TDual.h](../../Codespace/Congro/Modules/Struct/TDual.h) | 2 |
| [TPair.h](../../Codespace/Congro/Modules/Struct/TPair.h) | 2 |
| [TPenta.h](../../Codespace/Congro/Modules/Struct/TPenta.h) | 2 |
| [TQuad.h](../../Codespace/Congro/Modules/Struct/TQuad.h) | 2 |
| [TTriple.h](../../Codespace/Congro/Modules/Struct/TTriple.h) | 2 |

## Struct.space

[Declarações e implementação](../../Codespace/Congro/Modules/Struct/Struct.space)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `STRUCT_MOD(NAME)`
- `STRUCT_TYPE(NAME, SUFFIX)`
- `STRUCT_FUNC(NAME, SUFFIX, FUNC)`


## TDual.h

[Declarações e implementação](../../Codespace/Congro/Modules/Struct/TDual.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TDUAL_TYPE(SUFFIX)`
- `TDUAL_FUNC(SUFFIX, FUNC)`
- `TDUAL_TYPE_DECLARE(TYPE, SUFFIX)`
- `TDUAL_DECLARE(TYPE, SUFFIX)`

```c
TDUAL_TYPE(SUFFIX) CAST_TYPE_TO_STRUCT(SUFFIX, TDual)(TYPE value1, TYPE value2);

void CAST_STRUCT_TO_TYPE(TDual, SUFFIX)( TDUAL_TYPE(SUFFIX) dual, TYPE *var1, TYPE *var2);

```

## TPair.h

[Declarações e implementação](../../Codespace/Congro/Modules/Struct/TPair.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TPAIR_TYPE(SUFFIX)`
- `TPAIR_FUNC(SUFFIX, FUNC)`
- `TPAIR_TYPE_DECLARE(TYPE, SUFFIX)`
- `TPAIR_DECLARE(TYPE, SUFFIX)`

```c
TPAIR_TYPE(SUFFIX) CAST_TYPE_TO_STRUCT(SUFFIX, TPair)(TYPE value1, TYPE value2);

void CAST_STRUCT_TO_TYPE(TPair, SUFFIX)( TPAIR_TYPE(SUFFIX) pair, TYPE *var1, TYPE *var2);

```

## TPenta.h

[Declarações e implementação](../../Codespace/Congro/Modules/Struct/TPenta.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TPENTA_TYPE(SUFFIX)`
- `TPENTA_FUNC(SUFFIX, FUNC)`
- `TPENTA_TYPE_DECLARE(TYPE, SUFFIX)`
- `TPENTA_DECLARE(TYPE, SUFFIX)`

```c
TPENTA_TYPE(SUFFIX) CAST_TYPE_TO_STRUCT(SUFFIX, TPenta)( TYPE value1, TYPE value2, TYPE value3,
    TYPE value4,TYPE value5);

void CAST_STRUCT_TO_TYPE(TPenta, SUFFIX)( TPENTA_TYPE(SUFFIX) penta, TYPE *var1, TYPE *var2,
    TYPE *var3, TYPE *var4,TYPE *var5);

```

## TQuad.h

[Declarações e implementação](../../Codespace/Congro/Modules/Struct/TQuad.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TQUAD_TYPE(SUFFIX)`
- `TQUAD_FUNC(SUFFIX, FUNC)`
- `TQUAD_TYPE_DECLARE(TYPE, SUFFIX)`
- `TQUAD_DECLARE(TYPE, SUFFIX)`

```c
TQUAD_TYPE(SUFFIX) CAST_TYPE_TO_STRUCT(SUFFIX, TQuad)( TYPE value1, TYPE value2, TYPE value3,
    TYPE value4);

void CAST_STRUCT_TO_TYPE(TQuad, SUFFIX)( TQUAD_TYPE(SUFFIX) quad, TYPE *var1, TYPE *var2, TYPE
    *var3, TYPE *var4);

```

## TTriple.h

[Declarações e implementação](../../Codespace/Congro/Modules/Struct/TTriple.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `TTRIPLE_TYPE(SUFFIX)`
- `TTRIPLE_FUNC(SUFFIX, FUNC)`
- `TTRIPLE_TYPE_DECLARE(TYPE, SUFFIX)`
- `TTRIPLE_DECLARE(TYPE, SUFFIX)`

```c
TTRIPLE_TYPE(SUFFIX) CAST_TYPE_TO_STRUCT(SUFFIX, TTriple)( TYPE value1, TYPE value2, TYPE
    value3);

void CAST_STRUCT_TO_TYPE(TTriple, SUFFIX)( TTRIPLE_TYPE(SUFFIX) triple, TYPE *var1, TYPE *var2,
    TYPE *var3);

```
