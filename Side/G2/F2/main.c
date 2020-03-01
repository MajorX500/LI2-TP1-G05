#include <stdio.h>
#include "pointer.h"
#include <assert.h>

int main() {
    float p, a, i;
    printf("Indique o seu peso (em Kg): ");
    scanf("%f",&p);
    assert((p <= 130 && p >= 40) && "A Tabela não está optimizada para o seu peso.");
    printf("Indique a sua altura (em m): ");
    scanf("%f",&a);
    assert((a <= 2 && a >= 1.40) && "A Tabela não está optimizada para a sua altura.");
    i = imc(p, a);
    printf("O valor do seu IMC é: %f\n", i);
    return 0;
}
