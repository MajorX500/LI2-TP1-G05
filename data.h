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

void empty_board(HOUSE [8][8]);

STATE *starting_state();

int get_current_player(STATE *);

HOUSE get_house(STATE *, COORDINATES);

int get_num_moves(STATE *);

void make_move(STATE *s, COORDINATES c);

#endif