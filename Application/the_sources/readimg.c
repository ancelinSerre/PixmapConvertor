#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "../the_headers/readimg.h"

image *readImage(FILE *f)
{
  /* Récupération des paramètres pour l'init de l'image */
  char type[2];
  int x;

  x=fscanf(f, "%s ", type);
  if (!(type[0] == 'P' && type[1] == '3'))
  {
    return NULL;
  }
  uint32_t width;
  uint32_t height;
  // **
  x=fscanf(f, "%lu %lu", (unsigned long*)&width, (unsigned long*)&height);
  if(x != 2) {
    return NULL;
  }
  uint16_t maxValue;
  x=fscanf(f, "%u", (unsigned int*)&maxValue);
  if(x != 1) {
    return NULL;
  }

  /* Initialisation de l'image */
  image *img = newImage(type, width, height, maxValue);

  unsigned long long i = 0;
  int nbRead = 3;
  /* On complète le tableau data de l'image */
  while (i < (img->width * img->height)) {
    uint16_t red;
    uint16_t green;
    uint16_t blue;

    nbRead = fscanf(f,"%u %u %u", (unsigned int*)&red,(unsigned int*)&green, (unsigned int*)&blue);

    img->data[i] = fillPixel(red,green,blue);
    i++;
  }
  return img;
}

image *newImage(char type[2], uint32_t width, uint32_t height, uint16_t maxValue)
{
  /* Allocation mémoire pour l'image */
  image *img = (image *)malloc(sizeof(image));
  img->type = P3;
  img->height = height;
  img->width = width;
  img->maxValue = maxValue;
  /* Mémoire allouée, ne pas oublier de libérer */
  img->data = (uint64_t*)malloc(width * height * sizeof(uint64_t));
  return img;
}

image *readSTD() {
  /* Récupération des paramètres pour l'init de l'image */
  char type[2];
  int x;

  x=scanf("%s", type);
  if (!(type[0] == 'P' && type[1] == '3'))
  {
    return NULL;
  }
  uint32_t width;
  uint32_t height;
  x=scanf("%lu %lu", (unsigned long*)&width, (unsigned long*)&height);
  if(x != 2) {
    return NULL;
  }
  uint16_t maxValue;
  x=scanf("%u",(unsigned int*) &maxValue);
  if(x != 1) {
    return NULL;
  }

  /* Initialisation de l'image */
  image *img = newImage(type, width, height, maxValue);

  int i = 0;
  /* On complète le tableau data de l'image */
  while (i < (img->width * img->height)) {
    printf("Pixel %d: \n", i);
    uint16_t red = 0;
    uint16_t green = 0;
    uint16_t blue = 0;

    x=scanf("%u%u%u", (unsigned int*)&red, (unsigned int*)&green, (unsigned int*)&blue);

    if(x != 3) {
      return NULL;
    }
    if( (red>img->maxValue) || (green>img->maxValue) || (blue>img->maxValue) ) {
      printf("Valeur entrée supérieur a la valeur max d'une couleur. \n");
      return NULL;
    }

    img->data[i] = fillPixel(red,green,blue);
    i++;
  }
  return img;
}
