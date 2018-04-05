#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "../the_headers/writeimg.h"

/**
 * Réalisé par Damien Wykland et Ancelin Serre 
 */

void writeImagePPM(FILE *f, image *img)
{
  /* Ecriture du nombre magique */
  fprintf(f, "%s\n", "P3");
  /* Ecriture de la largeur et de la hauteur */
  fprintf(f, "%"SCNu32 " " "%"SCNu32 "\n",img->width, img->height);
  /* Ecriture de la valeur max d'une couleur */
  fprintf(f,"%"SCNu16 "\n", img->maxValue);

  for (int i = 1; i <= (img->width * img->height); i++)
  {
    /* Ecriture des données de l'image */
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
  /* Ecriture du nombre magique */
  fprintf(f, "%s\n", "P2");
  /* Ecriture de la largeur et de la hauteur */
  fprintf(f, "%"SCNu32 " " "%"SCNu32 "\n", img->width, img->height);
  /* Ecriture de la valeur max d'une intensité de gris */
  fprintf(f, "%"SCNu16 "\n", img->maxValue);

  for (int i = 1; i <= (img->width * img->height); i++)
  {
    /* Ecriture des données de l'image */
    fprintf(f, "%"SCNu64 " ", img->data[i - 1]);
    /* Permet de rendre un fichier image plus lisible en affichant 6 pixels par ligne */
    if (i % 6 == 0)
      fprintf(f, "\n");
  }

  return;
}

void writeImagePBM(FILE *f, image *img)
{
  /* Ecriture du nombre magique */
  fprintf(f, "%s\n", "P1");
  /* Ecriture de la largeur et de la hauteur */
  fprintf(f, "%"SCNu32 " " "%"SCNu32 "\n", img->width, img->height);

  for (int i = 1; i <= (img->width * img->height); i++)
  {

    /* Ecriture des données de l'image */
    fprintf(f, "%"SCNu64 " ", img->data[i - 1]);
    /* Permet de rendre un fichier image plus lisible en affichant 6 pixels par ligne */
    if (i % 6 == 0)
      fprintf(f, "\n");
  }

  return;
}