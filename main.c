
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//tipo de dado 'boolean' definido pelo utilizador
enum Boolean{
    true=1, false=0
};

typedef enum Boolean boolean;


void imprimeTodosNomes(char **nomes, int tamanho){
    /*
    * parametro: vetor de strings (char **)
    * valor de retorno: void
    * mostrar todos os nomes introduzidos no vetor de strings
    */
    int i = 0;
    printf("\n===========================================================\n\n");
    printf("\nTodos os nomes introduzidos sao...\n");
    
    //iterar o vetor de strings ate o ultimo
    while (i < tamanho){
        printf ("%s  ", nomes[i]);
        i++;
    }
    //informar, caso nenhum nome tenha sido encontrado
    if(i == 0){
        printf("Desculpe, nenhum nome foi introduzido'\n");
    }
}

void imprimeNomesComAS(char **nomes, int tamanho){
    /*
    * parametro: vetor de strings (char **)
    * valor de retorno: void
    * mostrar apenas os nomes que contem a sequencia
    * de letras 'as' ou 'AS' ou 'As' ou 'aS'
    */
    int i = 0;
    int contador = 0;
  
    printf("\n===========================================================\n\n");
    printf("\nOs nomes que contem a sequencia de letras \'as\' sao...\n");
    
    //ler iterar o vetor de string ate o ultimo
    while (i < tamanho){
        //O nome tem de ter o tamanho de pelos 2
        if (strlen(nomes[i]) >= 2){    
            //Fazer a verredura do nome para procura a sequencia e 
            //caso encontrar a sequencia num nome, pare e salte para 
            //o proximo nome
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
    //Caso nenhum nome tenha a sequencia de letra procurada
    if (contador == 0){
        printf("Desculpe, nenhum nome contem a sequencia de letas \'as\'\n");
    }
    printf("\n===========================================================\n\n");
}

void criaListaDeNomes(){
    /*
    * parametro: void
    * valor de retorno: void
    * criar um vetor e introduzir iterativamente neles todos os 
    * nomes lidos do utilizador ate que a palavra 'fim' seja lido.
    */

  int contador = 0;
  int it = 0;
  int size = 2;
  char **nomes;
  char **tmp;
  boolean verifica = true;
  nomes = malloc(sizeof(char*)*size);
  int length = sizeof(nomes);
  printf("\n===========================================================\n\n");
  
  // iterar ate infinitamente para ler nomes introduzidos pelo utilizador
  while (verifica){
    nomes[it] = malloc(50*sizeof(char));
    printf("Introduza nome (ou \'fim\' para terminar): ");
    char *aux = malloc(50*sizeof(char));
    scanf("%s", aux);
    
    // verificar se o nome introduzido corresponde a palavra 'fim'
    // e caso corresponda, pare imediatemente com a iteracao
    if (strcmp(aux, "fim")==0){
      break;
    }
    
    // copiar o nomes para o vetor de strings
    strcpy(nomes[it], aux);
    
    // vetor auxiliar de strings para servir na incrementacao
    // dinamica do tamanho do vetor 'nomes'
    tmp = malloc(sizeof(char*)*size);
    
    // copiar todos os nomes do vetor 'nomes' para vetor o
    // vetor tmp e aumentar o tamanho de tmp
    memcpy(tmp, nomes, sizeof(nomes)+sizeof(char*)*it);
    
    // libertar a memoria ocupada pelo vetor 'nomes'
    free(nomes);
    contador++;
    size++;
    it++;
    
    // apontar o vetor 'nomes' para o vetor auxiliar atualizado 'tmp'
    // e apontar o tmp para NULL
    nomes = tmp;
    tmp = NULL;
  }
  
  imprimeTodosNomes(nomes, contador);
  imprimeNomesComAS(nomes, contador);
}


int main(void) {

  criaListaDeNomes();

  return 0;
}

