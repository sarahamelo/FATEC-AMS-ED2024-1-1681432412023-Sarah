#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <criarPilha.c>

void criarPilha(struct Pilha *p, int c){
  p->topo = -1;
  p->capa = c;
  p->pElem = (float*) malloc (c * sizeof(float));
}