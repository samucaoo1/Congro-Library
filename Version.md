<pre>
Version Explanation:

X.Y.Z.W

X → Major Update (New Module)

Y → Minor Update (New Item)

Z → Major Fix (New Item) and/or Correction

W → Minor Fix (Correction)

===================================================
=       Unreleased - "Pattern Consolidation"       =
===================================================
Breaking changes:
+ Memory_Free now receives the pointer lvalue instead of its address.
+ Typed allocation callers publish converted pointers only after SUCCESS.
+ Math typed specializations use a separate suffix component (e.g. *_F32).
+ Math and Network constants use the UPPER_SNAKE_CASE constant renderer.
+ Container generated public typedefs use the T type marker.
+ Container instance generators use *_INSTANCE_DECLARE; legacy T* declaration
  macros remain compatibility aliases during migration.
+ Concurrency Try* APIs separate OPSTATUS from the acquired/submitted outcome.
+ Random Source owns a correctly aligned, typed engine-state allocation.
+ Network package namespaces no longer use *_MOD names reserved for modules.
+ Socket prototype macros no longer use the legacy FUNCTION_* prefix.
+ Network fallible APIs return OPSTATUS and expose TNetwork_Error explicitly
  in the same call; lastError remains observational state only.
+ Public parameters, locals and members follow lowerCamelCase.
+ POSIX strict-C11 builds require _POSIX_C_SOURCE=200809L at compile time.

Validation:
+ Full repository CI: Linux GCC, Linux Clang, macOS Clang, Windows MinGW, Windows MSVC.
===================================================

===================================================
=        Version 9.0.0 - "Divergence"             =
===================================================
Module:
+ Concurrency

Packages:
+ Atomic
+ Coroutine
+ Synchronization
+ Task
+ Thread

Validation:
+ Linux GCC and Clang
+ macOS Clang
+ Windows MinGW and MSVC
+ ThreadSanitizer coverage on Linux
===================================================

===================================================
=          Version 8.0.0 - "RINE"                 =
===================================================
Module:
+ Network

Package:
+ Address
+ Connection
+ Datagram
+ Listener
+ Poll
+ Socket

===================================================

====================================================
=          Version 7.0.0 - "Gadget Lab"            =
====================================================
Module:
+ Container
Package:
+ Flat
+ Linked
+ Tree
===================================================

===================================================
=         Version 6.0.0 - "Chaos Theory"          =
===================================================
Module:
+ Random
Package:
+ Engine
+ Entropy
+ Mixer
+ Source
+ Distribution
+ Shuffle  
====================================================

====================================================
=          Version 5.0.0 - "Time Machine"          =
====================================================
Modules:
+ Chronometry
+ Thread

Chronometry Packages:
+ Calendar
+ Clock
+ DateTime
+ Duration
+ Epoch
+ Format
+ Instant
+ Timer
+ Timezone

Chronometry Items:
+ Calendar systems and historical reforms
+ Civil Date and DateTime
+ Monotonic Clock and ClockTimePoint
+ Signed Duration
+ Timer, Delta and FrameLimiter
+ Absolute Instant
+ Unix, Julian Day and Rata Die epochs
+ ISO formatting and parsing
+ UTC offset conversion

Thread Items:
+ SleepFor
+ SleepUntil
+ Yield

Notes:
+ Chronometry is independent from Time
+ Thread depends on Chronometry
+ Time remains available as a legacy module
+ C11 compatible
===================================================

===================================================
=          Version 4.0.0 - "World Line"           =
===================================================
Module:
+ Math
Package:
+ Arthmetic
+ Equation
+ Value
===================================================

===================================================
=       Version 3.0.0 - "Reading Steiner"         =
===================================================
Modules : Bit
Package:
+ Bit

Modules : Type
Package:
+ Fundamental
+ TBigint
+ TBlock
+ TDecimal
===================================================

===================================================
=        Version 2.1.1 - "Divergence Meter"       =
===================================================
Module: Struct
Added "array like"(.value[]) interaction in
Package:
+ TDual
+ TPair
+ TTriple
+ TQuad
+ TPenta
===================================================

===================================================
=        Version 2.1.0 - "Divergence Meter"       =
===================================================
Module: Struct
Package:
+ TPenta
===================================================

===================================================
=        Version 2.0.0 - "Divergence Meter"       =
===================================================
Module: Struct
Package:
+ TDual
+ TPair
+ TTriple
+ TQuad
===================================================

===================================================
=        Version 1.0.0 - "Attractor Field"        =
===================================================
Module: Core
Package:
+ Algorithm
+ Cast
+ Error
+ Memory
+ Preprocessor
===================================================

===================================================
= Version 0.2.0.0 - "The Library has a beginning" =
===================================================

+ Readme Links

===================================================

===================================================
= Version 0.1.1.2 - "The Library has a beginning" =
===================================================

+ "pre" tag to fix format

===================================================

===================================================
= Version 0.1.1.1 - "The Library has a beginning" =
===================================================

+ Version Explanation 

===================================================

===================================================
=  Version 0.1.0 - "The Library has a beginning"  =
===================================================

[Road map]:

  [x]Readme 
  [x]Version
  [x]Licence
  [x]Readme(PT-BR)

===================================================
</pre>