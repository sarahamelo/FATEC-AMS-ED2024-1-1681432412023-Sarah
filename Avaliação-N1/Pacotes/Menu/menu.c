#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Menu/menu.h"
#include "../incluirPacote/incluirPacote.h"

void exibirMenu(struct PACOTE **inicio) {
    int opcao;
    int id = 2;
    char cidOrig[50]; 
    char cidDest[50];
    char conteudo[50];
    int status = 1;

    do {
        printf("\nMENU:\n");
        printf("1. Incluir Pacote\n");
        printf("2. Alterar Pacote\n");
        printf("3. Rastrear Pacote\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                printf("Digite a cidade de Origem: ");
                fgets(cidOrig, sizeof(cidOrig), stdin);
                cidOrig[strcspn(cidOrig, "\n")] = '\0'; // Remove o '\n' do final
                printf("Digite a cidade de Destino: ");
                fgets(cidDest, sizeof(cidDest), stdin);
                cidDest[strcspn(cidDest, "\n")] = '\0'; // Remove o '\n' do final
                printf("Digite o conteúdo: ");
                fgets(conteudo, sizeof(conteudo), stdin);
                conteudo[strcspn(conteudo, "\n")] = '\0'; // Remove o '\n' do final
                incluirPacote(inicio, &id, cidOrig, cidDest, &status, conteudo);
                break;
            case 2:
                printf("Digite o id do pacote: ");
                scanf("%d", &id);
                alterarPacote(inicio, id);
                break;
            case 3:
                printf("Digite o id do pacote ou digite '0' para ver todos: ");
                scanf("%d", &id);
                rastrearPacote(*inicio, id);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);
}