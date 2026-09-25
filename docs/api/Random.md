# Random: referência de API

[Guia de uso](../modules/Random.md) · [Índice](../INDEX.md)

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
| [Distribution/Boolean.h](../../Codespace/Congro/Modules/Random/Distribution/Boolean.h) | 1 |
| [Distribution/Distribution.h](../../Codespace/Congro/Modules/Random/Distribution/Distribution.h) | 0 |
| [Distribution/Distribution.space](../../Codespace/Congro/Modules/Random/Distribution/Distribution.space) | 0 |
| [Distribution/Integer.h](../../Codespace/Congro/Modules/Random/Distribution/Integer.h) | 2 |
| [Distribution/Real.h](../../Codespace/Congro/Modules/Random/Distribution/Real.h) | 1 |
| [Engine/Engine.h](../../Codespace/Congro/Modules/Random/Engine/Engine.h) | 0 |
| [Engine/Engine.space](../../Codespace/Congro/Modules/Random/Engine/Engine.space) | 2 |
| [Engine/Lcg.h](../../Codespace/Congro/Modules/Random/Engine/Lcg.h) | 0 |
| [Engine/Pcg.h](../../Codespace/Congro/Modules/Random/Engine/Pcg.h) | 0 |
| [Engine/Romu.h](../../Codespace/Congro/Modules/Random/Engine/Romu.h) | 0 |
| [Engine/Sfc.h](../../Codespace/Congro/Modules/Random/Engine/Sfc.h) | 0 |
| [Engine/Splitmix.h](../../Codespace/Congro/Modules/Random/Engine/Splitmix.h) | 0 |
| [Engine/VTable.h](../../Codespace/Congro/Modules/Random/Engine/VTable.h) | 2 |
| [Engine/WyRand.h](../../Codespace/Congro/Modules/Random/Engine/WyRand.h) | 0 |
| [Engine/Xoroshiro.h](../../Codespace/Congro/Modules/Random/Engine/Xoroshiro.h) | 0 |
| [Engine/Xoshiro.h](../../Codespace/Congro/Modules/Random/Engine/Xoshiro.h) | 0 |
| [Entropy/Entropy.h](../../Codespace/Congro/Modules/Random/Entropy/Entropy.h) | 7 |
| [Entropy/Entropy.space](../../Codespace/Congro/Modules/Random/Entropy/Entropy.space) | 0 |
| [Entropy/Pool/Pool.h](../../Codespace/Congro/Modules/Random/Entropy/Pool/Pool.h) | 3 |
| [Mixer/Mixer.h](../../Codespace/Congro/Modules/Random/Mixer/Mixer.h) | 1 |
| [Random.h](../../Codespace/Congro/Modules/Random/Random.h) | 6 |
| [Random.space](../../Codespace/Congro/Modules/Random/Random.space) | 0 |
| [Shuffle/Shuffle.h](../../Codespace/Congro/Modules/Random/Shuffle/Shuffle.h) | 2 |
| [Shuffle/Shuffle.space](../../Codespace/Congro/Modules/Random/Shuffle/Shuffle.space) | 0 |
| [Source/Source.h](../../Codespace/Congro/Modules/Random/Source/Source.h) | 6 |

## Distribution/Boolean.h

[Declarações e implementação](../../Codespace/Congro/Modules/Random/Distribution/Boolean.h)

```c
bool RANDOM_DISTRIBUTION_FUNC(Bool)(TRandomSource *source);

```

## Distribution/Integer.h

[Declarações e implementação](../../Codespace/Congro/Modules/Random/Distribution/Integer.h)

```c
uint64_t RANDOM_DISTRIBUTION_FUNC(U64)(TRandomSource *source, uint64_t minimum, uint64_t
    maximum);

int64_t RANDOM_DISTRIBUTION_FUNC(I64)(TRandomSource *source, int64_t minimum, int64_t maximum);

```

## Distribution/Real.h

[Declarações e implementação](../../Codespace/Congro/Modules/Random/Distribution/Real.h)

```c
double RANDOM_DISTRIBUTION_FUNC(F64)(TRandomSource *source);

```

## Engine/Engine.space

[Declarações e implementação](../../Codespace/Congro/Modules/Random/Engine/Engine.space)

```c
void RANDOM_ENGINE_FUNC(ENGINE, Seed)( RANDOM_ENGINE_TYPE(ENGINE) *state, uint64_t seed);

uint64_t RANDOM_ENGINE_FUNC(ENGINE, Next)( RANDOM_ENGINE_TYPE(ENGINE) *state);

```

## Engine/VTable.h

[Declarações e implementação](../../Codespace/Congro/Modules/Random/Engine/VTable.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `RANDOM_ENGINE_VTABLE_UNUSED`
- `RANDOM_ENGINE_VTABLE_DEFINE(ENGINE)`

```c
uint64_t RANDOM_ENGINE_FUNC(ENGINE, VTableNext)(void *state);

void RANDOM_ENGINE_FUNC(ENGINE, VTableSeed)( void *state, uint64_t seed);

```

## Entropy/Entropy.h

[Declarações e implementação](../../Codespace/Congro/Modules/Random/Entropy/Entropy.h)

```c
bool RANDOM_ENTROPY_FUNC(System)(void *destination, size_t size);

uint64_t RANDOM_ENTROPY_FUNC(Address)(void);

uint64_t RANDOM_ENTROPY_FUNC(Clock)(void);

uint64_t RANDOM_ENTROPY_FUNC(Jitter)(void);

uint64_t RANDOM_ENTROPY_FUNC(Thread)(void);

uint64_t RANDOM_ENTROPY_FUNC(Time)(void);

uint64_t RANDOM_ENTROPY_FUNC(Collect)(void);

```

## Entropy/Pool/Pool.h

[Declarações e implementação](../../Codespace/Congro/Modules/Random/Entropy/Pool/Pool.h)

```c
void RANDOM_ENTROPY_FUNC(Pool_Init)(RANDOM_ENTROPY_TYPE(Pool) *pool);

void RANDOM_ENTROPY_FUNC(Pool_Add)(RANDOM_ENTROPY_TYPE(Pool) *pool, uint64_t value);

uint64_t RANDOM_ENTROPY_FUNC(Pool_Finalize)( const RANDOM_ENTROPY_TYPE(Pool) *pool);

```

## Mixer/Mixer.h

[Declarações e implementação](../../Codespace/Congro/Modules/Random/Mixer/Mixer.h)

```c
uint64_t RANDOM_MIXER_FUNC(NAME)(uint64_t value);

```

## Random.h

[Declarações e implementação](../../Codespace/Congro/Modules/Random/Random.h)

```c
uint64_t RANDOM_FUNC(U64)(void);

uint64_t RANDOM_FUNC(U64_FromSeed)(uint64_t seed);

uint64_t RANDOM_FUNC(RangeU64)(uint64_t minimum, uint64_t maximum);

int64_t RANDOM_FUNC(RangeI64)(int64_t minimum, int64_t maximum);

double RANDOM_FUNC(F64)(void);

bool RANDOM_FUNC(Bool)(void);

```

## Random.space

[Declarações e implementação](../../Codespace/Congro/Modules/Random/Random.space)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `RANDOM_MOD(NAME)`
- `RANDOM_TYPE(NAME)`
- `RANDOM_FUNC(NAME)`
- `RANDOM_ENGINE_TYPE(NAME)`
- `RANDOM_ENGINE_FUNC(ENGINE, NAME)`
- `RANDOM_ENTROPY_TYPE(NAME)`
- `RANDOM_ENTROPY_FUNC(NAME)`
- `RANDOM_MIXER_TYPE(NAME)`
- `RANDOM_MIXER_FUNC(NAME)`
- `RANDOM_SOURCE_TYPE(NAME)`
- `RANDOM_SOURCE_FUNC(NAME)`
- `RANDOM_DISTRIBUTION_FUNC(NAME)`
- `RANDOM_SHUFFLE_FUNC(NAME)`


## Shuffle/Shuffle.h

[Declarações e implementação](../../Codespace/Congro/Modules/Random/Shuffle/Shuffle.h)

Macros de seleção, configuração ou geração (consulte o header para expansão):

- `RANDOM_SHUFFLE_VECTOR(VECTOR, COUNT)`
- `RANDOM_SHUFFLE_VECTOR_FROM_SOURCE(VECTOR, COUNT, SOURCE)`

```c
OPSTATUS RANDOM_SHUFFLE_FUNC(VectorFromSource)( void *vector, size_t count, size_t elementSize,
    TRandomSource *source);

OPSTATUS RANDOM_SHUFFLE_FUNC(Vector)(void *vector, size_t count, size_t elementSize);

```

## Source/Source.h

[Declarações e implementação](../../Codespace/Congro/Modules/Random/Source/Source.h)

```c
OPSTATUS RANDOM_SOURCE_FUNC(Init)( TRandomSource *source, const RANDOM_ENGINE_VTABLE *engine,
    uint64_t seed, RANDOM_MIXER_FUNCTION mixer);

OPSTATUS RANDOM_SOURCE_FUNC(InitWithState)( TRandomSource *source, const RANDOM_ENGINE_VTABLE
    *engine, void *state, size_t stateSize, uint64_t seed, RANDOM_MIXER_FUNCTION mixer);

OPSTATUS RANDOM_SOURCE_FUNC(InitSystem)( TRandomSource *source, const RANDOM_ENGINE_VTABLE
    *engine, RANDOM_MIXER_FUNCTION mixer);

OPSTATUS RANDOM_SOURCE_FUNC(Reseed)(TRandomSource *source, uint64_t seed);

uint64_t RANDOM_SOURCE_FUNC(NextU64)(TRandomSource *source);

void RANDOM_SOURCE_FUNC(Destroy)(TRandomSource *source);

```

## Engine/Impl/WyRand.impl

[Declarações e implementação](../../Codespace/Congro/Modules/Random/Engine/Impl/WyRand.impl)

```c
uint64_t RANDOM_ENGINE_FUNC(WyRand, Mum)(uint64_t a, uint64_t b);

```

## Engine/Seed.impl

[Declarações e implementação](../../Codespace/Congro/Modules/Random/Engine/Seed.impl)

```c
uint64_t RANDOM_ENGINE_FUNC(Common, RotateLeft)(uint64_t value, unsigned shift);

```

## Entropy/Pool/Impl/Pool.impl

[Declarações e implementação](../../Codespace/Congro/Modules/Random/Entropy/Pool/Impl/Pool.impl)

```c
uint64_t RANDOM_ENTROPY_FUNC(Pool_Mix)(uint64_t value);

```

## Impl/Random.impl

[Declarações e implementação](../../Codespace/Congro/Modules/Random/Impl/Random.impl)

```c
TRandomSource RANDOM_FUNC(SourceFromSeed)(uint64_t seed);

```

## Shuffle/Impl/Shuffle.impl

[Declarações e implementação](../../Codespace/Congro/Modules/Random/Shuffle/Impl/Shuffle.impl)

```c
void RANDOM_SHUFFLE_FUNC(Swap)(unsigned char *first, unsigned char *second, size_t size);

```
