#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../alterarPacote/alterarPacote.h"

void alterarPacote(struct PACOTE **inicio, int idProd){
  struct PACOTE *ptr = *inicio;
  int novoStatus;

  while (ptr != NULL){
    if (ptr->id == idProd){
      printf("Digite o novo status de acordo: \n");
      printf("1 - Em trânsito \n");
      printf("2 - Em espera \n");
      printf("3 - Entregue \n");
      printf("99 - Extraviado \n");
      printf("Digite: ");
      scanf("%d", &novoStatus);

      if(novoStatus == 1 | novoStatus == 2 | novoStatus == 3 | novoStatus == 99){
        *(ptr->status) = novoStatus;
      }
      else{
        printf("Status inválido, tente novamente.\n");
      }
    }
    ptr = ptr->proximo;
  }
}