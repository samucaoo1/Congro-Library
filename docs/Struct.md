# Struct

Struct provides small fixed-size typed aggregate families used throughout
Congro: `TPair`, `TDual`, `TTriple`, `TQuad`, and `TPenta`.

**Root:** `Codespace/Congro/Modules/Struct`

They are unions, so the same stored fields can be addressed through several
semantic aliases without conversion overhead.

## TPair

**Header:** `TPair.h`

Type spelling:

```c
TPAIR_TYPE(uint32)
Struct_TPair_uint32
```

Fields include `first/second`, `value1/value2`, `a/b`, `x/y`, and
`values[2]`.

Conversion functions:

```c
TPAIR_TYPE(uint32) pair =
    CAST_TYPE_TO_STRUCT(uint32, TPair)(10, 20);

uint32_t a, b;
CAST_STRUCT_TO_TYPE(TPair, uint32)(pair, &a, &b);
```

Direct:

```c
Struct_TPair_uint32 pair =
    Cast_uint32_To_TPair(10, 20);

Cast_TPair_To_uint32(pair, &a, &b);
```

## TDual

**Header:** `TDual.h`

TDual is the most semantic two-value aggregate. Besides generic names, aliases
include `x/y`, `X/Y`, `col/row`, `length/width`, `real/imaginary`,
`begin/end`, `first/second`, and `start/last`.

Example:

```c
TDUAL_TYPE(uint16) size =
    CAST_TYPE_TO_STRUCT(uint16, TDual)(80, 25);

printf("%u x %u", size.col, size.row);
```

Direct type/function:

```c
Struct_TDual_uint16 size =
    Cast_uint16_To_TDual(80, 25);
```

TDual additionally has a `size` specialization based on `size_t`.

## TTriple

**Header:** `TTriple.h`

Aliases include `x/y/z`, `length/width/height`, `a/b/c`, state names, and
`values[3]`.

Indirect/direct conversion pair:

```c
TTRIPLE_TYPE(float) p =
    CAST_TYPE_TO_STRUCT(float, TTriple)(1.0f, 2.0f, 3.0f);

Struct_TTriple_float q =
    Cast_float_To_TTriple(1.0f, 2.0f, 3.0f);
```

## TQuad

**Header:** `TQuad.h`

Useful aliases include `x/y/z/w` and rectangle-oriented
`left/right/top/bottom`.

```c
TQUAD_TYPE(uint16) rect = {
    .left = 2,
    .right = 20,
    .top = 3,
    .bottom = 12
};
```

Direct type: `Struct_TQuad_uint16`.

Conversions use `CAST_TYPE_TO_STRUCT(uint16,TQuad)` /
`Cast_uint16_To_TQuad`, and the inverse
`CAST_STRUCT_TO_TYPE(TQuad,uint16)` / `Cast_TQuad_To_uint16`.

## TPenta

**Header:** `TPenta.h`

Five values with aliases `a...e`, `x/y/z/w/t`, `c1...c5`,
`state1...state5`, and `values[5]`.

Indirect/direct type names:

```c
TPENTA_TYPE(double)
Struct_TPenta_double
```

## Built-in suffixes

The fixed aggregates are generated for the ordinary signed/unsigned integer and
floating types. TDual also includes `size`. On non-MSVC compilers, TDual,
TTriple, TQuad, and TPenta include C complex-number variants
(`float_complex`, `double_complex`, `longdouble_complex`).

The lowercase suffixes are intentional here because these families predate and
serve a different generated-type naming surface than Math's `I32/F64`
suffixes.
