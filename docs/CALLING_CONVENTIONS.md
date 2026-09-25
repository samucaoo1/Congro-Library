# Calling conventions and namespace expansion

This page explains the two forms used throughout the Congro;Library documentation.

Congro exposes semantic namespace macros such as `BIT_FUNC`, `MATH_TYPED_FUNC`,
`THREAD_FUNC`, and `TEXT_UTF8_NS`. Those macros expand to ordinary C identifiers.
The documentation always shows both forms.

## The two call forms

### Indirect / namespace-macro form

This is the form that expresses the API hierarchy through the module's naming macro:

```c
uint32_t flags = 0xF0u;
uint64_t count = BIT_FUNC(32, Popcount)(flags);
```

### Direct / expanded symbol form

With the default namespace configuration, the same call is:

```c
uint32_t flags = 0xF0u;
uint64_t count = Bit_32_Popcount(flags);
```

The direct spelling is not a second implementation. Both forms name the same
`static inline` function.

## Custom library namespace

`Codespace/Congro/Core/Namespace.h` defines `LIB_PREFIX` from
`CONGRO_NAMESPACE`. If no custom namespace is defined, a symbol such as:

```c
BIT_FUNC(32, Popcount)
```

expands to:

```text
Bit_32_Popcount
```

If the translation unit defines:

```c
#define CONGRO_NAMESPACE MyProject
```

before including Congro headers, the same semantic name expands to:

```text
MyProject_Bit_32_Popcount
```

For readability, module pages write the default direct symbol. Read
`[namespace_]Foo_Bar` as “the default symbol `Foo_Bar`, optionally prefixed by
`CONGRO_NAMESPACE` and an underscore”.

Constants follow the same hierarchy through `CONGRO_NAMESPACE_CONST`, but keep
the library's constant grammar.

## How to read the API tables

Each operation is documented with:

| Column | Meaning |
| --- | --- |
| Indirect | The semantic macro spelling used by the module. |
| Direct | The default expanded C identifier. |
| Return | The result type and the meaning of important return values. |
| Notes | Ownership, ranges, invalid input, or other behavioral details. |

Example:

| Indirect | Direct | Return | Notes |
| --- | --- | --- | --- |
| `BIT_FUNC(32, Popcount)(value)` | `Bit_32_Popcount(value)` | `uint64_t` | Counts set bits in a `uint32_t`. |

## OPSTATUS

Operational functions commonly return `OPSTATUS`. The success constant is:

```c
STATUS_CONST(SUCCESS)
```

which expands, under the default constant namespace, to:

```c
CONGRO_STATUS_SUCCESS
```

Typical use:

```c
int32_t result = 0;

OPSTATUS status = ARITHMETIC_TYPED_FUNC(Add, I32)(20, 22, &result);

if (status == STATUS_CONST(SUCCESS)) {
    /* result == 42 */
}
```

Direct form:

```c
int32_t result = 0;

OPSTATUS status = Math_Arithmetic_Add_I32(20, 22, &result);

if (status == CONGRO_STATUS_SUCCESS) {
    /* result == 42 */
}
```

The current status set includes success, generic error, invalid argument,
out-of-range, out-of-memory, not-found, already-exists, not-supported,
not-available, busy, would-block, timeout, cancelled, arithmetic overflow, and
division-by-zero.

## Output parameters

Congro prefers explicit output parameters for fallible operations:

```c
CHRONOMETRY_TYPE(Duration) elapsed;

OPSTATUS status =
    TIMER_FUNC(Elapsed)(&timer, &elapsed);
```

Direct form:

```c
Chronometry_Duration elapsed;

OPSTATUS status =
    Chronometry_Timer_Elapsed(&timer, &elapsed);
```

A successful return means the output object contains the result. Module pages
call out functions that deliberately behave differently.

## Generic generated APIs

Containers and extended numeric types generate type-specific symbols. For
example:

```c
TVector(int, values);
FLAT_VECTOR_FUNC(int, PushBack)(&values, 42);
```

expands to calls around the generated type and function family:

```c
Flat_TVector_int values = {0};
Flat_Vector_int_PushBack(&values, 42);
```

For a custom generated suffix, substitute that suffix in the direct symbol in
the same position shown by the naming macro.

## Pseudo-method tables

Selected Container and Type APIs can expose function-table ergonomics. For
containers this is controlled by:

```c
#define CONTAINER_ENABLE_PSEUDO_METHODS 0 /* or 1 */
```

Direct functions remain the canonical callable API. The documentation therefore
shows direct functions even when an example also demonstrates `object.api->...`.

## Header-oriented implementation

Congro's `.impl` files are implementation pages included by public headers.
They are not separate translation units and are not user linker inputs. Include
the public `.h` file for the API you use.
