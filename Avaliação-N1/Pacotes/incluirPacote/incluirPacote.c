#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../incluirPacote/incluirPacote.h"

void incluirPacote(struct PACOTE **inicio, int *id, char *cidOrig, char *cidDest, int *status, char *conteudo) {
    struct PACOTE *novoPacote = (struct PACOTE*)malloc(sizeof(struct PACOTE));
    if (novoPacote == NULL) {
        printf("Erro: impossível alocar memória\n");
        exit(EXIT_FAILURE);
    }

    *id = (*id % 2 == 0) ? *id : *id + 1;

    novoPacote->id = *id;
    strcpy(novoPacote->cidOrig, cidOrig);
    strcpy(novoPacote->cidDest, cidDest);
    novoPacote->status = (int *)malloc(sizeof(int)); // Aloca memória para o status
    *novoPacote->status = 1; // Inicializa o status com 1
    strcpy(novoPacote->conteudo, conteudo);

    novoPacote->proximo = *inicio;
    *inicio = novoPacote;

  (*id) = (*id) += 2;
}