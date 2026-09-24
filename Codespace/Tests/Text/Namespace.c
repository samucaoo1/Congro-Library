#define CONGRO_NAMESPACE Congro
#define CONGRO_NAMESPACE_CONST CONGRO
#include "../../Congro/Modules/Text/Text.h"

#include <assert.h>

int main(void) {
  Congro_TText_Grid_char32 grid = {0};
  Congro_Struct_TDual_uint16 size = {.col = 2U, .row = 1U};
  assert(Congro_Text_Grid_char32_Create(&grid, size) ==
         CONGRO_STATUS_SUCCESS);
  assert(Congro_Text_Grid_char32_Destroy(&grid) ==
         CONGRO_STATUS_SUCCESS);
  return 0;
}
