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
    int** rouge;
    int** bleu;
    int** vert;
};
//creer dossier pour les images
void creer_dossiers(){
    File = *f
    for(int i = 0; i < 9; i++){
        char command[100];
        sprintf(command, "mkdir -p %s", dossiers[i]);
        system(command);
    }
}
struct image *cree_image(int largeur, int hauteur, int range) {
    struct image *img = malloc(sizeof(struct image));

    if (img == NULL){
        printf("Erreur lors de l'allocation de la mémoire\n");
        return NULL;
    }

    img -> rouge = malloc(img -> largeur * sizeof(int)); 
    img -> vert = malloc(img -> largeur * sizeof(int)); 
    img -> bleu = malloc(img -> largeur * sizeof(int)); 
    if (img -> rouge == NULL || img -> vert == NULL || img -> bleu == NULL) {
            liberer_image(img);
            return NULL;

    int i;

    for (i = 0; i < img -> hauteur; i++){
        img -> rouge[i] = malloc(img -> hauteur * sizeof(int *));
        img -> vert[i] = malloc(img -> hauteur * sizeof(int *));  
        img -> bleu[i] = malloc(img -> hauteur * sizeof(int *));

        if (img -> rouge[i] == NULL || img -> vert[i] == NULL || img -> bleu[i] == NULL) {
            liberer_image(img);
            return NULL;
    }

}

void libere_image(struct image *img){
    int i; 
    
    for (i = 0; i < img -> hauteur; i++){
        if (img -> rouge != NULL){
            free(img -> rouge[i]);
        }
        if (img -> vert != NULL){
            free(img -> vert[i]);
        }
        if (img -> bleu != NULL){
            free(img -> bleu[i]);
        }
    }

    free(img -> rouge);
    free(img -> vert);
    free(img -> bleu);

    free(img);
}

struct image *lire_fichier(const char *nom) {
}

int ecrire_fichier(const struct image *img, const char *nom) {
}


int main(){

}