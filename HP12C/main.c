#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <criarPilha.h>

int main(void) {
  struct Pilha{
  int topo;
  int capa;
  float *pElem;
  };
  struct Pilha minhaPilha;
  
  printf("Capacidade da pilha? ");
  scanf("%d", &minhaPilha.capa);

  criarPilha(&minhaPilha, minhaPilha.capa);

  processaPilha(&minhaPilha);
  
}