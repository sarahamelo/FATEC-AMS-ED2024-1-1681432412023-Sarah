#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../buscaProduto/buscaProduto.h"

void buscaProduto(struct Produto **inicio, int idProd) {
    struct Produto *ptr = *inicio;
    while (ptr != NULL) {
        if (ptr->idProd == idProd) {
            printf("Busca de Produto por ID\n");
            printf("\nProduto encontrado\n");
            printf("Quantidade em estoque: %d\n", ptr->quantProd);
            printf("Preço: R$%.2f\n", ptr->precoProd);
            printf("Nome: %s\n", ptr->nomeProd);
            return;
        }
        ptr = ptr->proximo;
    }
    printf("Produto não encontrado\n");
}