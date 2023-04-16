// fonctions dont le but est de savoir si un chiffre peut ou non occupé une case



#include "representation_sudoku.h"
#include <math.h>

int test_region(grid_t grid,int region_i,int chiffre_j);
//renvoie 1 si le chiffre j est  présent dans la région i, 0 sinon

int test_ligne(grid_t grid, int ligne_i,int chiffre_j);
//renvoie 1 si le chiffre j est présent dans dans la ligne i, 0 sinon

int test_colonne(grid_t grid, int colonne_i, int chiffre_j);
//renvoie 1 si le chiffre j est présent dans la colonne i, 0 sinon

char ** init_verif_region(grid_t grid);
// on initialise un tableau de char dont la case (i,j) nous dit si le  chiffre j+1 est présent dans la région i

char ** init_verif_ligne(grid_t grid);
// on initialise un tableau de char dont la case (i,j) nous dit si le  chiffre j+1 est présent dans la ligne i

char ** init_verif_colonne(grid_t grid);
// on initialise un tableau de char dont la case (i,j) nous dit si le  chiffre j+1 est présent dans la colonne i


void actualiseregion(char** tabregion,int dim, int k,int i, int j,int boolean) ;
// si on rempli la case (i,j) par un essai on veut actualisé le fait que la region coresspondante ne peut pas avoir le caractere correspondant à k que l'on vient de mettre.
// au contraire si on a teste que l'essai à la case (i,j) ne permet pas de résoudre le sudoku, on veut que actualiser le fait que l'essai
//peut etre présent dans la région correspondante
//cette fonction met donc la case (region,k-1) du tableau tabregion à la valeur boolean qui vaut 0 ou 1 ;

void actualiseligne(char** tabligne,int dim,int k,int i,int boolean) ;

unsigned char convert_int_char(int k,int dim);



void actualisecolonne(char** tabcolonne,int dim,int k ,int j,int boolean);
