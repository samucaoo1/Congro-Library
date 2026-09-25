# Congro Roadmap

This roadmap tracks capabilities that appeared across earlier Congro/Teko generations
and are still absent from the current Congro-Library architecture, together with
new architectural goals that fit the current direction of the project.

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
- [ ] Attributed Text

### 2. Input

Issue: [#8 — Keyboard, Mouse and Events](https://github.com/samucaoo1/Congro-Library/issues/8)

- [ ] Keyboard
- [ ] Mouse
- [ ] Events
- [ ] Portable key/button vocabulary
- [ ] Terminal input backends
- [ ] Evaluate Gamepad / Controller

### 3. Terminal Foundation

Issue: [#9 — Screen, Buffer, Cursor and Output](https://github.com/samucaoo1/Congro-Library/issues/9)

- [ ] Terminal lifecycle
- [ ] Screen
- [ ] Buffer
- [ ] Cursor
- [ ] Output
- [ ] Capabilities
- [ ] ANSI/POSIX backend
- [ ] Windows Console / VT backend

### 4. TUI

Issue: [#10 — Components, Layout, Events and Widgets](https://github.com/samucaoo1/Congro-Library/issues/10)

- [ ] Event
- [ ] Render
- [ ] Layout
- [ ] Focus
- [ ] Component
- [ ] Widget set
- [ ] SpeakBox / dialogue box
- [ ] Overlay / HUD primitives

### 5. Graphics

Issue: [#11 — Geometry, Transform, Canvas and Raster](https://github.com/samucaoo1/Congro-Library/issues/11)

- [ ] Geometry
- [ ] Transform
- [ ] Canvas
- [ ] Raster
- [ ] Scanline fill
- [ ] Line styles
- [ ] Palette
- [ ] Gradients
- [ ] Text Grid rendering target

### 6. Raycast

Issue: [#16 — 2D/3D Ray Queries and Intersection](https://github.com/samucaoo1/Congro-Library/issues/16)

- [ ] Ray2D / Ray3D
- [ ] Hit/intersection representation
- [ ] Primitive intersection tests
- [ ] Closest / first / any / all hit queries
- [ ] Maximum-distance queries
- [ ] Optional masks/layers
- [ ] Integration with Graphics / Geometry / Transform
- [ ] Immediate GUI picking support

### 7. Immediate GUI

Issue: [#15 — Backend-Agnostic Immediate-Mode UI](https://github.com/samucaoo1/Congro-Library/issues/15)

A graphical immediate-mode UI layer inspired by the architectural role of Nuklear,
but implemented in Congro's own API, naming, memory and module conventions.

- [ ] Immediate-mode GUI context and frame lifecycle
- [ ] Minimal persistent state
- [ ] Explicit Input integration
- [ ] Renderer-independent draw-command output
- [ ] Styling / skinning
- [ ] Windows / panels
- [ ] Layout
- [ ] Widget set
- [ ] Text editing
- [ ] Images
- [ ] Custom widget hook
- [ ] Software raster backend through Graphics
- [ ] Optional vertex-buffer output
- [ ] OpenGL example/backend
- [ ] Keep OS/window ownership outside the GUI core

The GUI and TUI are separate frontends.

### 8. Parsing

Issue: [#21 — Lexer, Tokens and Parser Helpers](https://github.com/samucaoo1/Congro-Library/issues/21)

- [ ] Source cursor
- [ ] Tokens and spans
- [ ] Line/column tracking
- [ ] Scanner helpers
- [ ] Token stream
- [ ] Expect / accept helpers
- [ ] Parse error location
- [ ] Reusable recursive-descent helpers

### 9. Serialization

Issue: [#17 — Data Formats and Structured I/O](https://github.com/samucaoo1/Congro-Library/issues/17)

- [ ] JSON
- [ ] CSV
- [ ] INI
- [ ] Evaluate TOML
- [ ] Base64
- [ ] Hex encoding
- [ ] Structured value representation where justified
- [ ] Pretty / compact serialization
- [ ] Error location reporting

### 10. CLI

Issue: [#18 — Arguments, Options and Subcommands](https://github.com/samucaoo1/Congro-Library/issues/18)

- [ ] Positional arguments
- [ ] Short/long options
- [ ] Flags
- [ ] Option values
- [ ] Repeated options
- [ ] Subcommands
- [ ] Help / usage generation
- [ ] Validation

### 11. Process and System

Issue: [#19 — Environment and Child Processes](https://github.com/samucaoo1/Congro-Library/issues/19)

- [ ] Environment variables
- [ ] Current working directory
- [ ] Hostname
- [ ] CPU count
- [ ] Process ID
- [ ] Executable path
- [ ] Spawn
- [ ] Wait
- [ ] Exit status
- [ ] Termination
- [ ] Standard stream redirection
- [ ] Pipes

### 12. Event Loop

Issue: [#20 — Reactor and Unified Event Dispatch](https://github.com/samucaoo1/Congro-Library/issues/20)

- [ ] Loop lifecycle
- [ ] Register/unregister source
- [ ] Callback dispatch
- [ ] Timers
- [ ] Socket readiness
- [ ] Wakeup mechanism
- [ ] Stop / drain semantics
- [ ] User-posted events/tasks
- [ ] Input / Terminal integration
- [ ] Optional Concurrency integration

### 13. Checksum and Digest

Issue: [#22 — Non-Cryptographic Integrity Algorithms](https://github.com/samucaoo1/Congro-Library/issues/22)

- [ ] CRC32
- [ ] Adler-32
- [ ] FNV-1 / FNV-1a
- [ ] Evaluate additional fast non-cryptographic hashes
- [ ] Incremental API
- [ ] One-shot API
- [ ] File/buffer helpers

### 14. UUID and Identifier

Issue: [#23 — Portable Identifier Utilities](https://github.com/samucaoo1/Congro-Library/issues/23)

- [ ] UUID type
- [ ] Parse / format
- [ ] Equality / comparison
- [ ] UUID v4
- [ ] UUID v7
- [ ] Nil UUID
- [ ] Compact identifier helpers

### 15. Compression and Archive

Issue: [#24 — Containers and Compression Formats](https://github.com/samucaoo1/Congro-Library/issues/24)

- [ ] TAR reader/writer
- [ ] Archive entry metadata
- [ ] Streaming extraction/creation
- [ ] Evaluate Deflate
- [ ] Evaluate ZIP
- [ ] Incremental compression/decompression
- [ ] Buffer/file helpers

### 16. Logging

Issue: [#25 — Structured Diagnostics and Sinks](https://github.com/samucaoo1/Congro-Library/issues/25)

- [ ] Log levels
- [ ] Logger/context
- [ ] Message formatting
- [ ] Timestamp integration
- [ ] Console/File/User sinks
- [ ] Multiple sinks
- [ ] Compile-time filtering
- [ ] Runtime filtering
- [ ] Optional thread safety

Logging remains separate from OPSTATUS/Error semantics.

### 17. Testing

Issue: [#26 — Congro Test Utilities](https://github.com/samucaoo1/Congro-Library/issues/26)

- [ ] Assertion helpers
- [ ] Equality/status helpers
- [ ] Test runner
- [ ] Setup/teardown
- [ ] Expected failure helpers
- [ ] Reporting
- [ ] Optional timing
- [ ] Optional property-style helpers later

### 18. Text Art

Issue: [#12 — FIGlet and ASCII Image](https://github.com/samucaoo1/Congro-Library/issues/12)

- [ ] FIGlet font representation
- [ ] FIGlet parser
- [ ] FIGlet rendering
- [ ] ASCII image conversion
- [ ] Luminance ramp
- [ ] Configurable palette
- [ ] Styled Text Grid output

### 19. Audio

Issue: [#13 — Synth, Music, MIDI and Output](https://github.com/samucaoo1/Congro-Library/issues/13)

- [ ] Audio core
- [ ] Wave generation
- [ ] Synth
- [ ] Music
- [ ] MIDI
- [ ] Output backends
- [ ] Investigate a zero-link output strategy

### 20. Compatibility Archaeology

Issue: [#14 — Debug and Native Interop](https://github.com/samucaoo1/Congro-Library/issues/14)

- [ ] Audit old Debug facilities
- [ ] Assertions / diagnostics gaps
- [ ] Object/container dump helpers
- [ ] Audit old native converters
- [ ] Portable type replacements
- [ ] Backend-only native concepts
- [ ] Explicit Native escape hatches where useful

## Dependency direction

The intended dependency direction is approximately:

```text
                         File / Filesystem
                           /      |      \
                          v       v       v
                     Parsing  Logging  Archive/Compression
                        |
                        v
                  Serialization

Input ----------------------+
  |                         |
  v                         v
Terminal                Event Loop <------ Chronometry / Network
  |                         |
  v                         |
 TUI                        |
                            v
Graphics <------------ Immediate GUI
  |  \                    /
  |   \                  /
  |    v                /
  |  Raycast <---------+
  |
  +------------------> Text Art

Random + Chronometry ------> UUID / Identifier

File / Network -----------> Checksum / Digest

Process / System ---------> CLI and Event Loop integration

Testing supports every domain but is not a runtime dependency.

Audio remains mostly independent from this chain.
```

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
