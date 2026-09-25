# Congro;Library Documentation

This directory is the human-readable API reference for Congro;Library.

The reference follows the actual public headers in `Codespace/Congro`. Every
module page explains the API, gives usage examples, and shows both Congro's
semantic namespace-macro spelling and the ordinary C identifier produced by the
default namespace.

Start with **[Calling conventions](CALLING_CONVENTIONS.md)** if you are new to
forms such as:

```c
BIT_FUNC(32, Popcount)(flags);
Bit_32_Popcount(flags);
```

They are two spellings of the same function, not two implementations.

## API reference

| Area | Documentation | Contents |
| --- | --- | --- |
| Core | [Core](Core.md) | Namespace, OPSTATUS, comparison, memory, arenas, casting, panic, preprocessor utilities |
| Bit | [Bit](Bit.md) | Single bits, masks, popcount, bit indices, rotations, bit fields |
| Math | [Math](Math.md) | Checked arithmetic, clamp/saturation, range/value helpers, equations |
| Chronometry | [Chronometry](Chronometry.md) | Calendars, dates, durations, clocks, epochs, formatting, timers, timezones |
| Concurrency | [Concurrency](Concurrency.md) | Atomics, threads, sleep, synchronization, coroutines, tasks, futures, thread pools |
| Container | [Container](Container.md) | Vectors, strings, queues, stacks, linked structures, trees, hash maps, graphs |
| Network | [Network](Network.md) | Addresses, sockets, connections, listeners, datagrams, polling, resolution |
| Random | [Random](Random.md) | Entropy, deterministic engines, mixers, sources, distributions, shuffle |
| Struct | [Struct](Struct.md) | TPair, TDual, TTriple, TQuad, TPenta and conversions |
| Text | [Text](Text.md) | Unicode, UTF-8, UTF-16, display width, char/attribute/full grids |
| Type | [Type](Type.md) | Fundamental aliases, TBlock, TBigint, TDecimal |

## Source map

Congro is a modular C11 library with a header-oriented, single-header-style
architecture.

- Source root: `Codespace/Congro`
- Tests root: `Codespace/Tests`
- Public `.h` files define the API.
- `.impl` files are implementation pages included by public headers; users do
  not compile them as separate translation units.
- `.space` files define namespace/package configuration and shared declarations.
- Operational failures generally use `OPSTATUS`.
- Selected Container and Type APIs optionally provide pseudo-method/vtable
  ergonomics in addition to direct functions.
- Native backend details are kept behind portable APIs where practical.
- The project follows a zero-link philosophy: avoid mandatory user linker flags
  where viable.

## Module map

```text
Codespace/Congro/
├── Core/
│   ├── Algorithm/
│   ├── Cast/
│   ├── Error/
│   ├── Memory/
│   ├── Namespace.h
│   └── Preprocessor/
└── Modules/
    ├── Bit/
    ├── Chronometry/
    ├── Concurrency/
    ├── Container/
    │   ├── Array/
    │   ├── Linked/
    │   ├── Tree/
    │   ├── Hash/
    │   └── Graph/
    ├── Math/
    ├── Network/
    ├── Random/
    ├── Struct/
    ├── Text/
    └── Type/
```

Hash and Graph are part of the current main source tree and are documented under
[Container](Container.md).

## Build contract

Congro targets C11. On POSIX targets, native backends use interfaces gated by
POSIX feature-test macros. With strict C11 builds, define:

```text
-D_POSIX_C_SOURCE=200809L
```

on the compiler command line so it is present before the first system header.

## Project documents

- `README.md` — project overview
- `ROADMAP.md` — planned domains
- `Version.md` — change history
- `ENTROPY.md` — Entropy versioning
- `PATTERN.md` / repository pattern material — architecture and naming rules
- `LICENSING.md` — EUPL rationale
- `SECURITY.md` — vulnerability reporting
- `CODE_OF_CONDUCT.md` — community conduct
- `AUTHORS.md` — credits
- `llms.txt` — compact machine-oriented project map
- `CITATION.cff` — citation metadata

## Search terms

Congro Library, Congro C library, C11 library, header-oriented C, single-header
style C, portable systems programming C, generic containers C, C concurrency,
C networking, C sockets, Unicode C, text grid C, random C library, C
metaprogramming, C memory management, C data structures.
