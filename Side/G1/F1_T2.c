#include <stdio.h>
#include <math.h>

int main(){
  float a, b, c, x1, x2;
  printf("introduza os valores dos termos a,b e c do polinimio ax^2 + bx+ c\n");
  scanf("%f %f %f",&a,&b,&c);
  x1= (-1.0 * b + sqrt(pow(b,2) -4.0 * a * c)) / (2.0 * a);
  x2= (-1.0 * b - sqrt(pow(b,2) -4.0 * a * c)) / (2.0 * a);
  printf("raizes %f e %f \n", x1, x2);
  return 0;
}
