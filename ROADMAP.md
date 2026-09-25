# Congro Roadmap

This roadmap tracks capabilities that appeared across earlier Congro/Teko generations
and are still absent from the current Congro-Library architecture.

The goal is not to restore old code mechanically. Each capability must be reconsidered
under the current Congro Pattern, C11 baseline, ownership rules, error model, namespace
system, single-header architecture, portability requirements, and zero-link goals.

## Current recovery work

- Hash — implemented in [PR #6](https://github.com/samucaoo1/Congro-Library/pull/6), pending merge.
- Graph — implemented in [PR #6](https://github.com/samucaoo1/Congro-Library/pull/6), pending merge.

## Roadmap

### 1. Foundation II

Issue: [#7 — File, Filesystem and Attributed Text](https://github.com/samucaoo1/Congro-Library/issues/7)

- [ ] File / Filesystem
  - [ ] Path
  - [ ] File lifecycle
  - [ ] Binary I/O
  - [ ] Text I/O
  - [ ] Directory and filesystem operations
- [ ] Attributed Text
  - [ ] Attributed string representation
  - [ ] Spans/ranges
  - [ ] Per-span style/attributes
  - [ ] Text Grid / TUI integration

### 2. Input

Issue: [#8 — Keyboard, Mouse and Events](https://github.com/samucaoo1/Congro-Library/issues/8)

- [ ] Keyboard
- [ ] Mouse
- [ ] Event representation
- [ ] Portable key/button vocabulary
- [ ] Terminal input backends
- [ ] Evaluate Gamepad / Controller as a later extension

### 3. Terminal Foundation

Issue: [#9 — Screen, Buffer, Cursor and Output](https://github.com/samucaoo1/Congro-Library/issues/9)

- [ ] Terminal lifecycle
- [ ] Screen
- [ ] Buffer
- [ ] Cursor
- [ ] Output
- [ ] Terminal dimensions
- [ ] Alternate screen
- [ ] Text Grid rendering
- [ ] Style/capability translation
- [ ] ANSI/POSIX backend
- [ ] Windows Console / VT backend

### 4. TUI

Issue: [#10 — Components, Layout, Events and Widgets](https://github.com/samucaoo1/Congro-Library/issues/10)

- [ ] Event
- [ ] Render
- [ ] Layout
- [ ] Focus
- [ ] Component
- [ ] Button
- [ ] CheckBox
- [ ] RadioButton
- [ ] ComboBox
- [ ] Edit
- [ ] Memo
- [ ] Menu
- [ ] ProgressBar
- [ ] SpinEdit
- [ ] Dialog
- [ ] Grid
- [ ] ASCII Image component
- [ ] SpeakBox / dialogue box
- [ ] Overlay / HUD primitives

### 5. Graphics

Issue: [#11 — Geometry, Transform, Canvas and Raster](https://github.com/samucaoo1/Congro-Library/issues/11)

- [ ] Geometry
  - [ ] Point
  - [ ] Line
  - [ ] Rectangle
  - [ ] Circle
  - [ ] Ellipse
  - [ ] Triangle
  - [ ] Polygon
- [ ] Transform
  - [ ] Translation
  - [ ] Scale
  - [ ] Rotation
  - [ ] Composition
- [ ] Canvas
- [ ] Raster
- [ ] Scanline fill
- [ ] Line styles
- [ ] Palette
- [ ] Gradients
- [ ] Text Grid rendering target

### 6. Immediate GUI

Issue: [#15 — Backend-Agnostic Immediate-Mode UI](https://github.com/samucaoo1/Congro-Library/issues/15)

A graphical immediate-mode UI layer inspired by the architectural role of Nuklear,
but implemented in Congro's own API, naming, memory and module conventions.

- [ ] Immediate-mode GUI context and frame lifecycle
- [ ] Minimal persistent state
- [ ] Explicit Input integration
- [ ] Renderer-independent draw-command output
- [ ] Styling / skinning
- [ ] Windows / panels
- [ ] Fixed and dynamic layouts
- [ ] Labels and text
- [ ] Buttons
- [ ] CheckBox / Radio / Option
- [ ] Slider / Progress
- [ ] Text editing
- [ ] ComboBox / Menu
- [ ] Tree / collapsible sections
- [ ] Tooltip
- [ ] Image
- [ ] Custom widget hook
- [ ] Software raster backend through Graphics
- [ ] Optional vertex-buffer output
- [ ] OpenGL example/backend
- [ ] Keep OS/window ownership outside the GUI core

The GUI and TUI are separate frontends. They may share lower-level types or concepts
where the abstraction is genuinely common, but neither should be implemented as a
special case of the other.

### 7. Text Art

Issue: [#12 — FIGlet and ASCII Image](https://github.com/samucaoo1/Congro-Library/issues/12)

- [ ] FIGlet font representation
- [ ] FIGlet parser
- [ ] FIGlet rendering
- [ ] Optional bundled/default font
- [ ] ASCII image conversion
- [ ] Luminance ramp
- [ ] Configurable palette
- [ ] Styled Text Grid output

### 8. Audio

Issue: [#13 — Synth, Music, MIDI and Output](https://github.com/samucaoo1/Congro-Library/issues/13)

- [ ] Audio core
  - [ ] Sample
  - [ ] Buffer
  - [ ] Format
  - [ ] Channels
  - [ ] Sample rate
- [ ] Wave generation
- [ ] Synth
- [ ] Music
- [ ] MIDI
- [ ] Output backends
  - [ ] Windows
  - [ ] Linux
  - [ ] macOS
- [ ] Investigate a zero-link output strategy

### 9. Compatibility Archaeology

Issue: [#14 — Debug and Native Interop](https://github.com/samucaoo1/Congro-Library/issues/14)

- [ ] Audit old Debug facilities against Panic / Stacktrace / Status
- [ ] Assertions
- [ ] Diagnostic helpers
- [ ] Debug-only helpers
- [ ] Object/container dump helpers
- [ ] Audit old native converters
- [ ] Decide which concepts belong in portable Congro types
- [ ] Keep backend-only concepts below the public API
- [ ] Add explicit Native escape hatches only where useful

## Dependency direction

The intended dependency direction is approximately:

```text
File / Filesystem
       |
       +----------------------+
       |                      |
       v                      v
Attributed Text           Text Art assets
       |
       v
    Text Grid
       |
       v
    Terminal <----------- Input
       |                   |
       v                   |
      TUI                  |
                           v
Graphics <------------ Immediate GUI
   |
   +------------------> Text Art

Audio remains mostly independent from this chain.
```

The Immediate GUI depends conceptually on Graphics and Input, while keeping OS/window
creation and concrete rendering backends outside the GUI core.

This ordering is architectural guidance, not a promise that every item must be
implemented strictly in sequence.

## Roadmap rules

- A roadmap item does not require recreating its historical implementation.
- Reuse current Congro foundations before introducing new abstractions.
- Public APIs follow the current Pattern, not historical naming by default.
- Native platform details stay below portable interfaces unless an explicit
  advanced interop escape hatch is justified.
- New modules/packages should exist because they communicate a real domain,
  not merely for directory symmetry.
- Completion of a roadmap item should include tests and portability review.
