
#include <stdio.h>
#include <stdlib.h>

#define LARGEUR 1024
#define HAUTEUR 768
#define MAXVAL 255 // c'est la valeur max pour un pixel

// Structure pour représenter un pixel
typedef struct {
    int r;
    int g;
    int b;
} Pixel;

// Structure pour représenter une image
typedef struct {
    int largeur;
    int hauteur;
    int maxval;
    Pixel *pixels;
} Image;

// Fonction pour créer une image avec des dimensions qu on a
const int dimensions[9][2] = {{1024, 768},{512, 384},{256, 192},{128, 96},{64, 48},{32, 24},{16, 12},{8, 6},{4, 3}
};

// Dossiers correspondants aux dimensions
const char *dossiers[9] = {"1024x768","512x384","256x192","128x96","64x48","32x24","16x12","8x6","4x3"
};



