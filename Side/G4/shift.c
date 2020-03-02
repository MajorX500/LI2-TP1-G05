#include <stdlib.h>

void shift(int a[],int dim,int arg) {
  int B[arg],c=0,i=0;
  if (arg>=dim) {
    arg = arg-dim;
  }
  if (arg != 0) {
    i=arg;
    while (c < dim) {
      B[c]=a[i];
      if ((i+1)>=dim) i=0;
      else i++;
      c++;
    }
    i=0;
    while (i<=dim) {
      a[i]=B[i];
      i++;
    }
  }
}
