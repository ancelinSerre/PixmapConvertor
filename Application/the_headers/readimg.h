#ifndef _READIMG_H
#define _READIMG_H

/**
 * readimg
 * -------
 * Fonction utilitaire pour lire une image
 * 
 * Réalisé par Damien Wykland et Ancelin Serre
 */

/* Définition du type de l'image */
typedef enum 
{
  P1 = 1,
  P2,
  P3
} image_type;

/* Définition de la structure d'un pixel */
typedef struct
{
  image_type type;
  void *components;
} pixel;

/* Définition de la structure de l'image */
typedef struct
{
  image_type type;
  uint32_t width;
  uint32_t height;
  int maxValue;
  pixel *data;
} image;

/**
 * Lit un fichier au format PPM
 * et renvoi sa structure
 * @param char* fileName le nom du fichier à lire
 * @return image* un pointeur vers la structure de l'image
 */
image *readImage(char *fileName);

/**
 * Alloue et initialise un pixel d'un certain image_type
 * @param image_type type le type de l'image dans laquelle le pixel est stocké 
 * @param void* components tableau des composants du pixel, le type des données 
 * du tableau dépend du type de l'image
 * @return pixel* un pointeur vers le pixel créé
 */
pixel *newPixel(image_type type,void* components);

/**
 * Alloue et initialise une image
 * @param char type[2] le type de l'image récupéré dans en en-tête du fichier PPM
 * @param int maxValue valeur max utilisée pour coder une couleur
 * @param uint32_t width largeur de l'image
 * @param uint32_t height hauteur de l'image
 * @return image* un pointeur vers l'image créée
 */
image *newImage(char type[2], uint32_t width, uint32_t height, int maxValue);

#endif /* _READIMG_H */