 #include <stdio.h>

void soma(valor1, valor2){
  int somas = valor1 + valor2;
  printf("A soma é: %d", somas);
}

int main(){
  int valor1 = 15;
  int valor2 = 27;

  soma(valor1, valor2);
  return 0;
}
