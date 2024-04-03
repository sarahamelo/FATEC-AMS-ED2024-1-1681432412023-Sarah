#include <stdio.h>
#include <stdlib.h>
#include "../baixaEstoque/baixaEstoque.h"

void baixaEstoque(struct Produto **inicio) {
    int idProd, novaQuantidade;
    printf("Digite o código do produto: ");
    scanf("%d", &idProd);
    printf("Digite a nova quantidade: ");
    scanf("%d", &novaQuantidade);
    struct Produto *ptr = *inicio;
    while (ptr != NULL) {
        if (ptr->idProd == idProd) {
            ptr->quantProd = novaQuantidade;
            printf("Quantidade do produto de código %d alterada para %d.\n", ptr->idProd, novaQuantidade);
            return;
        }
        ptr = ptr->proximo;
    }
    printf("Produto com código %d não encontrado.\n", idProd);
}