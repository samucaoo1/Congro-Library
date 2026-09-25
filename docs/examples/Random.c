#include <assert.h>
#include "Congro/Modules/Random/Random.h"

int main(void) {
  TRandomSource source = {0};
  int values[] = {1, 2, 3, 4};
  OPSTATUS status = RANDOM_SOURCE_FUNC(Init)(
      &source, &RANDOM_ENGINE_FUNC(Xoshiro, VTable), UINT64_C(42), NULL);
  if (status != STATUS_CONST(SUCCESS))
    return 1;
  uint64_t roll = RANDOM_DISTRIBUTION_FUNC(U64)(&source, 1, 6);
  assert(roll >= 1 && roll <= 6);
  status = RANDOM_SHUFFLE_VECTOR_FROM_SOURCE(values, 4, &source);
  RANDOM_SOURCE_FUNC(Destroy)(&source);
  if (status != STATUS_CONST(SUCCESS))
    return 2;
  assert(values[0] + values[1] + values[2] + values[3] == 10);
  return 0;
}
