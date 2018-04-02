#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "../the_headers/readimg.h"
#include "../the_headers/struct.h"

image *readImage(FILE *f)
{
  /* Récupération des paramètres pour l'init de l'image */
  char type[2];
  //fgets(type, 2, f);
  fscanf(f, "%s ", type);
  if (type[0] != 'P' && type[1] != '3')
  {
    return NULL;
  }else {
    printf("ok P3 \n");
  }
  uint32_t width;
  uint32_t height;
  fscanf(f, "%lu %lu", &width, &height);
  uint16_t maxValue;
  fscanf(f, "%u", &maxValue);
  printf("ok lect w : %lu h : %lu  max : %u \n", width, height, maxValue);
  /* Initialisation de l'image */
  image *img = newImage(type, width, height, maxValue);

  int i = 0;
  int nbRead = 3;
  /* On complète le tableau data de l'image */
  while (nbRead == 3) {
    uint16_t red;
    uint16_t green;
    uint16_t blue;

    nbRead = fscanf(f,"%u %u %u", &red, &green, &blue);

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
  img->data = (uint64_t*)malloc(width * height * sizeof(uint64_t));
  return img;
}
