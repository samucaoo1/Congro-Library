#pragma once

#include "Preprocessor/Compiling.inc"
#include "Preprocessor/Arguments.h"
#include "Preprocessor/Operations.h"

#define CONGRO_SEPARATOR_TOKEN _

#define CONGRO_SEPARATOR(NAME) PP_OP_CAT2(CONGRO_SEPARATOR_TOKEN, NAME)
#define CONGRO_NAMESPACE_JOIN(SCOPE, NAME) PP_OP_CAT2(SCOPE, NAME)

#define GNS2(SCOPE, NAME)                                                      \
  CONGRO_NAMESPACE_JOIN(SCOPE, CONGRO_SEPARATOR(NAME))

#define GNS3(SCOPE, SPACE, NAME)                                               \
  GNS2(GNS2(SCOPE, SPACE), NAME)

#define GNS4(SCOPE, SPACE, SUBSPACE, NAME)                                     \
  GNS2(GNS3(SCOPE, SPACE, SUBSPACE), NAME)

#ifdef CONGRO_NAMESPACE
#define LIB_PREFIX(SPACE) GNS2(CONGRO_NAMESPACE, SPACE)
#else
#define LIB_PREFIX(SPACE) SPACE
#endif

/* Constant namespaces use the same semantic hierarchy. Their arguments are
 * already written in the constant grammar (UPPER_SNAKE_CASE). */
#define CNS2(SCOPE, NAME) GNS2(SCOPE, NAME)
#define CNS3(SCOPE, SPACE, NAME) GNS3(SCOPE, SPACE, NAME)
#define CNS4(SCOPE, SPACE, SUBSPACE, NAME) GNS4(SCOPE, SPACE, SUBSPACE, NAME)

#ifdef CONGRO_NAMESPACE_CONST
#define LIB_PREFIX_CONST(SPACE) CNS2(CONGRO_NAMESPACE_CONST, SPACE)
#else
#define LIB_PREFIX_CONST(SPACE) SPACE
#endif
/* EOF */
