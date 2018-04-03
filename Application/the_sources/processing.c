#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include "../the_headers/processing.h"
#include "../the_headers/readimg.h"

image *convertPGM(image *img)
{
  image *res = newImage("P2", img->width, img->height, img->maxValue);
  unsigned long max = (img->width * img->height);

  /* choix des constantes a, b et c :  ** en define ? */
  float a = 0.299;
  float b = 0.587;
  float c = 0.114;

  for (int i = 0; i < max; i++)
  {
    res->data[i] = a * getRed(img->data[i]) + b * getGreen(img->data[i]) + c * getBlue(img->data[i]);
  }

  return res;
}

image *convertPBM(image *img)
{
  image *res = newImage("P1", img->width, img->height, img->maxValue);
  unsigned long max = (img->width * img->height);

  /* choix de la valeur alpha : */
  float alpha = 0.08;
  
  for (int i = 0; i < max; i++)
  {
    long double temp = (long double)(getRed(img->data[i]) * getGreen(img->data[i]) * getBlue(img->data[i]));
    if( (temp / (long double)puissance(img->maxValue,3)) > alpha ) {
      res->data[i] = 0;
    }else {
      res->data[i] = 1;
    }
  }

  return res;
}

unsigned long long puissance(unsigned int base, unsigned int exp)
{
  unsigned long long result = 1;
  while(exp) {
    if(exp & 1)
      result *= base;
    exp /= 2;
    base *= base;
  }
  return result;
}
