#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "incluirPacote/incluirPacote.h"
#include "rastrearPacote/rastrearPacote.h"
#include "alterarPacote/alterarPacote.h"
#include "Menu/menu.h"

/*___________________________________________________________________________________*/
/*                                                                                   */
/*   Fatec - São Caetano Do Sul                Estrutura de Dados Profº Veríssimo    */
/*                          Sarah Melo & Agata Cecilia                               */
/*                    Objetivo: Incluir, alterar e rastrear pacotes                  */
/*                    Paradigma: Usar nó, ponteiros e struct                         */
/*                                                                                   */
/*                                                            12/04/24               */
/*___________________________________________________________________________________*/

int main(void) {
    struct PACOTE *inicio = NULL;
    exibirMenu(&inicio);
    return 0;
}