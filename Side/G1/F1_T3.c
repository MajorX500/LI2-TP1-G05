#include <stdio.h>
#include "math.h"
#include <stdlib.h>

int main(){
  int a, b, c, e;
  float s, p;
  printf("Inserir comprimento das arestas do triângulo\n");
  scanf("%d %d %d",&a,&b,&c);

    //** DEBUG ** printf("%f\n",a);
    //validation
    if ((abs(b - c) < a) && (a < (b + c)))
      {
      e = 1;
      }
      if (e == 1) {
       printf ("Triângulo válido\n");
      }
      else
    (printf ("Triângulo inválido\n"));

    //** DEBUG ** printf("%f\n",b);
    //classification
    if (e == 1) {
      if ((a == b) && (a == c) && (b == c))
        {
        printf("O Triângulo é Equilatero\n");
        }
      else if ((a != b) && (b != c) && (a != c))
             {
             printf("O Triângulo é Escaleno\n");
             }
           else printf("O Triângulo é Isósceles\n");
         }

    //** DEBUG ** printf("%f\n",c);
    //area
    if (e == 1) {
    p = (a + b + c) / 2.0;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("A Área do Triângulo é %f\n",s);
  }
  return 0;
}
