#include <stdio.h>

struct Produto{
  int idProd, quantProd;
  float precoProd;
  char nomeProd[50];
  struct Produto *proximo;
};

void Busca(struct Produto ** inicio, int idProd){

  struct Produto *ptr = *inicio;

  while(ptr != NULL){
    if(ptr->idProd == idProd){
      printf("Busca de Produto por ID\n");
      printf("\nProduto encontrad\n");
      printf("Quantidade em estoque:%d\n", ptr->quantProd);
      printf("Preço: R$%.2f\n", ptr->precoProd);
      printf("Nome: %s\n", ptr->nomeProd);

      return;
    }
    ptr = ptr->proximo;
  }
  printf("Produto não encontrado");
}
tem menu de contexto