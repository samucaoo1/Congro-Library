#include <assert.h>
#include "Congro/Modules/Chronometry/Chronometry.h"

int main(void) {
  CALENDAR_FUNC(Policy) policy =
      CALENDAR_FUNC(SystemPolicy)(CALENDAR_CONST(GREGORIAN));
  CHRONOMETRY_TYPE(Date) date = {.year = 2024, .month = 2, .day = 29};
  uint16_t day = 0;
  OPSTATUS status = CALENDAR_FUNC(DateToDayOfYear)(&policy, date, &day);
  if (status != STATUS_CONST(SUCCESS))
    return 1;
  assert(day == 60);
  return 0;
}
