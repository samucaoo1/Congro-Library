# Math

Math provides checked integer arithmetic, clamped and saturating arithmetic,
range/value helpers, and linear/quadratic equation utilities.

**Root:** `Codespace/Congro/Modules/Math`

## Naming

Typed functions follow:

```c
MATH_TYPED_FUNC(Space, Name, Suffix)
```

With the default namespace this expands to:

```text
Math_Space_Name_Suffix
```

For example:

```c
ARITHMETIC_TYPED_FUNC(Add, I32)(a, b, &result);
Math_Arithmetic_Add_I32(a, b, &result);
```

## Supported suffixes

Integer arithmetic:

`I8`, `I16`, `I32`, `I64`, `U8`, `U16`, `U32`, `U64`.

Value helpers also support `F32`, `F64`, and `F128`.

Equation helpers use `F32`, `F64`, and `F128`.

## Arithmetic / checked operations

**Header:** `Arithmetic/Basic.h`

Each operation writes to an output parameter and reports invalid output pointers,
integer overflow, or division-by-zero through `OPSTATUS`.

| Indirect | Direct | Purpose |
| --- | --- | --- |
| `ARITHMETIC_TYPED_FUNC(Add, I32)(a,b,&out)` | `Math_Arithmetic_Add_I32(a,b,&out)` | Checked addition. |
| `ARITHMETIC_TYPED_FUNC(Sub, I32)(a,b,&out)` | `Math_Arithmetic_Sub_I32(a,b,&out)` | Checked subtraction. |
| `ARITHMETIC_TYPED_FUNC(Mul, I32)(a,b,&out)` | `Math_Arithmetic_Mul_I32(a,b,&out)` | Checked multiplication. |
| `ARITHMETIC_TYPED_FUNC(Div, I32)(a,b,&out)` | `Math_Arithmetic_Div_I32(a,b,&out)` | Checked integer division. |
| `ARITHMETIC_TYPED_FUNC(Mod, I32)(a,b,&out)` | `Math_Arithmetic_Mod_I32(a,b,&out)` | Checked remainder. |

Example, indirect:

```c
int32_t total = 0;
OPSTATUS status = ARITHMETIC_TYPED_FUNC(Add, I32)(20, 22, &total);

if (status == STATUS_CONST(SUCCESS)) {
    /* total == 42 */
}
```

Direct:

```c
int32_t total = 0;
OPSTATUS status = Math_Arithmetic_Add_I32(20, 22, &total);

if (status == CONGRO_STATUS_SUCCESS) {
    /* total == 42 */
}
```

Overflow is not silently wrapped. For instance, adding two values whose result
cannot be represented returns `STATUS_CONST(ARITHMETIC_OVERFLOW)`.

## Arithmetic / clamp and saturation

**Header:** `Arithmetic/Clamp.h`

`ClampAdd`, `ClampSub`, and `ClampMul` perform the arithmetic and constrain
the result to the user-supplied interval. If the underlying operation overflows,
the corresponding boundary is returned.

`SaturatingAdd`, `SaturatingSub`, and `SaturatingMul` use the full range of
the integer type.

| Indirect | Direct |
| --- | --- |
| `ARITHMETIC_TYPED_FUNC(ClampAdd, I32)(a,b,min,max)` | `Math_Arithmetic_ClampAdd_I32(...)` |
| `ARITHMETIC_TYPED_FUNC(ClampSub, I32)(a,b,min,max)` | `Math_Arithmetic_ClampSub_I32(...)` |
| `ARITHMETIC_TYPED_FUNC(ClampMul, I32)(a,b,min,max)` | `Math_Arithmetic_ClampMul_I32(...)` |
| `ARITHMETIC_TYPED_FUNC(SaturatingAdd, I32)(a,b)` | `Math_Arithmetic_SaturatingAdd_I32(a,b)` |
| `ARITHMETIC_TYPED_FUNC(SaturatingSub, I32)(a,b)` | `Math_Arithmetic_SaturatingSub_I32(a,b)` |
| `ARITHMETIC_TYPED_FUNC(SaturatingMul, I32)(a,b)` | `Math_Arithmetic_SaturatingMul_I32(a,b)` |

Example:

```c
uint8_t brightness =
    ARITHMETIC_TYPED_FUNC(ClampAdd, U8)(250, 20, 0, 255);
/* brightness == 255 */

uint8_t alsoBrightness =
    Math_Arithmetic_ClampAdd_U8(250, 20, 0, 255);
```

## Value / range tests

**Header:** `Value/Between.h`

`IsBetween` is strict: the endpoints are not considered “between”.

`Between` returns a `TMathRangeResult`, distinguishing lower, higher, exactly
minimum, exactly maximum, and strictly between.

| Indirect | Direct |
| --- | --- |
| `VALUE_TYPED_FUNC(IsBetween, F64)(x,min,max)` | `Math_Value_IsBetween_F64(...)` |
| `VALUE_TYPED_FUNC(Between, F64)(x,min,max)` | `Math_Value_Between_F64(...)` |

Example:

```c
bool inside = VALUE_TYPED_FUNC(IsBetween, F64)(0.5, 0.0, 1.0);
TMathRangeResult where = VALUE_TYPED_FUNC(Between, F64)(1.0, 0.0, 1.0);
```

Direct:

```c
bool inside = Math_Value_IsBetween_F64(0.5, 0.0, 1.0);
TMathRangeResult where = Math_Value_Between_F64(1.0, 0.0, 1.0);
```

## Value / Clamp

**Header:** `Value/Clamp.h`

```c
int32_t x = VALUE_TYPED_FUNC(Clamp, I32)(150, 0, 100);
int32_t y = Math_Value_Clamp_I32(150, 0, 100);
/* both are 100 */
```

## Value / minima and maxima

**Header:** `Value/MaxAndMin.h`

| Indirect | Direct | Purpose |
| --- | --- | --- |
| `VALUE_TYPED_FUNC(Max, I32)(a,b)` | `Math_Value_Max_I32(a,b)` | Larger of two values. |
| `VALUE_TYPED_FUNC(Min, I32)(a,b)` | `Math_Value_Min_I32(a,b)` | Smaller of two values. |
| `VALUE_TYPED_FUNC(Smallest, I32)(&out,n,...)` | `Math_Value_Smallest_I32(...)` | Smallest among `n` variadic values. |
| `VALUE_TYPED_FUNC(Biggest, I32)(&out,n,...)` | `Math_Value_Biggest_I32(...)` | Largest among `n` variadic values. |

Example:

```c
int32_t smallest = 0;
VALUE_TYPED_FUNC(Smallest, I32)(&smallest, 4, 9, -2, 10, 3);
```

Direct:

```c
Math_Value_Smallest_I32(&smallest, 4, 9, -2, 10, 3);
```

## Equation / Linear

**Header:** `Equation/Linear.h`

Solves `a*x + b = 0`.

```c
double root = 0.0;
TMathSolution solution;

EQUATION_TYPED_FUNC(Linear, F64)(2.0, -8.0, &root, &solution);
```

Direct:

```c
Math_Equation_Linear_F64(2.0, -8.0, &root, &solution);
```

`TMathSolution` indicates whether there is no solution, one solution, multiple
solutions, or infinitely many solutions.

## Equation / Quadratic

**Header:** `Equation/Quadratic.h`

### Discriminant

```c
double d =
    EQUATION_TYPED_FUNC(QuadraticDiscriminant, F64)(1.0, -3.0, 2.0);
```

Direct:

```c
double d = Math_Equation_QuadraticDiscriminant_F64(1.0, -3.0, 2.0);
```

### Real roots

```c
double x1 = 0.0;
double x2 = 0.0;
TMathSolution solution;

EQUATION_TYPED_FUNC(Quadratic, F64)(
    1.0, -3.0, 2.0, &x1, &x2, &solution);
```

Direct:

```c
Math_Equation_Quadratic_F64(
    1.0, -3.0, 2.0, &x1, &x2, &solution);
```

If `a == 0`, the implementation falls back to the corresponding linear case.
A negative discriminant reports no real solution.

### Complex roots

Where complex-number support is available:

```c
double complex x1;
double complex x2;
TMathSolution solution;

EQUATION_TYPED_FUNC(QuadraticComplex, F64)(
    1.0, 0.0, 1.0, &x1, &x2, &solution);
```

Direct:

```c
Math_Equation_QuadraticComplex_F64(
    1.0, 0.0, 1.0, &x1, &x2, &solution);
```

The library uses its own square-root routine here, preserving the zero-link
design rather than requiring `-lm` from users.
