#include <stdio.h>
#include <stdlib.h>
#include "data.h"

void draw(STATE *s) {
  int y=0,x=0;
  while (y < 8) {
    while (x < 8) {
      if (s->board[y][x] == EMPTY) {printf(" .");}
      else{if (s->board[y][x] == WHITE) {printf(" @");}
      else{printf(" #");}}
      x++;
    }
    x=0;
    printf("\n");
    y++;
  }
}
/*
int main() {
  draw(starting_state());
  return 0;
}
*/
