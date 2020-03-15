#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "logic.h"

#define BUF_SIZE 1024

void draw(STATE *s) {
  int y=0,x=0;
  while (y < 8) {
    while (x < 8) {
      if (x == 7 && y == 0) {printf(" 2");}
      else if (x == 0 && y == 7) {printf(" 1");}
      else if (get_house(s, (COORDINATES){x, y}) == EMPTY) {printf(" .");}
      else if (get_house(s, (COORDINATES){x, y}) == WHITE) {printf(" @");}
      else{printf(" #");}
      x++;
    }
    x=0;
    printf("\n");
    y++;
  }
}

int CMD(STATE *s) {
  char command[BUF_SIZE];
  char x[2], y[2];
  do
  {
    if(fgets(command, 1024, stdin) == NULL) return 0;
    if(strlen(command) == 2) return 0;
    if(strlen(command) == 3 && sscanf(command, "%[a-h]%[1-8]", x, y) == 2) {
      COORDINATES pos = {*x -'a', 7 - (*y -'1')};
      printf("%d %d\n",pos.x, pos.y);
      if (validate_move(s, pos)){
        make_move(s, pos);
        draw(s);
      }
    }
  } while (command != "Q");
  return 1;
}
