#include <stdio.h>

int main() {
    int numeroInteiros[5];
    int quantidade = sizeof(numeroInteiros) / sizeof(numeroInteiros[0]);
    int i, j, temp;

    // Entrada de 5 números aleatórios
    printf("Entre com %d números inteiros e positivos:\n", quantidade);
    for (i = 0; i < quantidade; i++) {
        scanf("%d", &numeroInteiros[i]);
    }

    // Ordenar os números em ordem crescente
    for (i = 0; i < quantidade; i++) {
        for (j = i + 1; j < quantidade; j++) {
            if (numeroInteiros[i] > numeroInteiros[j]) {
                temp = numeroInteiros[i];
                numeroInteiros[i] = numeroInteiros[j];
                numeroInteiros[j] = temp;
            }
        }
    }

    // Mostrar os números ordenados
    printf("\nNúmeros em ordem crescente:\n");
    for (i = 0; i < quantidade; i++) {
        printf("%d ", numeroInteiros[i]);
    }
    printf("\n");

    return 0;
}