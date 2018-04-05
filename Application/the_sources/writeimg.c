#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "../the_headers/writeimg.h"

void writeImagePPM(FILE *f, image *img)
{
  fprintf(f, "%s\n", "P3");
  fprintf(f, "%"SCNu32 " " "%"SCNu32 "\n",img->width, img->height);
  fprintf(f,"%"SCNu16 "\n", img->maxValue);

  for (int i = 1; i <= (img->width * img->height); i++)
  {

    fprintf(f, "%"SCNu16 " " "%"SCNu16 " " "%"SCNu16 " ", getRed(img->data[i - 1]), getGreen(img->data[i - 1]), getBlue(img->data[i - 1]));

    /* Permet de rendre un fichier image plus lisible en affichant 6 pixels par ligne */
    if (i % 6 == 0)
    {
      fprintf(f, "\n");
    }
  }

  return;
}

void writeImagePGM(FILE *f, image *img)
{
  fprintf(f, "%s\n", "P2");
  fprintf(f, "%"SCNu32 " " "%"SCNu32 "\n", img->width, img->height);
  fprintf(f, "%"SCNu16 "\n", img->maxValue);

  for (int i = 1; i <= (img->width * img->height); i++)
  {

    fprintf(f, "%"SCNu64 " ", img->data[i - 1]);
    /* Permet de rendre un fichier image plus lisible en affichant 6 pixels par ligne */
    if (i % 6 == 0)
    {
      fprintf(f, "\n");
    }
  }

  return;
}

void writeImagePBM(FILE *f, image *img)
{
  fprintf(f, "%s\n", "P1");
  fprintf(f, "%"SCNu32 " " "%"SCNu32 "\n", img->width, img->height);

  for (int i = 1; i <= (img->width * img->height); i++)
  {

    fprintf(f, "%"SCNu64 " ", img->data[i - 1]);
    /* Permet de rendre un fichier image plus lisible en affichant 6 pixels par ligne */
    if (i % 6 == 0)
    {
      fprintf(f, "\n");
    }
  }

  return;
}