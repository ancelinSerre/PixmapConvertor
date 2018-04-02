#ifndef _WRITEIMG_H
#define _WRITEIMG_H

#include "../the_headers/struct.h"
#include <stdio.h>
/**
 * writeimg
 * -------
 * Fonction utilitaire pour écrire une image dans un fichier
 * 
 * Réalisé par Damien Wykland et Ancelin Serre
 */


/**
 * Ecrit un fichier au format PPM
 * @param char* fileName le nom du fichier à écrire
 * @param image* img la structure de l'image à écrire
 */
void writeImagePPM(char* filename, image* img);


#endif /* _WRITEIMG_H */