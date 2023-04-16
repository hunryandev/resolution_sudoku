#include "possibilite.h"




int nbpossibilite(grid_t grid,char** tabregion, char** tabligne,char** tabcolonne,case_tab c){



  int dim=grid.size;
  int nbpos = 0 ;

  if (grid.data[c.i][c.j] != '0' && grid.data[c.i][c.j] !=' '){
    return nbpos ;
  }

  else{
    // la case (i,j) est vide
    int taille =(int) sqrt(dim);
    int col ;
    int region = taille*(c.i/taille) + c.j/taille ;

    for(col=0;col<dim;col++){

      if(tabregion[region][col]=='1' || tabligne[c.i][col]=='1' || tabcolonne[c.j][col]=='1'){
      }
      else{nbpos ++ ;
      }
      }
    if(nbpos == 0 ){
      //cas ou la case c est vide mais il n'ya pas de possibilité de remplissage
      nbpos = -1 ;
    }
    return nbpos ;
}
}


int * possibilitecase(grid_t grid,char** tabregion, char** tabligne,char** tabcolonne, case_tab c ,int nbpos){

  if (nbpos <= 0 ){
    return NULL ;
  }
  else {

    int* listepos = NULL;
    listepos=calloc(nbpos,sizeof(int));

    int dim=grid.size;
    int k = 0 ;

    int taille =(int) sqrt(dim);
    int col ;
    int region = taille*(c.i/taille) + c.j/taille ;
    for(col=0;col<dim;col++){

      if(tabregion[region][col]=='1' || tabligne[c.i][col]=='1' || tabcolonne[c.j][col]=='1'){
      }
      else{listepos[k]=col +1  ;k++;}
    }
    return listepos ;
  }
}



void case_contraignante(grid_t grid,char** tabregion, char** tabligne,char** tabcolonne,case_tab * cpointer){

  cpointer->i = -1;
  cpointer->j = -1;

  case_tab c ;
  int i, j ;
  int dim = grid.size ;
  int nbpos ;
  int min = dim + 1;

  for(i=0;i<dim;i++){
    for(j=0;j<dim;j++){
      c.i = i ;
      c.j= j ;
      nbpos = nbpossibilite(grid,tabregion,tabligne,tabcolonne,c) ;
      if(nbpos!=0){
        if(nbpos < min){
          min = nbpos ;
          cpointer->i = i;
          cpointer->j = j;
        }

      }


}
}
}

int nombrevide(grid_t grid){

  int compteur = 0 ;
  int i,j ;
  int dim =grid.size ;
  for(i=0;i<dim;i++){
    for(j=0;j<dim;j++){
      if(grid.data[i][j]=='0'){
        compteur ++ ;
      }
  }
}
return compteur ;
}
