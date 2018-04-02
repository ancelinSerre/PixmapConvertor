#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <inttypes.h>
#include "../the_headers/struct.h"
#include "../the_headers/readimg.h"

int main(int argc, char **argv)
{
  /**
   * Lecture des arguments
   */

  /** Etant donné que nous avons que deux possibilités de traitements (PBM ou PGM),
   * nous pouvons stocker le flag dans une variable binaire.
   * Convention : 1 pour le flag g, 0 pour le flag b.
   */
  int flag = -1;
  int c;
  int std = -1;
  char *filename;
  FILE *f;
  image *img = NULL;

  while ((c = getopt(argc, argv, "gb")) != -1)
  {
    switch (c)
    {
    case 'g':
      flag = 1;
      break;
    case 'b':
      flag = 0;
      break;
    case '?':
      if (isprint(optopt))
        printf("Option inconnue `-%c'. \n", optopt);
      else
        printf("Caractère inconnu `\\x%x'.\n", optopt);
    default:
      return 1;
    }
  }

  if (flag == -1)
  {
    printf("Merci de préciser une option en paramètre ! (-g ou -b) \n");
    return 1;
  }

  if (optind < argc)
  {
    filename = malloc(100);
    sprintf(filename, "%s", argv[optind]);
    std = 0;
  }
  else
  {
    std = 1;
  }

  /**
   * Fin de lecture des arguments
   */

  if (!std)
  {
    printf("filename : %s\n", filename);
    /* Lecture du fichier */
    f = fopen(filename, "r");
    if (f)
    {
      img = readImage(f);
      fclose(f);
      if (img == NULL)
      {
        printf("Erreur lors de la lecture du fichier\n");
        return 1;
      }
    }
    else
    {
      printf("Erreur lors de l'ouverture du fichier\n");
      return 1;
    }
  }
  else
  {
    //img = readSTD();
  }


  return 0;
}