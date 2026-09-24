# Entropy Versioning

Congro;Library uses **Entropy** as a measure of accumulated change to the library.

> **Entropy measures accumulated change, not code size.**

The public form is:

```text
Entropy: 18800β
```

The number is the absolute accumulated entropy in **H**. The Greek suffix identifies the entropy band.

## Scope

Only tracked files under:

```text
Codespace/Congro/**
```

contribute to Entropy.

Tests, documentation, translations, CI configuration, badges, and repository metadata do not affect the value.

## Initial Release

The first canonical release establishes the immutable Git tag:

```text
entropy-origin
```

Every tracked line that exists in `Codespace/Congro/**` at that point contributes exactly **1 H** to the initial value:

```text
H₀ = lines in Codespace/Congro/** at entropy-origin
```

The history that existed before this point is intentionally not reconstructed. The Initial Release is treated as the initial state of the public entropy system.

## Changes after the origin

For every commit on the canonical first-parent history:

```text
ΔH = additions + deletions
Hₙ = H₀ + ΣΔH
```

Therefore:

```text
added line      = +1 H
deleted line    = +1 H
rewritten line  = +2 H
```

A rewritten line contributes twice because Git represents its transition as one removed state and one introduced state.

A refactor may reduce the number of lines in the library while still increasing Entropy.

## Historical, not merely textual

Entropy is accumulated commit by commit. It is not calculated only from the final difference between the origin and the current tree.

For example, changing a line and later restoring its original text still increases Entropy twice. The final source may match its original state, but the library has passed through additional states.

The canonical calculation follows the **first-parent history**. This makes squash-merged pull requests count the change that actually entered the main line rather than internal branch history.

## Greek bands

Each **10,000 H** selects a Greek band:

```text
0–9,999 H          α
10,000–19,999 H    β
20,000–29,999 H    γ
...
230,000–239,999 H  ω
```

After `ω`, the symbols continue like spreadsheet columns, using a bijective base-24 alphabet:

```text
ω → αα → αβ → αγ → ... → αω → βα → ...
```

The absolute number never resets.

## Reproducibility

The implementation lives in:

```text
.github/entropy/entropy.py
```

It derives the baseline from `entropy-origin` and sums `git diff --numstat` additions and deletions for each first-parent commit.

`.gitattributes` fixes line endings for `Codespace/Congro/**` to LF so that CRLF/LF conversions cannot artificially inflate Entropy.

The algorithm has automated tests for:

- the initial snapshot;
- additions and deletions;
- rewrites counting as 2 H;
- changes outside the source scope;
- new and deleted files;
- renames without textual changes;
- change-then-revert history;
- Greek-band rollover through `ω → αα`;
- the public `18800β`-style display format.

## Live badge

The README badge is generated automatically after source changes land on `main`.

The workflow stores the rendered badge and machine-readable state directly under `.github/` on `main`. These generated files are outside `Codespace/Congro/**`, so updating them does not change Entropy. Generated-state commits use `[skip ci]` and do not retrigger the Entropy workflow.

The machine-readable state contains the origin commit, current commit, initial entropy, accumulated change, absolute total, Greek band, and unit.
