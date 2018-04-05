#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include "../the_headers/processing.h"
#include "../the_headers/readimg.h"

/**
 * Réalisé par Damien Wykland et Ancelin Serre 
 */

image *convertPGM(image *img)
{
  /* Créé une nouvelle image avec les données correspondante au format souhaité */
  image *res = newImage("P2", img->width, img->height, img->maxValue);
  /* max = nombre total de pixels */
  unsigned long max = (img->width * img->height);

  /* choix des constantes a, b et c */
  float a = 0.299;
  float b = 0.587;
  float c = 0.114;

  for (int i = 0; i < max; i++)
    /* Formule permettant de convertir un pixel en nuances de gris */ 
    res->data[i] = a * getRed(img->data[i]) + b * getGreen(img->data[i]) + c * getBlue(img->data[i]);

  return res;
}

image *convertPBM(image *img)
{
  /* Créé une nouvelle image avec les données correspondante au format souhaité */
  image *res = newImage("P1", img->width, img->height, img->maxValue);
  /* max = nombre total de pixels */
  unsigned long max = (img->width * img->height);

  /* choix de la valeur alpha : */
  float alpha = 0.08;
  
  for (int i = 0; i < max; i++)
  {
    /* Formule permettant de convertir un pixel en binaire selon un seuil alpha */
    long double temp = (long double)(getRed(img->data[i]) * getGreen(img->data[i]) * getBlue(img->data[i]));
    if( (temp / (long double)puissance(img->maxValue,3)) > alpha )
      res->data[i] = 0;
    else
      res->data[i] = 1;
  }

  return res;
}

unsigned long long puissance(unsigned int val, unsigned int exposant)
{

  unsigned long long res = 1;
  while(exposant) 
  {
    if(exposant & 1)
      res *= val;
    exposant /= 2;
    val *= val;
  }
  return res;
}
