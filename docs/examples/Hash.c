#include <assert.h>
#include "Congro/Modules/Container/Hash/Hash.h"

int main(void) {
  THASH_TYPE(cstring, int) scores = {0};
  OPSTATUS status = HASH_OPERATION(cstring, int, Init)(&scores);
  if (status != STATUS_CONST(SUCCESS))
    return 1;
  status = HASH_OPERATION(cstring, int, Insert)(&scores, "okarin", 42);
  if (status == STATUS_CONST(SUCCESS)) {
    const int *score = HASH_OPERATION(cstring, int, ConstFind)(&scores, "okarin");
    assert(score != NULL && *score == 42);
  }
  HASH_OPERATION(cstring, int, Destroy)(&scores);
  return status == STATUS_CONST(SUCCESS) ? 0 : 2;
}
