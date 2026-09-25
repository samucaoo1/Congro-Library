#include <assert.h>
#include "Congro/Modules/Struct/TDual.h"
#include "Congro/Modules/Struct/TQuad.h"

int main(void) {
  TDUAL_TYPE(uint16) position = {.x = 5, .y = 3};
  TQUAD_TYPE(uint16) cell = {
      .left = position.x, .right = position.x,
      .top = position.y, .bottom = position.y};
  assert(position.col == 5 && position.row == 3);
  assert(cell.right - cell.left + 1 == 1);
  return 0;
}
