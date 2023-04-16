#include "representation_sudoku.h"


unsigned char** allocation_tab(int dimension){

  int i ;
  unsigned char** grille =NULL ;

  grille = calloc(dimension,sizeof(*grille ));
  if(grille==NULL){return NULL;}

  for(i=0;i<dimension;i++){
    grille[i]=calloc(dimension,sizeof(unsigned char));
    if (grille[i]==NULL){return NULL;}

  }
  return(grille);
}




grid_t grid_new(int dim){
  grid_t grid ;
  grid.data = allocation_tab(dim);
  grid.size = dim ;
  return grid ;
}




grid_t lecture_grille(char* fichier,int dim){

  grid_t grid = grid_new(dim);

  FILE * fic = fopen(fichier,"r");
  if(fic==NULL){
    fprintf(stderr, "ouverture du fichier %s impossible",fichier );
    return(grid);
  }

  unsigned char c ;

  int i,j ;


  for(i=0;i<dim;i++){
    for(j=0;j<dim;j++){
      c=fgetc(fic);
      grid.data[i][j]= c ;
      }
      fgetc(fic);
    }
    fclose(fic);

    return(grid);
  }




void grid_delete(grid_t grid){

  int  i ;
  for(i=0;i<grid.size;i++){
    free(grid.data[i]);
  }
  free(grid.data);
  grid.size = 0 ;
}



void grid_print(grid_t grid){

  int i,j ;
  int dim =grid.size ;

  for(i=0;i<dim;i++){

    for(j=0;j<dim;j++){
      printf("%c  ",grid.data[i][j] );
    }
    printf("\n");
  }
  printf("\n\n" );
  }



void affichetab2char(char** tab, int n){
  int i , j ;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%c  ", tab[i][j]);
    }
    printf("\n" );
  }
}



void affichetabchar(char * tab,int n){
  int i;
  for(i=0;i<n;i++){
    printf("%c ",tab[i] );
  }
  printf("\n" );
}

void affichetabint(int * tab, int n){
  int i;
  for(i=0;i<n;i++){
    printf("%d ",tab[i] );
  }
  printf("\n" );
}




int dimension(char *fichier){
  FILE  * fic = fopen(fichier,"r");
  if(fic==NULL){
    fprintf(stderr, "ouverture du fichier %s impossible",fichier );
    return 0 ;
  }
  unsigned char c = fgetc(fic);
  int n =0;
  while(c!='\n'){
    n++ ;
    c=fgetc(fic);
  }
  fclose(fic);
  return(n);

}
