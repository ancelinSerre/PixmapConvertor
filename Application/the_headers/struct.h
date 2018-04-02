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

/* Transforme trois couleurs sur 16 bits en un pixel sur 64 bits. */
uint64_t fillPixel(uint16_t red, uint16_t green, uint16_t blue);

/* Renvoi la valeur de la couleur rouge dans le pixel donné. */
uint16_t getRed(uint64_t pixel);

/* Renvoi la valeur de la couleur verte dans le pixel donné. */
uint16_t getGreen(uint64_t pixel);

/* Renvoi la valeur de la couleur bleu dans le pixel donné. */
uint16_t getBlue(uint64_t pixel);

#endif /* _STRUCT_H */