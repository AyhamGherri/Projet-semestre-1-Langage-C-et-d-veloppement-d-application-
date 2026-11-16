
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
//Fonction pour créer une image avec des dimensions qu on a
int dimensions[9][2] = {{1024, 768},{512, 384},{256, 192},{128, 96},{64, 48},{32, 24},{16, 12},{8, 6},{4, 3}
};

// Dossiers correspondants aux dimensions
char *dossiers[9] = {"1024x768","512x384","256x192","128x96","64x48","32x24","16x12","8x6","4x3"
};

//creer dossier pour les images
void creer_dossiers(){
    for(int i = 0; i < 9; i++){
        char command[100];
        sprintf(command, "mkdir -p %s", dossiers[i]);
        system(command);
    }
}

