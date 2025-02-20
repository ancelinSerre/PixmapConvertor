#ifndef _PROCESSING_H
#define _PROCESSING_H

#include "../the_headers/struct.h"
/**
 * processing
 * -------
 * Fichier utilitaire de traitement sur les images (conversion PGM et PBM)
 * 
 * Réalisé par Damien Wykland et Ancelin Serre
 */


/**
 * Transforme une image PPM en image PGM et renvoi sa nouvelle structure
 * @param image* img l'image PPM a transformer
 * @return image* un pointeur vers la nouvelle structure de l'image PGM
 */
image *convertPGM(image *img);

/**
 * Transforme une image PPM en image PBM et renvoi sa nouvelle structure
 * @param image* img l'image PPM a transformer
 * @return image* un pointeur vers la nouvelle structure de l'image PBM
 */
image *convertPBM(image *img);

/**
 * Calcul de la valeur 'val' à la puissance 'exposant'
 */
unsigned long long puissance(unsigned int val, unsigned int exposant);

#endif /* _PROCESSING_H */