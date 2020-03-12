#include <string.h>
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
    HOUSE b[8][8];
    memcpy(b,s -> board,8);
    return b[c.y][c.x];
}
