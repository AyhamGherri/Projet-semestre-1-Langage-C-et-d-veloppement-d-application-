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
    int** vert;
    int** bleu;
};


int verifie_dossier(const char *chemin){                        // Fonction qui permet de vérifier si un dossier existe ou non
    struct stat info;                                           // Crée la variable "info" vide qui pourra stocker les informations d'un fichier
    return stat(chemin, &info) == 0 && S_ISDIR(info.st_mode);   // Récupère les données du fichier et les stocks dans "info" ET vérifie si il s'agit bien d'un dossier.
}


void cree_dossier(){                        // Fonction qui permet de crée un dossier si celui ci n'existe pas
    if (!verifie_dossier("IMAGE/BASE_PPM")){      // Utilise la fonction Verifie_dossier pour voir si le dossier "BASE_PPM" existe
        mkdir("IMAGE/BASE_PPM", 0755);            // Si il n'existe pas, on le crée  
    }
    
    char *taille[9]={                       // Crée un tableau contenant des chaînes de caractère pour les tailles que chaque image doivent faire
        "IMAGE/BASE_PPM/1024x768",
        "IMAGE/BASE_PPM/512x384",
        "IMAGE/BASE_PPM/256x192",
        "IMAGE/BASE_PPM/128x96",
        "IMAGE/BASE_PPM/64x48",
        "IMAGE/BASE_PPM/32x24",
        "IMAGE/BASE_PPM/16x12",
        "IMAGE/BASE_PPM/8x6",
        "IMAGE/BASE_PPM/4x3"
    };

    for (int i = 0 ; i < 9 ; i++ ){         // Parcours chaque taille des images
        if (!verifie_dossier(taille[i])){   // Grâce a la fonction "verifie_dossier" on vérifie si chaque taille existe bien dans les dossiers
            mkdir(taille[i], 0755);         // Si il n'existe pas, on le crée 
        }
    }
}

void test_dossier(){                                                            // Fonction qui nous permet de tester si la création de dossier fonctionne bien
    cree_dossier();                                                             // On appel la fonction cree_dossier

    printf("test des dossers :\n");                             
    printf("BASE_PPM existe : %d\n", verifie_dossier("BASE_PPM"));              // Avec la fonction verifie_dossier on verifie si BASE_PPM existe bien grâce a la fonction cree_dossier
    printf("BASE_PPM/4x3 existe : %d\n", verifie_dossier("BASE_PPM/4x3"));      // De même avec un exemple de BASE_PPM/4x3
}


void sauter_commntaire(FILE *fichier){
    // rien a écrire ici
}


void lire_entete(FILE *fichier, struct image *img){
    char magic[3];

    fscanf(fichier, "%s", magic);

    sauter_commntaire(fichier);

    fscanf(fichier, "%d %d %d", &img -> largeur, &img -> hauteur, &(img -> range));

    sauter_commntaire(fichier); 
}


void libere_image(struct image *img){           // Fonction qui permet de liberer l'image si celle ci 
    if (img == NULL){
        return;
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


struct image *allouer_memoire_image(int largeur, int hauteur){          // Fonction qui permet d'allouer de la mémoire 
    struct image *img = malloc(sizeof(struct image));

    if (img == NULL){
        printf("Erreur lors de l'allocation de la mémoire\n");
        return NULL;
    }

    img -> rouge = malloc(img -> largeur * sizeof(int)); 
    img -> vert = malloc(img -> largeur * sizeof(int)); 
    img -> bleu = malloc(img -> largeur * sizeof(int)); 
    if (img -> rouge == NULL || img -> vert == NULL || img -> bleu == NULL) {
        libere_image(img);
        return NULL;
    }

    int i;

    for (i = 0; i < img -> hauteur; i++){
        img -> rouge[i] = malloc(img -> hauteur * sizeof(int *));
        img -> vert[i] = malloc(img -> hauteur * sizeof(int *));  
        img -> bleu[i] = malloc(img -> hauteur * sizeof(int *));

        if (img -> rouge[i] == NULL || img -> vert[i] == NULL || img -> bleu[i] == NULL) {
            libere_image(img);
            return NULL;
        }
    }

}


void convertir_ppm(const char *nom){                                                                                // Fonction qui permet de transformer une image de n'importe quelle format en image.ppm, elle prend en paramatrère une chaîne de caractère qui correspond au nom de notre fichier (on ne veut pas la modifier donc on met const)
    char *nouveau = malloc(strlen(nom) + 1);                                                                        // On crée une nouvelle chaîne de caractère qui va stocker en mémoire une copie du nom de l'image (on met le + 1 pour bien prendre en compte le "\0" qui est à la fin de la chaine de caractère)
    if (nouveau == NULL){                                                                                           // On vérifie si nouveau a bien été allouer
        printf("Erreur lors de l'allocation de la mémoire\n");
        return;                                                                                                     // si non alos on quitte la fonction 
    }
    strcpy(nouveau, nom);                                                                                           // On copie le nom de l'image dans notre variable "nouveau"

    char *point = strrchr(nouveau, '.');                                                                            // on définie un pointeur qui va chercher dans notre variable "nouveau" quand il y a eu pour la dérnière fois un "."
    if (point != NULL){                                                                                             // si il y a un point dans le nom de "nouveau"
        *point = '\0';                                                                                              // on ajoute "\0" pour couper tout ce qu'il y a apres le point 
    }

    char commande[250];                                                                                             // On définit une chaine de caractère "commande" qui va stocker la commande magick qui va être écrite dans le terminale 
    snprintf(commande, sizeof commande, "magick IMAGE/BASE/%s -compress none BASE_PPM/%s.ppm", nom, nouveau);       // On écrit dans "commande" la commande magick qui va stocker notre nouvelle image PPM dans le dossier "BASE_PPM" et va s'assurer avec "-compress none" que c'est bien en P3 

    int res = system(commande);                                                                                     // execute dans le terminale la commande de notre chaine de caractère "commande", elle convertie donc le fichier en PPM
    if (res != 0){                                                                                                  // On vérifie si l'image a bien été convertie 
        printf("Erreur lors de la conversion de l'image %s\n", nom);                                                //si non on affiche un message d'erreur et on continue jusqu'au free(nouveau)
    }

    free(nouveau);                                                                                                  // Maintenantr qu'on a convertie notre image en PPM on peut libérer "nouveau"
}

void test_conversion(){
    printf("test de la conversion :\n");
    convertir_ppm("ArcDeTriomphe.jpg");
}


int lire_image_ppm(const char *nom){                                          // Fonction qui permet de lire l'image qu'on vient de convertir en ppm
    FILE *fichier;

    struct image *img = malloc(sizeof(struct image));
    fichier = fopen(nom, "r");
    if (fichier == NULL){
        printf("Erreur lors de l'ouverture du fichier %s\n", nom);
        exit(1);
    }

    
}

// fonction de la question 3 (h) qui permet de stocker les 

int stockage_pixels_images_liste(){

}


// fonction qui calcule les moyennes de pixels

void moyenne_images(struct image *img, int **rouge, int **vert, int **bleu) {
    long somme_rouge = 0;
    long somme_vert = 0;
    long somme_bleu = 0;

    for (int i = 0; i < img->hauteur; i++) {
        for (int j = 0; j < img->largeur; j++) {
            somme_rouge += rouge[i][j]; //la somme des pixels
            somme_vert += vert[i][j];
            somme_bleu += bleu[i][j];
        }
    }

    long total_pixels = img->largeur * img->hauteur; // Calcul du nombre total de pixels H x L
    int moyenne_rouge = somme_rouge / total_pixels;
    int moyenne_vert = somme_vert / total_pixels;
    int moyenne_bleu = somme_bleu / total_pixels;

}

// fonction qui permet de crée le chemin jusqu'a l'image que l'on doit afficher.

int chemin_de_chaque_image(char *chem) {

}


int main(){
    test_dossier();
    test_conversion();
    // test_allocation();

    return 0;
}
