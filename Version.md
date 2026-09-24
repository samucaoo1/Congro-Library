# Congro;Library — Release Log

Congro;Library does **not** use semantic versioning.

Public releases are identified by the library's accumulated **Entropy**.

```text
Entropy: 18866β
```

The numeric value is the absolute accumulated entropy in **H**. The Greek
suffix identifies the current entropy band.

For the complete definition, calculation rules, scope, and reproducibility
model, see [ENTROPY.md](ENTROPY.md).

---

## Initial Release — 18866β

**Entropy:** 18866 H  
**Band:** β  
**Release:** Initial Release

This is the first public release of Congro;Library.

Earlier internal development versions are intentionally not part of the public
release history. The library begins its public version history from this source
state.

When this release is published, its source snapshot establishes the
`entropy-origin` reference. The complete contents of `Codespace/Congro/**`
at that point form the initial entropy value `H₀`.

### Included modules

- Bit
- Chronometry
- Concurrency
- Container
- Math
- Network
- Random
- Struct
- Text
- Type

### Core

- Algorithm
- Cast
- Error
- Memory
- Namespace
- Preprocessor

### Release validation

The Initial Release is validated on:

- Linux / GCC
- Linux / Clang
- Linux / GCC 32-bit
- macOS / Clang
- Windows / MinGW
- Windows / MSVC
- AddressSanitizer + UndefinedBehaviorSanitizer
- ThreadSanitizer
- standalone public-header compilation with GCC and Clang
- multi-translation-unit tests
- Entropy algorithm and history tests

---

## Release numbering from now on

There are no `1.0.0`, `1.1.0`, or `2.0.0` releases.

A future release is named by the entropy state at which it is published.

For example:

```text
18866β  Initial Release
19124β  future release
20037γ  later release
```

The absolute entropy number never resets. Crossing a 10,000 H boundary changes
the Greek band:

```text
0–9,999 H          α
10,000–19,999 H    β
20,000–29,999 H    γ
...
230,000–239,999 H  ω
```

After `ω`, the suffix continues as a bijective base-24 Greek alphabet:

```text
ω → αα → αβ → αγ → ... → αω → βα → ...
```

A release therefore records a **state of accumulated change**, rather than an
arbitrary major/minor/patch number.

> Every release has a history. Congro measures how much history accumulated.
