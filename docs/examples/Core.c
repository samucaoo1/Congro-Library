#include <assert.h>
#include "Congro/Core/Memory/Alloc.h"

int main(void) {
  void *storage = NULL;
  OPSTATUS status = ALLOC_FUNC(AllocArray)(&storage, 4, sizeof(int));
  if (status != STATUS_CONST(SUCCESS))
    return 1;
  int *values = storage;
  values[0] = 42;
  assert(values[0] == 42);
  Memory_Free(values);
  storage = NULL;
  assert(values == NULL);
  return 0;
}
