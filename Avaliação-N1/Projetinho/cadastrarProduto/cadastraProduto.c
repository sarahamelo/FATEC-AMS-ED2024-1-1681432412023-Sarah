#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cadastrarProduto/cadastraProduto.h"

void cadastraProduto(struct Produto **inicio, int idProd, char *nomeProd, float precoProd, int quantProd) {
    struct Produto *novoProduto = (struct Produto*)malloc(sizeof(struct Produto));
    if (novoProduto == NULL) {
        printf("Erro: impossível alocar memória\n");
        exit(EXIT_FAILURE);
    }

    novoProduto->idProd = idProd;
    novoProduto->quantProd = quantProd;
    novoProduto->precoProd = precoProd;
    strcpy(novoProduto->nomeProd, nomeProd);

    novoProduto->proximo = *inicio;
    *inicio = novoProduto;
}