#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "../the_headers/readimg.h"

image *readImage(char *fileName)
{
  /* Lecture du fichier */
  FILE *f;
  f = fopen(fileName, "r");
  if (f)
  {
    /* Récupération des paramètres pour l'init de l'image */
    char type[2];
    fgets(type, 2, f);
    uint32_t size[2];
    fscanf(f, "%u %u", size[0], size[1]);
    int maxValue = fscanf(f, "%d", &maxValue);
    /* Initialisation de l'image */
    image *img = newImage(type, size[0], size[1], maxValue);
    /* Le fichier donné ne correspond pas à une image au format PPM */
    if (!img) 
      return NULL;
    else
    {
      /* On complète le tableau data de l'image */
      while (fscanf(f, "%d", &cle) != EOF)
        a = ajouter_cle(a, cle);
      fclose(f);
      return a;
    }
  }
  /* Le fichier spécifié n'existe pas */
  else
    return NULL;
}

image *newImage(char type[2], uint32_t width, uint32_t height, int maxValue)
{
  /* Allocation mémoire pour l'image */
  image *img = (image *)malloc(sizeof(image));
  return NULL;
}