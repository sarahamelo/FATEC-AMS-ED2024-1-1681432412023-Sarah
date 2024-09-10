/*___________________________________________________________________________________*/
/*                                                                                   */
/*   Fatec - São Caetano Do Sul                Estrutura de Dados Profº Veríssimo    */
/*                                Sarah Melo                                         */
/*                    Objetivo: Análise Assintótica dos algorimos                    */
/*                                                                                   */
/*                                                            09/08/24               */
/*___________________________________________________________________________________*/

#include <stdio.h>

int busca_binaria(int arr[], int esquerda, int direita, int x) {
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (arr[meio] == x)
            return meio;
        if (arr[meio] < x)
            esquerda = meio + 1;
        else
            direita = meio - 1;
    }
    return -1;
}

int buscaBinaria(){
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int resultado = busca_binaria(arr, 0, tamanho - 1, x);
    if (resultado != -1){
        printf("Elemento %d encontrado na posição %d\n", x, resultado);
    }
}
