
#include <stdio.h>
#include <stdlib.h>

#define LARGEUR 1024
#define HAUTEUR 768
#define MAXVAL 255 // c'est la valeur max pour un pixel

struct image {
    int largeur,hauteur;
    int range;
    int** r;
    int** b;
    int** v;
}
