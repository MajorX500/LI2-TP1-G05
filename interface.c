#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int CMD(STATE *e) {
  char command[1024];
  char x[2], y[2];
  if(fgets(command, 1024, stdin) == NULL) return 0;
  if(strlen(command) == 3 && sscanf(command, "%[a-h]%[1-8]", x, y) == 2) {
    COORDINATES pos = {*x -'a', *y -'1'};
    printf("%s %s\n",x,y);
    make_move(e, pos);
    draw(e);
  }
  return 1;
}
