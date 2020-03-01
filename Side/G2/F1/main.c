#include <stdio.h>
#include "pointer.h"

int main() {
    float p, a, i;
    printf("Indique o seu peso (em Kg): ");
    scanf("%f",&p);
    printf("Indique a sua altura (em m): ");
    scanf("%f",&a);
    i = imc(p, a);
    printf("O valor do seu IMC é: %f\n", i);
    return 0;
}
