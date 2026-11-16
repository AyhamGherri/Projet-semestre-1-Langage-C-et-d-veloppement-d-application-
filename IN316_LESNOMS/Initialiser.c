/* projet final */
    
#include "stdio.h"
#include "stdlib.h"
#include "dirent.h"
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
//creer dossier pour les images
void creer_dossiers(){
    File = *f
    for(int i = 0; i < 9; i++){
        char command[100];
        sprintf(command, "mkdir -p %s", dossiers[i]);
        system(command);
    }
}