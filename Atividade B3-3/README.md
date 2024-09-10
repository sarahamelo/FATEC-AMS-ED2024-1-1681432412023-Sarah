# Algoritmos de Busca em C - Análise Assintótica

Este repositório contém três algoritmos de busca implementados em linguagem C e suas respectivas análises assintóticas. A análise considera o **pior caso** para cada algoritmo e demonstra as funções de tempo, a simplificação para a notação Big O e gráficos comparativos.

## Algoritmos Implementados

1. **Busca Linear**
2. **Busca Linear em Ordem**
3. **Busca Binária**

## Organização do Repositório

```bash
/algoritmos-busca
    /busca_linear
        buscaLinear.c
    /busca_linear_ordenada
        buscaLinearOrdenada.c
    /busca_binaria
        buscaBinaria.c
    README.md (Este arquivo)
    grafico.py (Código para gerar o gráfico)
    grafico.png (Gráfico gerado para análise Big O)
```

## Análise Assintótica

### 1. **Busca Linear**
A **Busca Linear** percorre cada elemento do array até encontrar o elemento procurado ou até o final do array.

#### Pior Caso:
- O pior caso ocorre quando o elemento a ser encontrado está no final da lista ou não está presente.

#### Função de Tempo:
- \( T(n) = n \) (O algoritmo percorre todos os elementos uma vez)

#### Notação Big O:
- \( O(n) \)

---

### 2. **Busca Linear em Ordem**
A **Busca Linear em Ordem** é realizada em um array já ordenado. A busca para quando encontra o elemento ou um valor maior que o procurado.

#### Pior Caso:
- O pior caso é similar à busca linear tradicional, com a diferença de que se o elemento procurado não estiver presente, o algoritmo para quando encontra um elemento maior que o procurado.

#### Função de Tempo:
- \( T(n) = n \) (No pior caso, o algoritmo percorre todo o array)

#### Notação Big O:
- \( O(n) \)

---

### 3. **Busca Binária**
A **Busca Binária** funciona dividindo o array ordenado repetidamente ao meio até encontrar o elemento desejado.

#### Pior Caso:
- O pior caso ocorre quando o algoritmo deve dividir o array até restar apenas um elemento.

#### Função de Tempo:
- \( T(n) = \log n \) (A cada iteração, o número de elementos restantes é reduzido pela metade)

#### Notação Big O:
- \( O(\log n) \)

---

## Demonstração Matemática das Funções

Aqui estão as funções algébricas que descrevem o tempo de execução de cada algoritmo, considerando o pior caso:

- **Busca Linear:** \( T(n) = n \)
- **Busca Linear em Ordem:** \( T(n) = n \)
- **Busca Binária:** \( T(n) = \log n \)

A simplificação para a notação Big O é baseada nas propriedades de crescimento das funções:

- Busca Linear: \( O(n) \)
- Busca Linear em Ordem: \( O(n) \)
- Busca Binária: \( O(\log n) \)

## Gráficos de Comparação

O gráfico abaixo mostra a comparação das complexidades de tempo dos três algoritmos:

![Gráfico de Complexidade](./grafico.png)

- A linha **O(n)** representa tanto a Busca Linear quanto a Busca Linear Ordenada, já que ambas têm o mesmo comportamento de pior caso.
- A linha **O(log n)** representa a Busca Binária, que tem um crescimento mais lento em comparação.

## Como Executar os Códigos

Cada algoritmo está em seu próprio diretório com um arquivo `*.c` correspondente. Para compilar e executar os programas:

### Exemplo de Compilação e Execução

```bash
gcc -o busca_linear busca_linear.c
./buscaLinear
```