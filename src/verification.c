#include "verification.h"


int test_region(grid_t grid,int region_i,int chiffre_j){
int dim = grid.size ;
  int taille =(int) sqrt(dim);

int dl =taille*(region_i/taille) ;
int dc = taille*(region_i%taille);
//région i : coordonné:  ligne = taille *(i/taille) colonne =taille*(i%taille)

char essai = convert_int_char(chiffre_j,dim);

  int l, c ;
  for(l=dl;l<dl+taille;l++){
    for(c=dc;c<dc+taille;c++){

      if(grid.data[l][c]==essai){
        return 1;
      }
    }
  }
  return 0 ;
}


int test_ligne(grid_t grid, int ligne_i,int chiffre_j){

  int dim =grid.size ;
  int c ;
  unsigned char essai = convert_int_char(chiffre_j,dim);
  //printf("essai : %c\n", essai );
  for(c=0;c<dim;c++){
    //printf("l'essai : %c , la case (%d,%d):%c",essai,ligne_i,c,grid.data[ligne_i][c]);
    if(grid.data[ligne_i][c]==essai){
      return 1 ;
    }
  }
    return 0 ;
}


int test_colonne(grid_t grid, int colonne_i, int chiffre_j){

int dim = grid.size ;
int l ;

char essai = convert_int_char(chiffre_j,dim);
for(l=0;l<dim;l++){
  if(grid.data[l][colonne_i]==essai){
    return 1 ;
  }
}
  return 0 ;
}


unsigned char convert_int_char(int k,int dim){
  if(dim<16){
    return(k+'0');
  }
  else{
    char lettre[27] ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return(lettre[k-1]);
  }
}



char ** init_verif_region(grid_t grid){
int dim = grid.size ;


char ** tabbinaire = allocation_tab(dim);
if(tabbinaire==NULL){
  return NULL ;
}

int i,k ;
unsigned char j ;

  for(i=0;i<dim;i++){
    for(k=1;k<dim+1;k++){

      tabbinaire[i][k-1]=test_region(grid,i,k)+'0';

    }

  }
  return tabbinaire ;

}


char ** init_verif_ligne(grid_t grid){

int dim = grid.size ;
  char ** tabbinaire = allocation_tab(dim);
  if(tabbinaire==NULL){
    return NULL ;
  }

  int i,k;



  for(i=0;i<dim;i++){
    for(k=1;k<dim+1;k++){
      tabbinaire[i][k-1]=test_ligne(grid,i,k)+'0';
    }
  }
  return tabbinaire ;

}

char ** init_verif_colonne(grid_t grid){
  // on veut initialiser un tableau dont le point (i,j)nous dit si le  chiffre j est présent dans la région i
int dim = grid.size ;

  char ** tabbinaire = allocation_tab(dim);
  if(tabbinaire==NULL){
    return NULL ;
  }

  int i,k ;

  for(i=0;i<dim;i++){
    for(k=1;k<dim+1;k++){

      tabbinaire[i][k-1]=test_colonne(grid,i,k)+'0';
    }
  }
  return tabbinaire ;
}


void actualiseregion(char** tabregion,int dim,int essai,int i, int j, int boolean){

  int taille =(int) sqrt(dim);
  int region = taille*(i/taille) + j/taille ;


  tabregion[region][essai-1] = boolean +'0' ;

}


void actualiseligne(char** tabligne,int dim,int essai,int i,int boolean){

  tabligne[i][essai-1] = boolean+'0' ;

}


void actualisecolonne(char** tabcolonne,int dim,int essai ,int j,int boolean){

  tabcolonne[j][essai-1]= boolean+'0' ;
}
