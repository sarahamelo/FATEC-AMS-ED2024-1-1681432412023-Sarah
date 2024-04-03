#ifndef CADASTRAPRODUTO_H
#define CADASTRAPRODUTO_H

struct Produto {
    int idProd;
    int quantProd;
    float precoProd;
    char nomeProd[50];
    struct Produto *proximo;
};

void cadastraProduto(struct Produto **inicio, int idProd, char *nomeProd, float precoProd, int quantProd);

#endif