#include <stdlib.h>
#include "data.h"

void empty_board(HOUSE board[8][8])
{
    int x, y;
    for (y = 0; y < 8; y ++)
    {
        for (x = 0; x < 8; x ++)
            board[y][x] = EMPTY;
    }
    board[3][4] = WHITE;
}

STATE *starting_state()
{
    STATE *s = (STATE *) malloc(sizeof(STATE));
    empty_board(s -> board);
    s -> previous_move.x = 4;
    s -> previous_move.y = 3;
    s -> num_moves = 0;
    s -> current_player = 1;
    return s;
}

int get_current_player(STATE *s)
{
    return s -> current_player;
}

HOUSE get_house(STATE *s, COORDINATES c)
{
    return s -> board[c.y][c.x];
}

int get_num_moves(STATE *s)
{
    return s -> num_moves;
}

void make_move(STATE *s, COORDINATES c)
{
    s -> board[c.y][c.x] = WHITE;
    s -> board[s -> previous_move.y][s -> previous_move.x] = BLACK;
    s -> previous_move = c;
}
