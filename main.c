#include "resolution_sudoku.h"


int main(int argc, char** argv){
  if(argc <2){
    printf("chemin vers le sudoku manquant");
    return ;
  }
  
  char * fic = argv[1];




  //exemple de résolution d'un sudoku

  grid_t grid ;

  int dim = dimension(fic);
  grid = lecture_grille(fic,dim);

  grid_print(grid);
  printf("dimension du fichier : %d\n",dim );


if(resolution_optimisee(grid)==GAGNE){printf("W\n");}
else{printf("L\n" );}

grid_print(grid);


grid_delete(grid);
return 0 ;
}
