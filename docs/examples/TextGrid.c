#include <assert.h>
#include "Congro/Modules/Text/Grid/Grid.h"

int main(void) {
  TEXT_GRID_TYPE(char32) grid = {0};
  TDUAL_TYPE(uint16) size = {.col = 10, .row = 5};
  TDUAL_TYPE(uint16) position = {.x = 5, .y = 3};
  TEXT_GRID_ATTRIBUTE_TYPE(Cell) attribute = TEXT_GRID_ATTRIBUTE_FUNC(Default)();
  TText_Char32 character = 0;
  OPSTATUS status = TEXT_GRID_FUNC(char32, Create)(&grid, size);
  if (status != STATUS_CONST(SUCCESS))
    return 1;
  status = TEXT_GRID_FUNC(char32, WriteCell)(&grid, position, 'A', attribute);
  if (status == STATUS_CONST(SUCCESS))
    status = TEXT_GRID_FUNC(char32, ReadCell)(&grid, position, &character, &attribute);
  if (status == STATUS_CONST(SUCCESS))
    assert(character == 'A');
  OPSTATUS destroyed = TEXT_GRID_FUNC(char32, Destroy)(&grid);
  return status == STATUS_CONST(SUCCESS) && destroyed == STATUS_CONST(SUCCESS) ? 0 : 2;
}
