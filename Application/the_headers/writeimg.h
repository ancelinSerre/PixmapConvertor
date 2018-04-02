#ifndef _WRITEIMG_H
#define _WRITEIMG_H

#include "../the_headers/struct.h"
#include <stdio.h>
/**
 * writeimg
 * -------
 * Fichier utilitaire pour écrire une image dans un fichier
 * 
 * Réalisé par Damien Wykland et Ancelin Serre
 */


/**
 * Ecrit un fichier au format PPM
 * @param FILE *f le fichier dans lequel ecrire
 * @param image* img la structure de l'image à écrire
 */
void writeImagePPM(FILE *f, image* img);

/**
 * Ecrit un fichier au format PGM
 * @param FILE *f le fichier dans lequel ecrire
 * @param image* img la structure de l'image à écrire
 */
void writeImagePGM(FILE *f, image* img);

/**
 * Ecrit un fichier au format PBM
 * @param FILE *f le fichier dans lequel ecrire
 * @param image* img la structure de l'image à écrire
 */
void writeImagePBM(FILE *f, image* img);


#endif /* _WRITEIMG_H */