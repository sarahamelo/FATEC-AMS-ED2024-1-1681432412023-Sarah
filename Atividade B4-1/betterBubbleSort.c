#include <stdio.h>
#include <stdbool.h>

// Função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função Bubble Sort com otimização
void bubbleSort(int arr[], int n) {
    bool trocou;
    for (int i = 0; i < n-1; i++) {
        trocou = false; // Verificação de troca
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                trocou = true;
            }
        }
        // Se não houve troca, o array já está ordenado
        if (!trocou) {
            break;
        }
    }
}

// Função para exibir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    
    // Solicitar a entrada do número de elementos
    printf("Digite o número de elementos: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Ler os elementos do array
    printf("Digite os elementos:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Mostrar o array original
    printf("Array original: ");
    printArray(arr, n);
    
    // Ordenar o array usando Bubble Sort
    bubbleSort(arr, n);
    
    // Mostrar o array ordenado
    printf("Array ordenado: ");
    printArray(arr, n);
    
    return 0;
}
