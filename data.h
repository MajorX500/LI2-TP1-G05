#ifndef __DATA_H__
#define __DATA_H__

typedef enum {
    EMPTY = '.',
    WHITE = '@',
    BLACK = '#',
    H1 = '1',
    H2 = '2'
    } HOUSE;

typedef struct 
{
    int x; //columns
    int y; //lines
} COORDINATE;

typedef struct 
{
    COORDINATE player1;
    COORDINATE player2;
} MOVE;

typedef MOVE MOVES[32];

typedef struct 
{
    HOUSE board[8][8]; //board state
    COORDINATE previous_move;
    MOVES moves;
    int num_moves;
    int current_player;
} STATE;

void empty_board(HOUSE [8][8]);

STATE *starting_state();

int get_current_player(STATE *);

HOUSE get_house(STATE *, COORDINATE);

int get_num_moves(STATE *);

COORDINATE get_previous_move (STATE *);

void put_white_house(STATE *, COORDINATE );

void put_black_house(STATE *);

void update_previous_move(STATE *, COORDINATE );

#endif