#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastrarProduto/cadastraProduto.h"
#include "buscaProduto/buscaProduto.h"
#include "baixaEstoque/baixaEstoque.h"
#include "Menu/menu.h"

/*___________________________________________________________________________________*/
/*                                                                                   */
/*   Fatec - São Caetano Do Sul                Estrutura de Dados Profº Veríssimo    */
/*                          Sarah Melo & Agata Cecilia                               */
/*                    Objetivo: Manipulando Lista Ligada                             */
/*                    Paradigma: Usar nó e ponteiros                                 */
/*                                                                                   */
/*                                                            02/04/24               */
/*___________________________________________________________________________________*/

int main(void) {
    struct Produto *inicio = NULL;
    exibirMenu(&inicio);
    return 0;
}