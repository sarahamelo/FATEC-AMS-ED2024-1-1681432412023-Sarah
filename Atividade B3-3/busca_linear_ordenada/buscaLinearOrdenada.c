/*___________________________________________________________________________________*/
/*                                                                                   */
/*   Fatec - São Caetano Do Sul                Estrutura de Dados Profº Veríssimo    */
/*                                Sarah Melo                                         */
/*                    Objetivo: Análise Assintótica dos algorimos                    */
/*                                                                                   */
/*                                                            09/08/24               */
/*___________________________________________________________________________________*/

#include <stdio.h>

int busca_linear_ordenada(int arr[], int tamanho, int x) {
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == x)
            return i;
        if (arr[i] > x)
            return -1;
    }
    return -1;
}

int buscaLinearOrdenada(){
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int resultado = busca_linear_ordenada(arr, tamanho, x);
    if (resultado != -1){
        printf("Elemento %d encontrado na posição %d\n", x, resultado);
    }
}