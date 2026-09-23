# Congro;Library 
[Changelog](Version.md)&nbsp;|&nbsp;[Why EUPL?](LICENSING.md)&nbsp;|&nbsp;[Code of Conduct](CODE_OF_CONDUCT.md)&nbsp;|&nbsp;[Credits](AUTHORS.md)&nbsp;|&nbsp;[Português (Brasil)](Translations/Portugues-Brasil/README(PT-BR).md)  
<pre>

A library for curious minds exploring beyond the expected path.

$ congro --about

Congro;Library
A modular and flexible library for curious minds.

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


Or, when published:

$ brew install congro

$ yay(or paru) -S congro

> Quick Test

Congro_Experiment();

Output:

[Congro] Initializing experiment...
[Congro] Loading modules...
[Congro] Running...
[Congro] Done.

> Architecture

Congro is built around independent modules that can be combined according to the needs 
of your project.

congro/
│
├── Core/          # Fundamental components
├── Modules/       # Modular functionality
├── Assets/        # Assets
└── ...


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

API:        ██░░░░░░░░ 20%
Stability:  █████░░░░░ 50%
Docs:       ░░░░░░░░░░ 0%
Curiosity:  ██████████ 100%


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

By participating in the project, you agree to follow the [Code of Conduct](CODE_OF_CONDUCT.md).

> Credits
Congro;Library was created by [Samuel (okarin)](https://github.com/samucaoo1). See [AUTHORS.md](AUTHORS.md) for project authorship and contributor credits.

> License
Congro;Library is licensed under the European Union Public Licence, Version 1.2 only (EUPL-1.2).

See [Why EUPL?](LICENSING.md) for the project's licensing rationale.

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
<pre>
