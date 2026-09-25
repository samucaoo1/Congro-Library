#include <assert.h>
#include "Congro/Modules/Concurrency/Thread/Thread.h"

static void Work(void *argument) {
  int *result = argument;
  *result = 42;
}

int main(void) {
  TThread thread = {0};
  int result = 0;
  if (THREAD_FUNC(Create)(&thread, Work, &result) != STATUS_CONST(SUCCESS))
    return 1;
  if (THREAD_FUNC(Join)(&thread) != STATUS_CONST(SUCCESS))
    return 2;
  assert(result == 42);
  return 0;
}
