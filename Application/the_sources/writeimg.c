#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "../the_headers/writeimg.h"
#include "../the_headers/struct.h"

void writeImagePPM(FILE *f, image* img) {
  fprintf(f, "%s\n","P3");
  fprintf(f, "%lu %lu\n",(unsigned long)img->width, (unsigned long)img->height);
  fprintf(f, "%u\n", (unsigned int)img->maxValue);

  for(int i = 1; i <= (img->width * img->height); i++) {
    
    fprintf(f, "%u %u %u ", getRed(img->data[i-1]), getGreen(img->data[i-1]), getBlue(img->data[i-1]));

    /* Permet de rendre un fichier image plus lisible en affichant 6 pixels par ligne */
    if(i%6 == 0) {
      fprintf(f, "\n");
    }
  }

  return;
}