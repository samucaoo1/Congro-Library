#include <assert.h>
#include "Congro/Modules/Network/Address/Address.h"

int main(void) {
  TNetwork_Address address;
  TNetwork_Address other;
  TNetwork_Endpoint endpoint;
  NETWORK_ADDRESS_FUNC(IPv4_Loopback)(&address);
  NETWORK_ADDRESS_FUNC(IPv4_Create)(&other, 127, 0, 0, 1);
  NETWORK_ADDRESS_FUNC(Endpoint_Create)(&endpoint, &address, 8080);
  assert(NETWORK_ADDRESS_FUNC(Equal)(&address, &other));
  assert(endpoint.port == 8080);
  return 0;
}
