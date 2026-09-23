#include <assert.h>

#include "../../Congro/Modules/Network/Connection/Connection.h"

int main(void) {
  TNetwork_Connection connection;
  size_t count = 123;
  CHRONOMETRY_TYPE(Duration) negative;

  NETWORK_CONNECTION_FUNC(Init)(&connection);

  assert(NETWORK_CONNECTION_FUNC(Read)(NULL, NULL, 0, &count, NULL) ==
         STATUS_NS(INVALID_ARGUMENT));
  assert(NETWORK_CONNECTION_FUNC(Read)(&connection, NULL, 1, &count, NULL) ==
         STATUS_NS(INVALID_ARGUMENT));
  assert(NETWORK_CONNECTION_FUNC(ReadExact)(NULL, NULL, 0, NULL) ==
         STATUS_NS(INVALID_ARGUMENT));
  assert(NETWORK_CONNECTION_FUNC(Write)(NULL, NULL, 0, &count, NULL) ==
         STATUS_NS(INVALID_ARGUMENT));
  assert(NETWORK_CONNECTION_FUNC(Write)(&connection, NULL, 1, &count, NULL) ==
         STATUS_NS(INVALID_ARGUMENT));
  assert(NETWORK_CONNECTION_FUNC(WriteAll)(NULL, NULL, 0, NULL) ==
         STATUS_NS(INVALID_ARGUMENT));
  assert(NETWORK_CONNECTION_FUNC(Shutdown)(
             NULL, SOCKET_TYPE(SHUTDOWN_BOTH), NULL) == STATUS_NS(INVALID_ARGUMENT));

  negative = DURATION_FUNC(FromNanoseconds)(-1);
  assert(NETWORK_CONNECTION_FUNC(ConnectFor)(
             &connection, "127.0.0.1", 1, negative, NULL) ==
         STATUS_NS(INVALID_ARGUMENT));

  NETWORK_CONNECTION_FUNC(Destroy)(&connection);
  return 0;
}
