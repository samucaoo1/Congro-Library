# Congro;Library Technical Index

Congro;Library is a modular C11 library with a header-oriented, single-header-style
architecture. This index exists to make the repository easier to navigate for humans,
search engines, documentation systems, and code-reading agents.

## Canonical repository

- Repository: https://github.com/samucaoo1/Congro-Library
- Language baseline: C11
- License: EUPL-1.2-only
- Status: experimental / active development
- Source root: `Codespace/Congro`
- Tests root: `Codespace/Tests`

## Design characteristics

- Modular C library
- Header-oriented architecture
- `.impl` files are implementation pages included by public headers
- `.space` files define namespace/package-level configuration and common declarations
- Explicit ownership and error handling
- `OPSTATUS` for operational failures
- Optional pseudo-method/vtable ergonomics in selected modules
- Portable API surfaces with native backend details kept internal where practical
- Zero-link philosophy: avoid mandatory user linker flags where viable

## Core

### Algorithm
Comparison and low-level reusable algorithms.

Path: `Codespace/Congro/Core/Algorithm`

### Cast
Explicit conversion helpers.

Path: `Codespace/Congro/Core/Cast`

### Error
Status codes, panic facilities, and stack traces.

Path: `Codespace/Congro/Core/Error`

### Memory
Allocation, arena, memory operations, and memory utilities.

Path: `Codespace/Congro/Core/Memory`

### Namespace
Namespace and symbol-prefix composition.

Path: `Codespace/Congro/Core/Namespace.h`

### Preprocessor
Macro metaprogramming, argument counting, boolean logic, compiler/OS/processor
detection, foreach/map/repeat/sequence helpers, token operations, and evaluation.

Path: `Codespace/Congro/Core/Preprocessor`

## Modules

### Bit
Bit manipulation and integer bit utilities.

Path: `Codespace/Congro/Modules/Bit`

### Chronometry
Time-related abstractions including calendars, clocks, dates, durations, epochs,
instants, timers, formatting, and time zones.

Path: `Codespace/Congro/Modules/Chronometry`

### Concurrency
Atomics, threads, sleep, synchronization primitives, coroutines, barriers,
conditions, mutexes, once initialization, reader/writer locks, semaphores,
tasks, futures, and thread pools.

Path: `Codespace/Congro/Modules/Concurrency`

### Container
Generic container structures including vectors, strings, queues, stacks,
linked structures, and trees. Hash and Graph development is tracked separately
until merged into the main branch.

Path: `Codespace/Congro/Modules/Container`

### Math
Arithmetic helpers, clamps/ranges, min/max and equation utilities.

Path: `Codespace/Congro/Modules/Math`

### Network
Portable networking abstractions for addresses, sockets, connections,
listeners, datagrams, polling, runtime setup, errors, and name resolution.

Path: `Codespace/Congro/Modules/Network`

### Random
Entropy sources, deterministic engines, mixers, distributions, seeds,
random values, and shuffle operations.

Path: `Codespace/Congro/Modules/Random`

### Struct
Reusable typed structures such as pairs and fixed-size tuple-like groups.

Path: `Codespace/Congro/Modules/Struct`

### Text
Text encoding and Unicode facilities, including UTF-8, UTF-16, Unicode code
points/width, character grids, attribute grids, and text-grid types.

Path: `Codespace/Congro/Modules/Text`

### Type
Fundamental typed operations plus extended numeric/value types.

Path: `Codespace/Congro/Modules/Type`

## Project documentation

- `README.md` — project overview and entry point
- `ROADMAP.md` — planned domains and architectural direction
- `Version.md` — changelog/history
- `ENTROPY.md` — Entropy versioning model
- `LICENSING.md` — EUPL licensing rationale
- `SECURITY.md` — vulnerability reporting
- `CODE_OF_CONDUCT.md` — community conduct
- `AUTHORS.md` — authorship and contributor credits
- `PATTERN.md` — coding and architecture conventions
- `llms.txt` — concise machine-oriented project map
- `CITATION.cff` — canonical project citation metadata

## Roadmap domains

Planned work includes File/Filesystem, Attributed Text, Input, Terminal, TUI,
Graphics, Raycast, Immediate GUI, Parsing, Serialization, CLI, Process/System,
Event Loop, Checksum/Digest, UUID/Identifier, Compression/Archive, Logging,
Testing utilities, Text Art, Audio, and compatibility/native interop audits.

See `ROADMAP.md` and the linked GitHub issues for scope.

## Search terms

Congro Library, Congro C library, C11 library, header-only C, single-header C,
portable C library, systems programming C, generic containers C, C concurrency,
C networking library, C sockets, C Unicode, C text grid, C random library,
C metaprogramming, C memory management, C data structures, educational C library.
