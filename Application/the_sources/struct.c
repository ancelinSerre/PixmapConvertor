#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include "../the_headers/struct.h"

uint64_t fillPixel(uint16_t red, uint16_t green, uint16_t blue) {
  uint64_t red64 = 0;
  uint64_t green64 = 0;
  uint64_t blue64 = 0;

  red64 = red;
  red64 = red64 << 32;
  green64 = green;
  green64 = green64 << 16;
  blue64 = blue;

  red64 = red64 | green64 | blue64;
  
  return red64;
}