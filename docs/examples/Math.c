#include <assert.h>
#include "Congro/Modules/Math/Arithmetic/Basic.h"
#include "Congro/Modules/Math/Value/Between.h"
#include "Congro/Modules/Math/Value/Clamp.h"

int main(void) {
  int32_t result = 0;
  if (ARITHMETIC_TYPED_FUNC(Add, I32)(20, 22, &result) != STATUS_CONST(SUCCESS))
    return 1;
  assert(result == 42);
  assert(!VALUE_TYPED_FUNC(IsBetween, I32)(0, 0, 10));
  assert(VALUE_TYPED_FUNC(Clamp, I32)(12, 0, 10) == 10);
  assert(ARITHMETIC_TYPED_FUNC(Add, I32)(INT32_MAX, 1, &result) ==
         STATUS_CONST(ARITHMETIC_OVERFLOW));
  return 0;
}
