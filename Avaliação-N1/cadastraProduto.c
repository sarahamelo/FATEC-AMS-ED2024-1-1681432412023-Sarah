#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto{
  int idProd, quantProd;
  float precoProd;
  char nomeProd[50];
  struct Produto *proximo;
};

void cadastroProduto(struct Produto ** inicio, int idProd, int quantProd, float precoProd, char nomeProd[50]){

  struct Produto *novoProduto = (struct Produto*)malloc(sizeof(struct Produto));

  novoProduto->idProd = idProd;
  novoProduto->quantProd= quantProd;
  novoProduto->precoProd = precoProd;
  strcpy(novoProduto->nomeProd, nomeProd);

  novoProduto->proximo = *inicio;
  *inicio = novoProduto;

}
tem menu de contexto