# Congro;Library

**Congro;Library is a modular C11 library for portable systems programming, education,
experimentation, and reusable low-level components.** It follows a header-oriented
single-header style, emphasizes readable APIs and explicit ownership, and currently
includes utilities for memory, preprocessing, containers, concurrency, networking,
chronometry, random generation, mathematics, text/Unicode, bit operations, generic
types, and reusable structures.

**Keywords:** C11, C library, header-only C, single-header library, systems programming,
portable C, containers, concurrency, networking, sockets, random number generation,
Unicode, text processing, mathematics, memory management, metaprogramming, generic C.

[Changelog](Version.md)&nbsp;|&nbsp;[Roadmap](ROADMAP.md)&nbsp;|&nbsp;[Technical Index](docs/INDEX.md)&nbsp;|&nbsp;[Entropy](ENTROPY.md)&nbsp;|&nbsp;[Why EUPL?](LICENSING.md)&nbsp;|&nbsp;[Code of Conduct](CODE_OF_CONDUCT.md)&nbsp;|&nbsp;[Credits](AUTHORS.md)&nbsp;|&nbsp;[Português (Brasil)](Translations/Portugues-Brasil/README(PT-BR).md)&nbsp;|&nbsp;[Español (Latinoamérica)](Translations/Espanol-LATAM/README(ES-LATAM).md)

[![Entropy](.github/badges/entropy.svg)](ENTROPY.md)

## What is Congro?

Congro is an experimental modular C11 library designed around readable source code,
small composable modules, consistent naming, explicit error handling, and portability.
It is intended both as a practical library and as code that can be studied.

The current source tree contains:

- **Core:** Algorithm, Cast, Error, Memory, Namespace, and Preprocessor facilities.
- **Bit:** bit manipulation and low-level integer helpers.
- **Chronometry:** calendars, clocks, dates, durations, epochs, instants, timers, and time zones.
- **Concurrency:** atomics, threads, synchronization, coroutines, futures/tasks, and thread pools.
- **Container:** arrays, strings, vectors, queues, stacks, linked structures, trees, and related generic containers.
- **Math:** arithmetic, ranges/clamps, values, and equation helpers.
- **Network:** addresses, sockets, connections, listeners, datagrams, polling, and name resolution.
- **Random:** entropy sources, engines, distributions, mixers, and shuffle utilities.
- **Struct:** typed pair/tuple-like structures such as TDual, TPair, TTriple, TQuad, and TPenta.
- **Text:** UTF-8/UTF-16 encoding, Unicode code points/width, and text grids.
- **Type:** fundamental typed operations and extended numeric/value types.

For a compact machine- and human-readable map of the repository, see
[docs/INDEX.md](docs/INDEX.md). Future domains are tracked in [ROADMAP.md](ROADMAP.md).

<pre>
A library for curious minds exploring beyond the expected path.

$ congro --about

Congro;Library
A modular and flexible C11 library for curious minds.

Designed to be:
    [✓] Educational
    [✓] Readable
    [✓] Standardized
    [✓] Modular
    [✓] Flexible

Built for programmers of all skill levels.

> Why Congro?
$ congro --why

Programming shouldn't feel like deciphering ancient code.

Congro is designed around a simple idea:

    readable code
        +
    modular architecture
        +
    educational design
        =
    software worth understanding

Whether you're experimenting, learning, prototyping, or building something serious,
Congro aims to keep the internals understandable without sacrificing flexibility.

> Philosophy
$ congro --philosophy

┌──────────────────────────────────────────┐
│  > EDUCATIONAL                           │
│  Learn from the code, not around it.     │
├──────────────────────────────────────────┤
│  > READABLE                              │
│  Clear abstractions. Clear intentions.   │
├──────────────────────────────────────────┤
│  > STANDARDIZED                          │
│  Consistent interfaces and conventions.  │
├──────────────────────────────────────────┤
│  > MODULAR                               │
│  Small pieces. Composable systems.       │
├──────────────────────────────────────────┤
│  > FLEXIBLE                              │
│  Adapt Congro to your experiment.        │
└──────────────────────────────────────────┘

> C11 / POSIX build contract

On POSIX targets, Congro's native backends use interfaces gated by POSIX feature-test
macros. With strict C11 builds, define `_POSIX_C_SOURCE=200809L` in the compiler
command line (for example `-D_POSIX_C_SOURCE=200809L`). It must be defined before
the first system header is parsed; Congro therefore does not try to define it from
inside a public header. This makes include order deterministic, including programs
that include libc headers before Congro.

> Installation
$ git clone https://github.com/samucaoo1/Congro-Library.git

> Architecture

Congro is built around independent modules that can be combined according to the needs
of your project.

Codespace/Congro/
│
├── Core/          # Fundamental components
└── Modules/       # Modular functionality

The goal is to make each part of the library understandable on its own.

┌─────────────┐
│    Core     │
└──────┬──────┘
       │
       ├──────────────┐
       ▼              ▼
┌─────────────┐ ┌─────────────┐
│   Module A  │ │   Module B  │
└──────┬──────┘ └──────┬──────┘
       │               │
       └───────┬───────┘
               ▼
        ┌─────────────┐
        │ Experiment  │
        └─────────────┘

> Design Goals
[01] Keep abstractions understandable.
[02] Prefer composition over unnecessary complexity.
[03] Make modules independently useful.
[04] Keep APIs consistent.
[05] Make learning part of the development process.
[06] Allow experimentation without fighting the library.

> Status
$ congro --status

Project status: EXPERIMENTAL

⚠️ Congro is currently under active development. APIs may change.

> Contributing

Got an experiment?
Got a weird idea?
Found something that could be clearer?

$ git clone <repository>
$ git checkout -b experiment/my-idea
$ make your-changes
$ git commit -m "feat: my contribution"
$ git push

Contributions, experiments, improvements, and constructive criticism are welcome.

By participating in the project, you agree to follow the Code of Conduct.

> Credits
Congro;Library was created by Samuel (okarin).

> License
Congro;Library is licensed under the European Union Public Licence, Version 1.2 only
(EUPL-1.2).

> Final Message
$ congro --message

┌────────────────────────────────────────────┐
│                                            │
│   "Stay curious. Break things. Learn."     │
│                                            │
│                 — Congro                   │
│                                            │
└────────────────────────────────────────────┘

Congro;Library — A library for curious minds exploring beyond the expected path.
</pre>
