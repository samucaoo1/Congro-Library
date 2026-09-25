#include <assert.h>
#include "Congro/Modules/Concurrency/Coroutine/Coroutine.h"

static void Count(TCoroutine *coroutine, void *argument) {
  int *value = argument;
  COROUTINE_BEGIN(coroutine);
  ++*value;
  COROUTINE_YIELD(coroutine);
  ++*value;
  COROUTINE_END(coroutine);
}

int main(void) {
  int value = 0;
  TCoroutine coroutine = COROUTINE_INIT(Count, &value);
  if (COROUTINE_FUNC(Resume)(&coroutine) != STATUS_CONST(SUCCESS))
    return 1;
  assert(value == 1 && COROUTINE_FUNC(IsSuspended)(&coroutine));
  if (COROUTINE_FUNC(Resume)(&coroutine) != STATUS_CONST(SUCCESS))
    return 2;
  assert(value == 2 && COROUTINE_FUNC(IsFinished)(&coroutine));
  return 0;
}
