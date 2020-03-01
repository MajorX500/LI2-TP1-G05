#include <stdlib.h>


int bye_smol(int r[],int dim,int arg) {
  int L[dim],S[dim],i=0,cb=0,cs=0,cbs=0,css=0;
  while (i<dim) {
    if (r[i]>=arg) {
      L[cb]=r[i];
      cb++;
      i++;
    }
    else {
      S[cs]=r[i];
      cs++;
      i++;
    }
  }
  i=0;
  while (i<cb) {
    r[i]=L[cbs];
    cbs++;
    i++;
  }
  while (i<cb+cs) {
    r[i]=S[css];
    css++;
    i++;

  }
  return cb;
}
