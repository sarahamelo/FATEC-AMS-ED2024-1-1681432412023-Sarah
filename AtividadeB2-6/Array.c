#include <stdio.h>
#include <time.h>

void inserir_no_array(int arr[], int *n, int pos, int valor) {
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = valor;
    (*n)++;
}

int main() {
    int arr[10] = {10, 25, 40, 80};
    int n = sizeof(arr[10]); // Número atual de elementos no array
    int valor = 30;
    int pos = n / 2; // Inserir no meio do array

    clock_t inicio, fim;
    double tempo_gasto;

    inicio = clock();
    inserir_no_array(arr, &n, pos, valor);
    fim = clock();

    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Array após inserção: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTempo de processamento: %f segundos\n", tempo_gasto);

    return 0;
}
