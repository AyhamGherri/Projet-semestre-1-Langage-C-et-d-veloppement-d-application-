/* projet final */
    
#include "stdio.h"
#include "stdlib.h"
#include "dirent.h"
#include "sys/stat.h"
#include "sys/types.h"
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

void cree_dossier(){
    mkdir("BASE_PPM",0755);
    char *taille[]={
        "BASE_PPM/1024x768",
        "BASE_PPM/512x384",
        "BASE_PPM/256x192",
        "BASE_PPM/128x96",
        "BASE_PPM/64x48",
        "BASE_PPM/32x24",
        "BASE_PPM/16x12",
        "BASE_PPM/8x6",
        "BASE_PPM/4x3"
    };
    for (int i = 0 ; i < 9 ; i++ )
    {
        mkdir(taille[i], 0755);
    }
}

void convertion_ppm() {
    
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

// fonction de la question 3 (h) qui permet de stocker les 

int stockage_pixels_images_liste(){

}

// fonction qui calcule les moyennes de pixels

int moyene_pixels(image){

}

// fonction qui permet de crée le chemin jusqu'a l'image que l'on doit afficher.

int chemin_de_chaque_image(char *chem) {

}


int main(){

}