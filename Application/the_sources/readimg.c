#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "../the_headers/readimg.h"

/**
 * Réalisé par Damien Wykland et Ancelin Serre 
 */

image *readImage(FILE *f)
{
  /* Récupération des paramètres pour l'init de l'image */
  char type[2];
  int x;

  /* Lecture du nombre magique */
  x=fscanf(f, "%s ", type);
  if (!(type[0] == 'P' && type[1] == '3'))
  {
    /* Si le nombre magique est différent de P3, erreur */
    return NULL;
  }
  uint32_t width;
  uint32_t height;
  /* Lecture de la largeur et de la hauteur */
  x=fscanf(f,"%"SCNu32 "%"SCNu32, &width, &height);
  if(x != 2)
    /* Si on a pas deux lectures, erreur */
    return NULL;
  uint16_t maxValue;
  /* Lecture de la valeur max d'une couleur */
  x=fscanf(f, "%"SCNu16, &maxValue);
  if(x != 1) 
    /* Si lecture incorrecte, retour avec erreur */
    return NULL;

  /* Initialisation de l'image */
  image *img = newImage(type, width, height, maxValue);
  int nbread;
  unsigned long long i = 0;
  /* On complète le tableau data de l'image */
  while (i < (img->width * img->height)) {
    uint16_t red;
    uint16_t green;
    uint16_t blue;

    nbread = fscanf(f,"%"SCNu16 "%"SCNu16 "%"SCNu16, &red,&green,&blue);
    if(nbread != 3)
    {
      free(img->data);
      free(img);
      return NULL;
    }

    /* Transformation de trois variables de couleurs en une variable de taille 64 bits */
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
  /* Mémoire allouée qui sera libérée plus tard dans le main */
  img->data = (uint64_t*)malloc(width * height * sizeof(uint64_t));
  return img;
}

image *readSTD() 
{
  /* Récupération des paramètres pour l'init de l'image */
  char type[2];
  int x;

  /* Lecture du nombre magique */
  x=scanf("%s", type);
  if (!(type[0] == 'P' && type[1] == '3'))
  {
    /* Si le nombre magique est différent de P3, erreur */
    return NULL;
  }
  uint32_t width;
  uint32_t height;
  /* Lecture de la largeur et de la hauteur */
  x=scanf("%"SCNu32 "%"SCNu32, &width, &height);
  if(x != 2)
    /* Si on a pas deux lectures, erreur */
    return NULL;
  uint16_t maxValue;
  /* Lecture de la valeur max d'une couleur */
  x=scanf("%"SCNu16, &maxValue);
  if(x != 1)
    /* Si lecture incorrecte, retour avec erreur */
    return NULL;

  /* Initialisation de l'image */
  image *img = newImage(type, width, height, maxValue);

  int i = 0;
  /* On complète le tableau data de l'image */
  while (i < (img->width * img->height))
  {
    printf("Pixel %d: \n", i);
    uint16_t red = 0;
    uint16_t green = 0;
    uint16_t blue = 0;

    x=scanf("%"SCNu16 "%"SCNu16 "%"SCNu16, &red, &green, &blue);

    if(x != 3)
      return NULL;

    if( (red>img->maxValue) || (green>img->maxValue) || (blue>img->maxValue) ) 
    {
      printf("Valeur entrée supérieur a la valeur max d'une couleur. \n");
      return NULL;
    }

    img->data[i] = fillPixel(red,green,blue);
    i++;
  }
  return img;
}
