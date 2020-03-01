#include <stdio.h>
#include "math.h"
#include <stdlib.h>

int main(){
  int a, b, c, input;
  float s, p;
  printf("Inserir comprimento das arestas do triângulo\n");
  scanf("%d %d %d",&a,&b,&c);
  printf("Selecione a opção:\n 1) - Validar Triângulo\n 2) - Classificar Triângulo\n 3) - Calcular a Área Triângulo\n");
  scanf("%d",&input);

  if (input == 1)
    {

    //** DEBUG ** printf("%f\n",a);
    //validation
    if ((abs(b - c) < a) && (a < (b + c)))
      {
      printf ("Triângulo válido\n");
      }
    else (printf ("Triângulo inválido\n"));
    return 0;
    }

  else if (input == 2)
    {

    //** DEBUG ** printf("%f\n",b);
    //classification
    if ((a == b) && (a == c) && (b == c))
      {
      printf("O Triângulo é Equilatero\n");
      }
    else if ((a != b) && (b != c) && (a != c))
           {
           printf("O Triângulo é Escaleno\n");
           }
         else printf("O Triângulo é Isósceles\n");

    return 0;
    }

  else if (input == 3)
    {

    //** DEBUG ** printf("%f\n",c);
    //area
    p = (a + b + c) / 2.0;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("A Área do Triângulo é %f\n",s);
    return 0;
    }
  else printf("Input Errado\n");
  return 0;
}
