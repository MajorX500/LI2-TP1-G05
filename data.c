#include "data.h"

void empty_board(HOUSE board[8][8])
{
    int x, y;
    for (y = 0; y < 8; y ++)
    {
        for (x = 0; x < 8; x ++)
            board[x][y] = EMPTY;
    }
    board[4][4] = BLACK;
}

STATE *starting_state()
{
    STATE *s;
    empty_board(s -> board);
    s -> previous_move.x = 5;
    s -> previous_move.y = 5;
    s -> moves[32];
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
