#include <assert.h>
#include "Congro/Modules/Bit/Bit.h"

int main(void) {
  uint32_t flags = 0;
  BIT_FUNC(32, Set)(&flags, 3);
  assert(BIT_FUNC(32, Check)(&flags, 3));
  BIT_FUNC(32, Insert)(&flags, 7, 4, 10);
  assert(BIT_FUNC(32, Extract)(&flags, 7, 4) == 10);
  assert(BIT_FUNC(32, Popcount)(flags) == 3);
  return 0;
}
