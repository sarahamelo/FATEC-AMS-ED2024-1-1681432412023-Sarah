import matplotlib.pyplot as plt
import numpy as np

# Tamanhos de entrada
n = np.linspace(1, 100, 100)

# Funções de tempo (Big O)
linear = n
binary = np.log2(n)

# Criando o gráfico
plt.figure(figsize=(10, 6))

# Plotando as funções
plt.plot(n, linear, label='Busca Linear (O(n))', color='blue')
plt.plot(n, linear, label='Busca Linear Ordenada (O(n))', color='green', linestyle='--')
plt.plot(n, binary, label='Busca Binária (O(log n))', color='red')

# Configurações do gráfico
plt.xlabel('Tamanho da entrada (n)')
plt.ylabel('Número de operações')
plt.title('Comparação das Complexidades de Algoritmos de Busca')
plt.legend()
plt.grid(True)

# Salvando o gráfico como imagem
plt.savefig('grafico.png')

# Exibindo o gráfico
plt.show()
