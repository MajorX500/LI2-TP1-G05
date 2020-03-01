#include <stdio.h>
#include <stdlib.h>
#include "draw.h"

int main(int argc, char *argv[]) {
    if(argc == 3) {
        int tarefa = atoi(argv[1]);
        int numero = atoi(argv[2]);
        switch(tarefa) {
            case 1: pointyBOI(numero); break;
            case 2: kiteKun(numero); break;
            case 3: pentagonPlus1(numero); break;
            default: printf("ERROR: %d\n", tarefa);
        }
    }
    return 0;
}
