#ifndef __DATA_H__
#define __DATA_H__

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

int get_current_player(STATE *);

HOUSE get_house(STATE *, COORDINATES);

int get_num_moves(STATE *);

#endif