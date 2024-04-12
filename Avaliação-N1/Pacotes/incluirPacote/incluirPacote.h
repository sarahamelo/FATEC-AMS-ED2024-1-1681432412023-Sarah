#ifndef INCLUIR_H
#define INCLUIR_H

struct PACOTE {
  int id;
  char cidOrig[50]; 
  char cidDest[50];
  int *status;
  char conteudo[50];
  struct PACOTE *proximo;
};

void incluirPacote(struct PACOTE **inicio, int *id, char *cidOrig, char *cidDest, int *status, char *conteudo);

#endif