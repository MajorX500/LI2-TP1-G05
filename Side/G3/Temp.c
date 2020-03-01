#include <stdio.h>
#include <stdlib.h>

void imprime_losango (int);
void imprimeTriangSuperior(int);
void imprimeTriangInferior(int);
void imprimeLinha(int);
void imprimeCaracs(char,int);
void espaco(char,int);
int par(int);



void imprime_losango (int num2Linhas) {
    int n = num2Linhas/2 - (par(num2Linhas)? 1 : 0);
    imprimeTriangSuperior(n);
    imprimeLinha(num2Linhas);
    if (par(num2Linhas)) imprimeLinha(num2Linhas);
    imprimeTriangInferior(n);
}

void imprimeTriangSuperior (int n) {
    // Imprime triângulo com n brancos e 1 asterisco na 1a linha,
    // depois n-1 brancos e 3 asteriscos na 2a linha, etc., até uma
    // linha com 1 branco (e 2n-1 astericos).
    int numBrancos = n, numcardinal = 1, i;
    for (i=1; i<=n; i++) {
        espaco(' ', numBrancos);
        imprimeCaracs('A', numcardinal);
        printf("\n");
        numBrancos --;
        numcardinal +=2;
    }
}

void imprimeTriangInferior (int n) {
    // Imprime triângulo com 1 branco e 2*n-1 asteriscos na 1a linha,
    // depois 2 brancos e n*n-3 asteriscos na 2a linha, etc., até uma
    // linha com 1 asterisco (e 2*n-1 brancos).
    int numBrancos = 1, numcardinal = 2*n-1, i;
    for (i=1; i<=n; i++) {
        espaco(' ', numBrancos);
        imprimeCaracs('A', numcardinal);
        printf("\n");
        numBrancos ++;
        numcardinal -=2;
    }
}
void imprimeLinha (int n) {
    // Imprime uma linha com n asteriscos, se n é ímpar,
    // do contrário (n par) imprime linha com n-1 asteriscos.
    imprimeCaracs('A', par(n) ? n-1 : n);
    printf("\n");
}

void imprimeCaracs (char a, int n) {
    // Imprime n caracs iguais a c.
    int i=1;
    while (i<=n) {
      printf("%c",a);
      i++;
      a++;
    }
}


int par (int num) {
    return num%2 == 0;
}

void espaco (char c , int n) {
    // Imprime n caracs iguais a c.
    int i;
    for (i = 1; i <= n; i++)
        printf("%c", c );
}

void imprime_triangulo (int num_linhas){
    // Imprime triângulo com n brancos e 1 asterisco na 1a linha,
    // depois n-1 brancos e 3 asteriscos na 2a linha, etc., até uma
    // linha com 1 branco (e 2n-1 astericos).
    int numBrancos = num_linhas, numcardinal = 1, i;
    for (i=1; i<=num_linhas; i++){
    espaco (" ", numBrancos);
    imprimeCaracs('A', numcardinal);
    printf("\n");
    numBrancos --;
    numcardinal +=2;
    }
}

int main(int a) {
  imprime_triangulo(a);
  imprime_losango(a);
  return 0;
}
