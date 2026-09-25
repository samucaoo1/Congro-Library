#include <assert.h>
#include <string.h>
#include "Congro/Modules/Type/TBigint.h"

int main(void) {
  TBIGINT_TYPE(128) value = {0};
  char text[129];
  if (TBIGINT_FUNC(128, Init)(&value) != STATUS_CONST(SUCCESS))
    return 1;
  value.limb[0] = 42;
  if (TBIGINT_FUNC(128, ToCStringBase)(&value, text, sizeof(text), 16) !=
      STATUS_CONST(SUCCESS))
    return 2;
  assert(strcmp(text, "2a") == 0 || strcmp(text, "2A") == 0);
  return 0;
}
