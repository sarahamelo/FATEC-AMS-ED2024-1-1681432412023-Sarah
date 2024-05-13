#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*___________________________________________________________________________________*/
/*                                                                                   */
/*   Fatec - São Caetano Do Sul                Estrutura de Dados Profº Veríssimo    */
/*                                Sarah Melo                                         */
/*                    Objetivo: Fila Hospitalar                                      */
/*                    Paradigma: Usar filas                                          */
/*                                                                                   */
/*                                                            13/05/24               */
/*___________________________________________________________________________________*/

// Estrutura para representar um paciente
typedef struct {
    char nome[50];
    int idade;
    char motivo_consulta[100];
} Paciente;

// Estrutura para representar um nó da fila
typedef struct Node {
    Paciente paciente;
    struct Node* prox;
} Node;

// Estrutura para representar uma fila
typedef struct {
    Node* inicio;
    Node* fim;
} Fila;

// Inicializa uma fila
void inicializarFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

// Verifica se a fila está vazia
int filaVazia(Fila* fila) {
    return (fila->inicio == NULL);
}

// Adiciona um paciente à fila
void adicionarPaciente(Fila* fila, Paciente paciente) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->paciente = paciente;
    novo->prox = NULL;
    if (filaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

// Remove e retorna o primeiro paciente da fila
Paciente removerPaciente(Fila* fila) {
    if (filaVazia(fila)) {
        Paciente pacienteVazio = {"", 0, ""};
        return pacienteVazio;
    } else {
        Node* temp = fila->inicio;
        Paciente paciente = temp->paciente;
        fila->inicio = fila->inicio->prox;
        if (fila->inicio == NULL) {
            fila->fim = NULL;
        }
        free(temp);
        return paciente;
    }
}
// Atende o próximo paciente, chamando apenas um paciente de qualquer fila por vez
void atenderProximoPaciente(Fila* filaUrgente, Fila* filaPreferencial, Fila* filaNormal) {

    // Verifica se há pacientes na fila urgente e atende o próximo, se houver
    if (!filaVazia(filaUrgente)) {
        Paciente paciente = removerPaciente(filaUrgente);
        printf("Chamando paciente urgente: %s\n", paciente.nome);
        // Simula o atendimento
        printf("Paciente %s sendo atendido no consultório 02 - urgente.\n", paciente.nome);
        return;
    }

    // Verifica se há pacientes na fila preferencial e atende o próximo, se houver
    if (!filaVazia(filaPreferencial)) {
        Paciente paciente = removerPaciente(filaPreferencial);
        printf("Chamando paciente preferencial: %s\n", paciente.nome);
        // Simula o atendimento
        printf("Paciente %s sendo atendido no consultório 04 - preferencial.\n", paciente.nome);
        return;
    }

    // Verifica se há pacientes na fila normal e atende o próximo, se houver
    if (!filaVazia(filaNormal)) {
        Paciente paciente = removerPaciente(filaNormal);
        printf("Chamando paciente normal: %s\n", paciente.nome);
        // Simula o atendimento
        printf("Paciente %s sendo atendido no consultório 06 - normal.\n", paciente.nome);
        return;
    }

    // Se não houver pacientes em nenhuma fila
    printf("Nenhum paciente na fila para atendimento.\n");
}



// Visualiza as informações da fila
void visualizarFila(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia.\n");
    } else {
        Node* atual = fila->inicio;
        while (atual != NULL) {
            printf("Nome: %s | Idade: %d | Motivo da consulta: %s\n", atual->paciente.nome, atual->paciente.idade, atual->paciente.motivo_consulta);
            atual = atual->prox;
        }
    }
}

int main() {
    Fila filaUrgente, filaPreferencial, filaNormal;
    inicializarFila(&filaUrgente);
    inicializarFila(&filaPreferencial);
    inicializarFila(&filaNormal);

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Adicionar paciente à fila\n");
        printf("2. Chamar próximo paciente\n");
        printf("3. Visualizar filas\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Paciente paciente;
                printf("Nome do paciente: ");
                scanf("%s", paciente.nome);
                printf("Idade do paciente: ");
                scanf("%d", &paciente.idade);
                printf("Motivo da consulta: ");
                scanf("%s", paciente.motivo_consulta);

                // Determina em qual fila adicionar o paciente
                char tipoConsulta[20];
                printf("Tipo de consulta (urgente, preferencial, normal): ");
                scanf("%s", tipoConsulta);
                if (strcmp(tipoConsulta, "urgente") == 0) {
                    adicionarPaciente(&filaUrgente, paciente);
                } else if (strcmp(tipoConsulta, "preferencial") == 0) {
                    adicionarPaciente(&filaPreferencial, paciente);
                } else if (strcmp(tipoConsulta, "normal") == 0) {
                    adicionarPaciente(&filaNormal, paciente);
                } else {
                    printf("Tipo de consulta inválido.\n");
                }
                break;
            }
            case 2: {
                printf("\nChamando próximos pacientes:\n");
                atenderProximoPaciente(&filaUrgente, &filaPreferencial, &filaNormal);
                break;
            }
            case 3: {
                printf("\nFilas de atendimento:\n");
                printf("Fila de pacientes urgentes:\n");
                visualizarFila(&filaUrgente);
                printf("\nFila de pacientes preferenciais:\n");
                visualizarFila(&filaPreferencial);
                printf("\nFila de pacientes normais:\n");
                visualizarFila(&filaNormal);
                break;
            }
            case 4: {
                printf("Encerrando o programa.\n");
                break;
            }
            default: {
                printf("Opção inválida.\n");
                break;
            }
        }
    } while (opcao != 4);

    return 0;
}
