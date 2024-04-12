#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../rastrearPacote/rastrearPacote.h"

void rastrearPacote(struct PACOTE *inicio, int id){
  struct PACOTE *atual = inicio;

  if (id == 0) { 
    while (atual != NULL) {
      printf("ID: %d\n", atual->id);
      printf("Cidade de Origem: %s\n", atual->cidOrig);
      printf("Cidade de Destino: %s\n", atual->cidDest);
      printf("Status: %d\n", *atual->status);
      printf("Conteúdo: %s\n", atual->conteudo);
      printf("_________________________________________\n");
      printf("_________________________________________\n");
      atual = atual->proximo;
    }
  } else { 
    while (atual != NULL){
      if (atual->id == id) {
        printf("Pacote encontrado:\n");
        printf("ID: %d\n", atual->id);
        printf("Cidade de Origem: %s\n", atual->cidOrig);
        printf("Cidade de Destino: %s\n", atual->cidDest);
        printf("Status: %d\n", *atual->status);
        printf("Conteúdo: %s\n", atual->conteudo);
        
        return;
      }
      atual = atual->proximo;
    }
    printf("Pacote não encontrado\n");
  }
}