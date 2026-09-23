#pragma once

#if OS_WINDOWS
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <winsock2.h>

static inline BOOL CALLBACK NETWORK_FUNC(_InitializeWinSock)(
    PINIT_ONCE init_once, PVOID parameter, PVOID *context) {
  bool *initialized = (bool *)parameter;
  WSADATA data;
  (void)init_once;
  (void)context;
  *initialized = WSAStartup(MAKEWORD(2, 2), &data) == 0;
  return TRUE;
}

static inline bool NETWORK_FUNC(_EnsureRuntime)(void) {
  static INIT_ONCE once = INIT_ONCE_STATIC_INIT;
  static bool initialized = false;
  if (!InitOnceExecuteOnce(&once, NETWORK_FUNC(_InitializeWinSock),
                           &initialized, NULL))
    return false;
  return initialized;
}
#else
static inline bool NETWORK_FUNC(_EnsureRuntime)(void) { return true; }
#endif
