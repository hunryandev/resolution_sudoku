// toutes les fonctions qui permettent de lire un sudoku et de l'afficher

#include <stdio.h>
#include <stdlib.h>
#define VIDE 0

typedef struct {
    int size;
unsigned char** data; } grid_t;
// structure de donnée dans laquelle on stocke les données de la grille (tableau de char)
// et la taille de la grille 


unsigned char** allocation_tab(int dimension);
//renvoie une matrice carré de unsigned char alloué dynamiqument de dimension dimension.


grid_t grid_new(int dim);
//creer en mémoire une varaible de type grid_t et renvoie cette variable en résultat


grid_t lecture_grille(char* fichier,int dim);
//lecture d'un fichier contenant un sudoku de dimension dim/

int dimension(char *fichier);
//calcul la dimension d'un sudoku stocké dans le fichier fichier


void grid_delete(grid_t grid);
// liberre la mémoire de la grill alloué dynamiquement

void grid_print(grid_t grid);
//afficher une grille de sudoku

void affichetab2char(char** tab, int n);
// affiche une matrice de char de dimension n

void affichetabchar(char*tab,int n);
//affiche un tableau de char de taille n

void affichetab2int(int** tab, int n);

void affichetabint(int * tab, int n);
