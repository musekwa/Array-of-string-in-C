/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimeTodosNomes(char **nomes){
  int i = 0;
   printf("\n===========================================================\n\n");
  printf("\nTodos os nomes introduzidos sao...\n");
  while (nomes[i] != NULL){
    printf ("%s  ", nomes[i]);
    i++;
  }
  if(i == 0){
       printf("Desculpe, nenhum nome foi introduzido'\n");
  }
}

void imprimeNomesComAS(char **nomes){
  int i = 0;
  int contador = 0;
   printf("\n===========================================================\n\n");
  printf("\nOs nomes que contem a sequencia de letras \'as\' sao...\n");
  while (nomes[i] != NULL){
    if (strlen(nomes[i]) >= 2){    
      char a, s;
      for(int j = 1; j <= strlen(nomes[i]); j++){
        if ((nomes[i][j-1] == 'a' || nomes[i][j-1] == 'A' )&& (nomes[i][j] == 's' || nomes[i][j] == 'S')){
          printf("%s  ", nomes[i]);
          contador++;
          break;
        }
      }
    }
    i++;
  }
  if (contador == 0){
      printf("Desculpe, nenhum nome contem a sequencia de letas \'as\'\n");
  }
  printf("\n===========================================================\n\n");
}

void criaListaDeNomes(){
  int count = 1;
  int it = 0;
  int size = 2;
  char **nomes;
  char **tmp;
  nomes = malloc(sizeof(char*)*size);
  int length = sizeof(nomes);
  printf("\n===========================================================\n\n");
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

