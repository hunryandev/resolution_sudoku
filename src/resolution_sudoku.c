#include "resolution_sudoku.h"


int resolution_optimisee(grid_t grid){

char ** tabregion = init_verif_region(grid);
char ** tabligne = init_verif_ligne(grid);
char ** tabcolonne = init_verif_colonne(grid);

return(resolution_opt(grid,tabregion,tabligne,tabcolonne));
}


int resolution_opt(grid_t grid,char **tabregion, char** tabligne, char**tabcolonne){

int dim =grid.size ;
case_tab c ;
case_contraignante(grid ,tabregion, tabligne, tabcolonne, &c); // puisque nombrevide != 0 on est sure que une case sera retourné par cette fonction

if (c.i==-1 && c.j==-1){
  return GAGNE ;
}

int nbpos = nbpossibilite(grid,tabregion,tabligne,tabcolonne,c) ;
if(nbpos == -1){
  return IMPOSSIBLE ;
}

else{

    int *listepos = possibilitecase(grid,tabregion,tabligne,tabcolonne,c,nbpos);
    int k ;
    char essai ;

    for(k=0;k<nbpos;k++){

      essai = convert_int_char(listepos[k],dim);


      grid.data[c.i][c.j]= essai;

      actualiseregion(tabregion,dim,listepos[k],c.i,c.j,1);
      actualiseligne(tabligne,dim,listepos[k],c.i,1);
      actualisecolonne(tabcolonne,dim,listepos[k],c.j,1);


      if(resolution_opt(grid, tabregion, tabligne, tabcolonne)==GAGNE){
        return GAGNE ;
      }
      else{
        actualiseregion(tabregion,dim,listepos[k],c.i,c.j,0);
        actualiseligne(tabligne,dim,listepos[k],c.i,0);
        actualisecolonne(tabcolonne,dim,listepos[k],c.j,0);

        grid.data[c.i][c.j]='0';


      }
    }
    return IMPOSSIBLE ;
    }
}
