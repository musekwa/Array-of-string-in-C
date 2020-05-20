#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimeTodosNomes(char **nomes){
  int i = 0;
  printf("\nOs Nomes sao...\n");
  while (nomes[i] != NULL){
    printf ("%s  ", nomes[i]);
    i++;
  }
}

void imprimeNomesComAS(char **nomes){
  int i = 0;
  printf("\nOs Nomes que contem \'as\' sao...\n");
  while (nomes[i] != NULL){
    printf("Estou dentro\n");
  
    if (strlen(nomes[i]) < 2){
      continue;
    }
    char a, s;
    for(int j = 1; j <= strlen(nomes[i]); j++){
      if ((nomes[i][j-1] == 'a' || nomes[i][j-1] == 'A' )&& (nomes[i][j] == 's' || nomes[i][j-1] == 'S')){
        printf(" %s ", nomes[i]);
        continue;
      }
    }

    i++;
  }
}

void criaListaDeNomes(){
  int count = 1;
  int it = 0;
  int size = 2;
  char **nomes;
  char **tmp;
  nomes = malloc(sizeof(char*)*size);
  int length = sizeof(nomes);
   
  while (1){
    nomes[it] = malloc(50*sizeof(char));
    printf("Introduza nome (ou \'fim\' para terminar): ");
    char *aux = malloc(50*sizeof(char));
    scanf("%s", aux);
    if (strcmp(aux, "fim")==0){
      break;
    }
    strcpy(nomes[it], aux);
    
    tmp = malloc(sizeof(char*)*size);
    memcpy(tmp, nomes, sizeof(nomes)+sizeof(char*)*it);
    free(nomes);
    count++;
    size++;
    it++;
    nomes = tmp;
    tmp = NULL;
  }
  
  imprimeTodosNomes(nomes);
  imprimeNomesComAS(nomes);
}


int main(void) {

  criaListaDeNomes();

  return 0;
}
