#include <stdlib.h>

void add(int a[],int dim,int arg) {
  int i=0,f=a[arg];
  while (i<dim) {
    a[i]+=f;
    i++;
  }
}
