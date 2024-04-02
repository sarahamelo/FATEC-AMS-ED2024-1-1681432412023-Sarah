/*___________________________________________________________________________________*/
/*                                                                                   */
/*   Fatec - São Caetano Do Sul                Estrutura de Dados Profº Veríssimo    */
/*                                Sarah Melo                                         */
/*                    Objetivo: Manipulando Lista Ligada                             */
/*                    Paradigma: Usar nó e ponteiros                                 */
/*                                                                                   */
/*                                                            02/04/24               */
/*___________________________________________________________________________________*/

#include <stdio.h>
#include <stdlib.h>

#define tamanho_array 5

struct No {
    int numero;
    struct No *prox;
};

typedef struct No no;

// Funções
void CriarNo(no * LISTA);
no* Incluir();
int Consultar();
no* Deletar();
void ListarTodos();
void LiberarLista();
void opcao(no * LISTA, int *opt);
void trataOpcao(no * LISTA, int opt, int valor, int posicao);

// CRIAÇÃO DO NÓ
void CriarNo(no *LISTA) {
    LISTA->prox = NULL;
}

// MENU DE OPÇÕES
void opcao(no *LISTA, int *opt) {
    printf("\nO que deseja fazer?\n");
    printf("1 - Incluir\n");
    printf("2 - Consultar\n");
    printf("3 - Deletar\n");
    printf("4 - Listar todos\n");
    printf("5 - Sair\n");

    scanf("%d", opt);
}

// TRATAR AS OPÇÕES
void trataOpcao(no *LISTA, int opt, int valor, int posicao) {
    switch (opt) {
        case 1:
            printf("Digite o valor a incluir: ");
            scanf("%d", &valor);
            LISTA->prox = Incluir(LISTA->prox, valor);
            break;
        case 2:
            printf("Digite a posição a consultar: ");
            scanf("%d", &posicao);
            printf("Valor na posição %d: %d\n", posicao, Consultar(LISTA, posicao));
            break;
        case 3:
            printf("Digite o valor a deletar: ");
            scanf("%d", &valor);
            LISTA->prox = Deletar(LISTA->prox, valor);
            break;
        case 4:
            ListarTodos(LISTA->prox);
            break;
        case 5:
            LiberarLista(LISTA->prox);
            exit(0);
            break;
        default:
            printf("Opção inválida\n");
    }
}

// INCLUIR COMEÇO DA LISTA
no *Incluir(no *LISTA, int valor) {
    no *novoNo = (no *)malloc(sizeof(no));
    if (novoNo == NULL) {
        printf("Erro: Não foi possível alocar memória\n");
        exit(EXIT_FAILURE);
    }
    novoNo->numero = valor;
    novoNo->prox = LISTA;
    return novoNo;
}

// CONSULTAR A LISTA
int Consultar(no *LISTA, int posicao) {
  int contador = 0;
  no* atual = LISTA;
  while (atual != NULL) {
      if (contador == posicao) {
          return atual->numero;
      }
      atual = atual->prox;
      contador++;
  }
  printf("Erro: Posição inválida\n");
  return 0;
}

// DELETAR VALOR DA LISTA
no *Deletar(no *LISTA, int valor) {
    no *atual = LISTA;
    no *anterior = NULL;

    while (atual != NULL && atual->numero != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Erro: Elemento não encontrado\n");
        return LISTA;
    }

    if (anterior == NULL) {
        LISTA = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    return LISTA;
}

// LISTAR TODOS OS VALORES DA LISTA
void ListarTodos(no *LISTA) {
    no *p;
    for (p = LISTA; p != NULL; p = p->prox)
        printf("-> %d\n", p->numero);
}

// LIBERAR LISTA
void LiberarLista(no *lista) {
    no *atual = lista;
    no *proximo;
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

// MAIN
int main(void) {
    // Inicialização da lista
    no *LISTA = (no *)malloc(sizeof(no));
    if (!LISTA) {
        printf("Erro");
        exit(EXIT_FAILURE);
    }
    CriarNo(LISTA);

  // Chamando o menu de opções
    int opt;
    do {
        opcao(LISTA, &opt);
        trataOpcao(LISTA, opt, 0, 0);
    } while (opt != 5);

    return 0;
}
