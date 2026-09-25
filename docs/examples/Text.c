#include <assert.h>
#include "Congro/Modules/Text/Encoding/UTF8.h"

int main(void) {
  unsigned char bytes[4];
  TText_Encode_Result encoded = TEXT_UTF8_NS(Encode)(0x00E1, bytes, sizeof(bytes));
  if (encoded.error != TEXT_ERROR_NONE)
    return 1;
  TText_Decode_Result decoded = TEXT_UTF8_NS(Decode)(bytes, encoded.units);
  if (decoded.error != TEXT_ERROR_NONE)
    return 2;
  assert(decoded.codepoint == 0x00E1 && decoded.units == 2);
  return 0;
}
