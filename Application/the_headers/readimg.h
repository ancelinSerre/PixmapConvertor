#ifndef _READIMG_H
#define _READIMG_H

#include "../the_headers/struct.h"
#include <stdio.h>
/**
 * readimg
 * -------
 * Fichier utilitaire pour lire une image
 * 
 * Réalisé par Damien Wykland et Ancelin Serre
 */


/**
 * Lit un fichier au format PPM
 * et renvoi sa structure
 * @param char* fileName le nom du fichier à lire
 * @return image* un pointeur vers la structure de l'image, NULL si erreur de lecture
 */
image *readImage(FILE *f);

/**
 * Lit un fichier au format PPM depuis la console
 * et renvoi sa structure
 * @return image* un pointeur vers la structure de l'image
 */
image *readSTD();

/**
 * Alloue et initialise une image
 * @param char type[2] le type de l'image récupéré dans en en-tête du fichier PPM
 * @param uint16_t maxValue valeur max utilisée pour coder une couleur
 * @param uint32_t width largeur de l'image
 * @param uint32_t height hauteur de l'image
 * @return image* un pointeur vers l'image créée
 */
image *newImage(char type[2], uint32_t width, uint32_t height, uint16_t maxValue);

#endif /* _READIMG_H */