#ifndef _STRUCT_H
#define _STRUCT_H

/* Structure contenant la déclaration des types permettant la manipulation des images */

#include <inttypes.h> 

/* Type énuméré des types d'image */
typedef enum {
  P1 = 1,
  P2 = 2,
  P3 = 3
} image_type;

/* Définition de la structure de l'image */
typedef struct
{
  image_type type;
  uint32_t width;
  uint32_t height;
  uint16_t maxValue;
  uint64_t *data;
} image;

uint64_t fillPixel(uint16_t red, uint16_t green, uint16_t blue);

#endif /* _STRUCT_H */