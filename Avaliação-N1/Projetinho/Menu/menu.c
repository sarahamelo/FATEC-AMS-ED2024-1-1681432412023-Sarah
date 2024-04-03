#include <stdio.h>
#include <stdlib.h>
#include "../Menu/menu.h"
#include "../cadastrarProduto/cadastraProduto.h"

void exibirMenu(struct Produto **inicio) {
    int opcao;
    char nome[50]; // Variável para armazenar o nome do produto
    int idProd; // Variável para armazenar o id do produto

    do {
        printf("\nMENU:\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Buscar Produto\n");
        printf("3. Dar Baixa no Estoque\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome do produto: ");
                scanf("%s", nome);
                printf("Digite o preço do produto: ");
                float preco;
                scanf("%f", &preco);
                printf("Digite a quantidade em estoque: ");
                int quantidade;
                scanf("%d", &quantidade);
                cadastraProduto(inicio, idProd, nome, preco, quantidade);
                break;
            case 2:
                printf("Digite o id do produto: ");
                scanf("%d", &idProd);
                buscaProduto(inicio, idProd);
                break;
            case 3:
                baixaEstoque(inicio);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);
}