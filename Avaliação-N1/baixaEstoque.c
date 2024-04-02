#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct EstruturaVenda{
  int codigo;
  int quantidade;
};

typedef struct EstruturaVenda venda;

void AlterarProduto(venda * Venda, int codigo, int quantidade){
  Venda->codigo = codigo;
  Venda->quantidade = quantidade;
}

int PassagemPorReferencia(){
  venda venda1;
  printf("Digite o código do produto a ser alterado: ");
  scanf("%d", &venda1.codigo);

  if(venda1.codigo == )

  printf("Código novo: %d\n", venda1.codigo);
  scanf("%d", &venda1.codigo);
  printf("Quantidade nova %d\n", venda1.quantidade);
  scanf("%d", &venda1.quantidade);

  AlterarProduto(&venda1, venda1.codigo, venda1.quantidade);
  return 0;
}