#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/*___________________________________________________________________________________*/
/*                                                                                   */
/*   Fatec - São Caetano Do Sul                Estrutura de Dados Profº Veríssimo    */
/*                          Sarah Melo & Bianca Soares                               */
/*                    Objetivo: Calculadora HP12C em C                               */
/*                    Paradigma: Usar Estrutura de pilha e memórias X,Y,Z e T        */
/*                                                                                   */
/*                                                            12/04/24               */
/*___________________________________________________________________________________*/

#define STACK_SIZE 100

// Struct da Pilha
typedef struct {
    double items[STACK_SIZE];
    int top;
} Stack;

// Manipulação da pilha
void initialize(Stack *s) {
    s->top = -1;
}

// Se estiver cheia
bool isFull(Stack *s) {
    return s->top == STACK_SIZE - 1;
}

// Se estiver vazia
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Se estiver cheia, erro. Senão, adiciona ao topo
void push(Stack *s, double value) {
    if (isFull(s)) {
        printf("Cheio\n");
        exit(EXIT_FAILURE);
    }
    s->items[++s->top] = value;
}

// Se estiver vazia, erro. Senão, remove do topo
double pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Vazio\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top--];
}

// Função de execução de operações
double executeOperation(double operand1, double operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Error: Divisão por Zero\n");
                exit(EXIT_FAILURE);
            }
            return operand1 / operand2;
        default:
            printf("Error: Operador inválido\n");
            exit(EXIT_FAILURE);
    }
}

// Função principal
int main() {
    Stack stack;
    initialize(&stack);

    char input[STACK_SIZE * 2];
    printf("Digite a expressao em RPN: ");
    fgets(input, sizeof(input), stdin);

    int i = 0;
    while (input[i] != '\0') {
        // Se for um número, adiciona na pilha
        if (isdigit(input[i]) || (input[i] == '-' && isdigit(input[i + 1]))) {
            push(&stack, atof(&input[i]));
            while (isdigit(input[i]) || input[i] == '.') {
                i++;
            }
        // Se for operador ... 
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);
            double result = executeOperation(operand1, operand2, input[i]);
            push(&stack, result);
            i++;
        } else if (isspace(input[i])) {
            i++;
        // Se não for nenhum dos casos acima, erro
        } else {
            printf("Error: Caractére inválido\n");
            exit(EXIT_FAILURE);
        }
    }

    // Expressão inválida
    if (stack.top != 0) {
        printf("Error: Expressão inválida\n");
        exit(EXIT_FAILURE);
    }

    // Imprimir o resultado 
    printf("Resultado: %.2lf\n", stack.items[stack.top]);
    printf("Expressao algébrica: ");
    for (int j = 0; j < strlen(input); j++) {
        if (input[j] != '\n') {
            printf("%c ", input[j]);
        }
    }
    printf("\n");

    return 0;
}