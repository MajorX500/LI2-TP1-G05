#include <stdio.h>
#include <stdlib.h>
//#include "___.h"

typedef enum {EMPTY, WHITE, BLACK} HOUSE;

typedef struct
{
    int x; //columns
    int y; //lines
} COORDINATES;

typedef struct
{
    COORDINATES player1;
    COORDINATES player2;
} MOVE;

typedef MOVE MOVES[32];

typedef struct
{
    HOUSE board[8][8]; //board state
    COORDINATES previous_move;
    MOVES moves;
    int num_moves;
    int current_player;
} STATE;

HOUSE **empty_board()
{
    HOUSE board[8][8];
    int x, y;
    for (y = 0; y < 8; y ++)
    {
        for (x = 0; x < 8; x ++)
            board[x][y] = EMPTY;
    }
    board[4][4] = BLACK;
    return board;
}

void draw(HOUSE **board) {
  int y=0,x=0;
  while (y < 8) {
    while (x < 8) {
      if (board[y][x] == 0) {printf(" .");}
      else{if (board[y][x] == 1) {printf(" @");}
      else{printf(" #");}}
      x++;
    }
    x=0;
    printf("\n");
    y++;
  }
}

int main() {
  draw(**empty_board());
  return 0;
}
