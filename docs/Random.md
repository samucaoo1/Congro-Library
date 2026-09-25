# Random

Random combines OS/system entropy, deterministic engines, mixers, reusable
sources, distributions, and safe generic shuffling.

**Root:** `Codespace/Congro/Modules/Random`

## Convenience random functions

**Header:** `Random.h`

| Indirect | Direct | Meaning |
| --- | --- | --- |
| `RANDOM_FUNC(U64)()` | `Random_U64()` | Collects a non-cryptographic random 64-bit value from the entropy subsystem. |
| `RANDOM_FUNC(U64_FromSeed)(seed)` | `Random_U64_FromSeed(seed)` | Deterministic Xoshiro-derived value. |
| `RANDOM_FUNC(RangeU64)(min,max)` | `Random_RangeU64(min,max)` | Uniform unsigned range. |
| `RANDOM_FUNC(RangeI64)(min,max)` | `Random_RangeI64(min,max)` | Uniform signed range. |
| `RANDOM_FUNC(F64)()` | `Random_F64()` | Double in the generator's unit interval construction. |
| `RANDOM_FUNC(Bool)()` | `Random_Bool()` | Random boolean. |

If minimum and maximum are supplied in reverse order, the integer distributions
normalize their order.

Example:

```c
uint64_t die = RANDOM_FUNC(RangeU64)(1, 6);
bool coin = RANDOM_FUNC(Bool)();
```

Direct:

```c
uint64_t die = Random_RangeU64(1, 6);
bool coin = Random_Bool();
```

These APIs are not advertised as cryptographically secure.

## Engines

**Directory:** `Engine`

Available stateful engines:

`Lcg`, `Pcg`, `Romu`, `Sfc`, `Splitmix`, `WyRand`, `Xoroshiro`,
and `Xoshiro`.

Every engine follows the same basic pair:

```c
RANDOM_ENGINE_FUNC(Xoshiro, Seed)(&state, seed);
uint64_t x = RANDOM_ENGINE_FUNC(Xoshiro, Next)(&state);
```

Direct:

```c
Random_Engine_Xoshiro_Seed(&state, seed);
uint64_t x = Random_Engine_Xoshiro_Next(&state);
```

Each engine also exposes a generated vtable object, e.g.
`Random_Engine_Xoshiro_VTable`, containing state size/alignment, `nextU64`,
and `seed` callbacks. This lets `TRandomSource` operate over engines
uniformly.

## Source

**Header:** `Source/Source.h`

`TRandomSource` owns or references an engine state and optionally applies a
mixer.

| Indirect | Direct |
| --- | --- |
| `RANDOM_SOURCE_FUNC(Init)(&s,engine,seed,mixer)` | `Random_Source_Init(...)` |
| `RANDOM_SOURCE_FUNC(InitWithState)(...)` | `Random_Source_InitWithState(...)` |
| `RANDOM_SOURCE_FUNC(InitSystem)(&s,engine,mixer)` | `Random_Source_InitSystem(...)` |
| `RANDOM_SOURCE_FUNC(Reseed)(&s,seed)` | `Random_Source_Reseed(...)` |
| `RANDOM_SOURCE_FUNC(NextU64)(&s)` | `Random_Source_NextU64(&s)` |
| `RANDOM_SOURCE_FUNC(Destroy)(&s)` | `Random_Source_Destroy(&s)` |

Example:

```c
TRandomSource source = {0};

RANDOM_SOURCE_FUNC(Init)(
    &source,
    &RANDOM_ENGINE_FUNC(Pcg, VTable),
    42,
    RANDOM_MIXER_FUNC(Splitmix64));

uint64_t value = RANDOM_SOURCE_FUNC(NextU64)(&source);
RANDOM_SOURCE_FUNC(Destroy)(&source);
```

Direct symbols include `Random_Source_Init`,
`Random_Engine_Pcg_VTable`, `Random_Mixer_Splitmix64`, and
`Random_Source_NextU64`.

## Distributions

**Directory:** `Distribution`

- `RANDOM_DISTRIBUTION_FUNC(Bool)(&source)` → `Random_Distribution_Bool`
- `RANDOM_DISTRIBUTION_FUNC(U64)(&source,min,max)` → `Random_Distribution_U64`
- `RANDOM_DISTRIBUTION_FUNC(I64)(&source,min,max)` → `Random_Distribution_I64`
- `RANDOM_DISTRIBUTION_FUNC(F64)(&source)` → `Random_Distribution_F64`

The integer distribution uses rejection to avoid simple modulo bias.

## Mixers

**Header:** `Mixer/Mixer.h`

All mixers accept and return `uint64_t`.

| Indirect | Direct |
| --- | --- |
| `RANDOM_MIXER_FUNC(Jenkins)(x)` | `Random_Mixer_Jenkins(x)` |
| `RANDOM_MIXER_FUNC(Knuth)(x)` | `Random_Mixer_Knuth(x)` |
| `RANDOM_MIXER_FUNC(Murmur3)(x)` | `Random_Mixer_Murmur3(x)` |
| `RANDOM_MIXER_FUNC(Splitmix64)(x)` | `Random_Mixer_Splitmix64(x)` |
| `RANDOM_MIXER_FUNC(Stafford)(x)` | `Random_Mixer_Stafford(x)` |
| `RANDOM_MIXER_FUNC(Wang)(x)` | `Random_Mixer_Wang(x)` |
| `RANDOM_MIXER_FUNC(WyHash)(x)` | `Random_Mixer_WyHash(x)` |
| `RANDOM_MIXER_FUNC(Xorshift)(x)` | `Random_Mixer_Xorshift(x)` |

## Entropy

**Directory:** `Entropy`

Public entropy sources:

- `RANDOM_ENTROPY_FUNC(System)(dst,size)` → `Random_Entropy_System`
- `Address`, `Clock`, `Jitter`, `Thread`, `Time`
- `Collect` combines entropy inputs into a 64-bit value.

Entropy pool:

- `RANDOM_ENTROPY_FUNC(Pool_Init)`
- `Pool_Add`
- `Pool_Finalize`

Direct family: `Random_Entropy_Pool_Init`, etc.

## Shuffle

**Header:** `Shuffle/Shuffle.h`

```c
int values[] = {1, 2, 3, 4, 5};

RANDOM_SHUFFLE_FUNC(Vector)(
    values, sizeof(values) / sizeof(values[0]), sizeof(values[0]));
```

Direct:

```c
Random_Shuffle_Vector(
    values, sizeof(values) / sizeof(values[0]), sizeof(values[0]));
```

For deterministic/reusable random state:

```c
RANDOM_SHUFFLE_FUNC(VectorFromSource)(
    values, count, sizeof(values[0]), &source);
```

Direct: `Random_Shuffle_VectorFromSource(...)`.

The implementation validates null pointers, element size, size multiplication,
and address-range overflow before shuffling.
