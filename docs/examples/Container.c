#include <assert.h>
#include "Congro/Modules/Container/Array/Vector.h"

int main(void) {
  FLAT_VECTOR_TYPE(int) values = {0};
  OPSTATUS status = FLAT_VECTOR_FUNC(int, Init)(&values);
  if (status != STATUS_CONST(SUCCESS))
    return 1;
  status = FLAT_VECTOR_FUNC(int, PushBack)(&values, 42);
  if (status == STATUS_CONST(SUCCESS)) {
    int *first = FLAT_VECTOR_FUNC(int, At)(&values, 0);
    assert(first != NULL && *first == 42);
  }
  FLAT_VECTOR_FUNC(int, Destroy)(&values);
  return status == STATUS_CONST(SUCCESS) ? 0 : 2;
}
