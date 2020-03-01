#include <stdio.h>
void printArray(int X[],int dim) {
  int i;
  for (i = 0; i < dim; i++) {
    printf("%d ",X[i]);
  }
  printf("\n");
}
