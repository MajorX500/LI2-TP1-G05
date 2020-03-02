#include <stdio.h>
#include <stdlib.h>
#include "add.h"
#include "shift.h"
#include "bye_smol.h"
#include "printArray.h"

int main(int argc,char *argv[]) {
  int t,dim,arg,a[dim],i;
    t = atoi(argv[1]);
    dim = atoi(argv[2]);
    arg = atoi(argv[3]);
    printf("Insert Array\n");
    for (i = 0; i < dim; i++) {
      scanf("%d", &a[i]);
    }
    switch (t) {
      case 1:{add(a,dim,arg);
        printArray(a,dim);
      break;
    }
      case 2:{shift(a,dim,arg);
        printArray(a,dim);
      break;
    }
      case 3:{bye_smol(a,dim,arg);
        printArray(a,dim);
      break;
    }
      default:printf("Wrong Job\n");
  }
  return 0;
}
