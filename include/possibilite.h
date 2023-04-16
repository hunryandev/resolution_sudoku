#include "verification.h"
#include <string.h>




typedef struct {int i ; int j ;
} case_tab;


int nbpossibilite(grid_t grid,char** tabregion, char** tabligne,char** tabcolonne,case_tab c) ;
// renvoie 0 si  la case est déja rempli, renvoie -1 si la case n'est pas rempli mais qu'il n'ya aucune possibilité,
// sinon renvoie le nombre de possibilite pour cette case


int * possibilitecase(grid_t grid,char** tabregion, char** tabligne,char** tabcolonne, case_tab c,int nbpos);
// dans cette fonction on retourne pour une case i,j une liste d'int de taille nbpos ou chaque élement est un charactere possible pour cette case




void case_contraignante(grid_t grid,char** tabregion, char** tabligne,char** tabcolonne,case_tab * cpointer);
// retourne la case vide avec le moins de nombre de possibilité, si toutes les cases sont remplis, renvoie vers (-1,-1)


int nombrevide(grid_t grid);
