#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* criar_no(int valor) {
    Node *novo_no = (Node*)malloc(sizeof(Node));
    novo_no->data = valor;
    novo_no->next = NULL;
    return novo_no;
}

void inserir_na_lista(Node **head, int pos, int valor) {
    Node *novo_no = criar_no(valor);
    if (pos == 0) {
        novo_no->next = *head;
        *head = novo_no;
        return;
    }

    Node *atual = *head;
    for (int i = 0; i < pos - 1 && atual != NULL; i++) {
        atual = atual->next;
    }
    if (atual == NULL) {
        return;
    }

    novo_no->next = atual->next;
    atual->next = novo_no;
}

void imprimir_lista(Node *head) {
    Node *atual = head;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");
}

int main() {
    Node *head = criar_no(10);
    head->next = criar_no(25);
    head->next->next = criar_no(40);
    head->next->next->next = criar_no(80);

    int valor = 30;
    int pos = 2; // Inserir no meio da lista (posição 2)

    clock_t inicio, fim;
    double tempo_gasto;

    inicio = clock();
    inserir_na_lista(&head, pos, valor);
    fim = clock();

    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Lista ligada após inserção: ");
    imprimir_lista(head);
    printf("Tempo de processamento: %f segundos\n", tempo_gasto);

    // Liberar a memória alocada
    Node *atual = head;
    Node *temp;
    while (atual != NULL) {
        temp = atual;
        atual = atual->next;
        free(temp);
    }

    return 0;
}
