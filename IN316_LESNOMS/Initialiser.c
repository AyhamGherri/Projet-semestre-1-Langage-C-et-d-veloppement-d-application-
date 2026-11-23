/* projet final */
    
/* Bibliothèques */
#include "stdio.h"
#include "stdlib.h"
#include "dirent.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "string.h"


#define LARGEUR 1024
#define HAUTEUR 768
#define MAXVAL 255 // c'est la valeur max pour un pixel


struct image {
    int largeur, hauteur;
    int range; 

    int** rouge;
    int** bleu;
    int** vert;
};

int verifie_dossier(const char *chemin){    // Fonction qui permet de vérifier si un dossier existe ou non
    struct stat info;   // Crée la variable "info" vide qui pourra stocker les informations d'un fichier
    return stat(chemin, &info) == 0 && S_ISDIR(info.st_mode);   // Récupère les données du fichier et les stocks dans "info" ET vérifie si il s'agit bien d'un dossier.
}

void cree_dossier(){    // Fonction qui permet de crée un dossier si celui ci n'existe pas
    if (!verifie_dossier("BASE_PPM")){  // Utilise la fonction Verifie_dossier pour voir si le dossier "BASE_PPM" existe
        mkdir("BASE_PPM", 0755);    // Si il n'existe pas, on le crée  
    }
    
    char *taille[9]={   // Crée un tableau contenant des chaînes de caractère pour les tailles que chaque image doivent faire
        "BASE_PPM/1024x768",
        "BASE_PPM/512x384",
        "BASE_PPM/256x192",
        "BASE_PPM/128x96",
        "BASE_PPM/64x48",
        "BASE_PPM/32x24",
        "BASE_PPM/16x12",
        "BASE_PPM/8x6",
        "BASE_PPM/4x3"
    }

    for (int i = 0 ; i < 9 ; i++ ){ // Parcours chaque taille des images
        if (!verifie_dossier(taille[i])){   // Grâce a la fonction "verifie_dossier" on vérifie si chaque taille existe bien dans les dossiers
            mkdir(taille[i], 0755); // Si il n'existe pas, on le crée 
        }
    }
}

void sauter_commntaire(FILE *fichier){
    // rien a écrire ici
}

void lire_entete(FILE *fichier, struct *img){
    char magic[3];

    fscanf(fichier, "%s", magic);

    sauter_commntaire(fichier);

    fscanf(fichier, "%d %d %d", &img -> largeur, &img -> hauteur, &(img -> range));

    sauter_commntaire(fichier); 
}

struct image *allouer_memoire_image(int largeur, int hauteur){  // Fonction qui permet d'allouer de la mémoire 
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
    }

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

}

void libere_image(struct image *img){   // Fonction qui permet de liberer l'image si celle ci 
    if (img == NULL){
        return NULL;
    }

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


void convertir_ppm(struct *image){  // Fonction qui permet de transformer une image de n'importe quelle format en image.ppm
    char *nouveau = malloc(sizeof(struct image));   // On crée une nouvelle chaîne de caractère qui va stocker une copie de l'image
    strcpy(nouveau, image); // On copie image dans nouveau

    char *point = strrchr(nouveau, ".");
    if (point != NULL){
        *point = "\0";
    }

    ............
}

int lire_image_ppm(char *nom){  // Fonction qui permet de lire l'image qu'on vient de convertir en image.ppm
    FILE *fichier;

    struct image *img = malloc(sizeof(struct image));
    fichier = fopen(nom, "r");
    if (fichier == NULL){
        printf("Erreur lors de l'ouverture du fichier %s\n", nom);
        exit(1);
    }

    ..............
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
    cree_dossier();

    return 0;
}