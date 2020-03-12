#include <stdio.h>
#include <stdlib.h>
#include "data.c"

void draw(HOUSE board[8][8]) {
  int y=0,x=0;
  while (y < 8) {
    while (x < 8) {
      if (board[y][x] == EMPTY) {printf(" .");}
      else{if (board[y][x] == WHITE) {printf(" @");}
      else{printf(" #");}}
      x++;
    }
    x=0;
    printf("\n");
    y++;
  }
}
