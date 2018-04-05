#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <inttypes.h>
#include <string.h>
#include "../the_headers/struct.h"
#include "../the_headers/readimg.h"
#include "../the_headers/writeimg.h"
#include "../the_headers/processing.h"

/**
 * Réalisé dans le cadre de cours de programmation C pour le système par :
 * 
 * WYKLAND Damien
 * SERRE Ancelin
 * 
 * Pixmap convertor permet de convertir une image du format PPM aux format PGM et PBM.
 */

int main(int argc, char **argv)
{
  /**
   * LECTURE DES ARGUMENTS
   */

  /** 
   * Etant donné que nous avons que deux possibilités de traitements (PBM ou PGM),
   * nous pouvons stocker le flag dans une variable binaire.
   * Convention : 1 pour le flag g, 0 pour le flag b.
   */
  int flag = -1;
  int c;
  int std = -1;
  char *filename = malloc(100);
  FILE *f;
  FILE *ff;
  image *img = NULL;
  image *res = NULL;

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
      free(filename);
      return 1;
    }
  }

  if (flag == -1)
  {
    printf("Merci de préciser une option en paramètre ! (-g ou -b) \n");
    /* On oublie pas de free la mémoire utilisée par filename */
    free(filename); 
    return 1;
  }

  if (optind < argc)
  {
    /* Nous avons une image en paramètre */
    sprintf(filename, "%s", argv[optind]);
    std = 0;
  }
  else
  {
    /* Nous travaillons sur l'entrée STD */
    std = 1;
  }

  /**
   * Fin de lecture des arguments
   */

  /**
   *  Appel des fonctions concernées suivant les choix utilisateurs  (lecture de l'image ou entrée STD)
   */
  if (!std)
  {
    /* Lecture du fichier */
    f = fopen(filename, "r");
    if (f)
    {
      img = readImage(f);
      fclose(f);
      if (img == NULL)
      {
        printf("Erreur lors de la lecture du fichier\n");
        free(filename);
        return 1;
      }
      printf("Lecture de l'image OK\n");
    }
    else
    {
      printf("Erreur lors de l'ouverture du fichier\n");
      free(filename);
      return 1;
    }
  }
  else
  {
    /* Entrée STD */
    printf("Pas de nom de fichier ou mauvais nom de fichier, on travaille sur l'entrée STD\n");
    sprintf(filename,"../../Exemples/image.ppm");
    img = readSTD();
    if (img == NULL)
    {
      printf("Erreur lors de la lecture du fichier\n");
      free(filename);
      return 1;
    }
    printf("Lecture de l'image OK\n");
  }


  /**
   * TRAITEMENTS
   */

  if (flag)
  {
    /* Si option -g */
    res = convertPGM(img);
  }
  else
  {
    /* Si option -b */
    res = convertPBM(img);  
  }

  /**
   * ECRITURES
   */

  int pos = (int)strlen(filename);

  /** Construction de la chaine de caractère du fichier de sortie.
   * La technique utilisée ici est de remplacer le caractère concerné
   * par un g ou un b suivant le format de sortie désiré. */
  if (flag)
  {
    /* Si option -g */
    filename[pos - 2] = 'g';
  }
  else
  {
    /* Si option -b */
    filename[pos - 2] = 'b';
  }

  ff = fopen(filename, "w");
  if (ff)
  {
    /* Si ouverture de fichier OK */
    if (flag)
    {
      /* Si option -g */
      printf("On sauve l'image au format PGM dans le fichier %s \n", filename);
      writeImagePGM(ff, res);
    }
    else
    {
      /* Si option -b */
      printf("On sauve l'image au format PBM dans le fichier %s \n", filename);
      writeImagePBM(ff, res);
    }

    /* On oublie pas de refermer le fichier */
    fclose(ff);
  }
  else
  {
    /* En cas d'erreur de création/d'ouverture de fichier */
    printf("Erreur lors de la création du fichier\n");
    /* On oublie pas de libérer la mémoire liée aux images et aux chaines de caractères */
    free(img->data);
    free(img);
    free(res->data);
    free(res);
    free(filename);
    return 1;
  }
  /* On oublie pas de libérer la mémoire liée aux images et aux chaines de caractères */
  free(img->data);
  free(img);
  free(res->data);
  free(res);
  free(filename);

  return 0;
}