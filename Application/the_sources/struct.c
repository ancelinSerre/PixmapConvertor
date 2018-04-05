#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include "../the_headers/struct.h"

/**
 * Réalisé par Damien Wykland et Ancelin Serre 
 */

uint64_t fillPixel(uint16_t red, uint16_t green, uint16_t blue)
{
  uint64_t red64 = 0;
  uint64_t green64 = 0;
  uint64_t blue64 = 0;

  /* La composante rouge est écrite à partir du 32ème bit */
  red64 = red;
  red64 = red64 << 32;
  /* La composante verte est écrite du 16ème au 31ème bit */
  green64 = green;
  green64 = green64 << 16;
  /* La composante bleue est écrite du bit 0 au bit 15 */  
  blue64 = blue;

  /* On fait un OU binaire pour ajouter chaque composante dans le pixel */
  red64 = red64 | green64 | blue64;

  return red64;
}

uint16_t getRed(uint64_t pixel)
{
  uint64_t temp = pixel >> 32;
  uint16_t red = (uint16_t)temp;
  return red;
}

uint16_t getGreen(uint64_t pixel)
{
  uint64_t temp = pixel >> 16;
  uint16_t green = (uint16_t)temp;
  return green;
}

uint16_t getBlue(uint64_t pixel)
{
  uint16_t blue = (uint16_t)pixel;
  return blue;
}