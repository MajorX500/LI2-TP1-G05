#include <stdlib.h>
#include "data.h"

void empty_board(HOUSE board[8][8]) {
    int x, y;
    for (y = 0; y < 8; y ++) {
        for (x = 0; x < 8; x ++)
            board[y][x] = EMPTY;
    }
    board[3][4] = WHITE;
    board[7][0] = H1;
    board[0][7] = H2;
}

STATE *starting_state() {
    STATE *s = (STATE *) malloc(sizeof(STATE));
    empty_board(s -> board);
    s -> previous_move.x = 4;
    s -> previous_move.y = 3;
    s -> num_moves = 0;
    s -> current_player = 1;
    return s;
}

int get_current_player(STATE *s) {
    return s -> current_player;
}

HOUSE get_house(STATE *s, COORDINATE c) {
    return s -> board[c.y][c.x];
}

int get_num_moves(STATE *s) {
    return s -> num_moves;
}

COORDINATE get_previous_move(STATE *s) {
    return s -> previous_move;
}

void change_house(STATE *s, COORDINATE c, HOUSE h) {
    s -> board[c.y][c.x] = h;
}

void update_previous_move(STATE *s, COORDINATE c) {
    s -> previous_move = c;
}

void next_player(STATE *s) {
    s -> current_player = 1 + (s -> current_player % 2);
}

void next_move(STATE *s) {
    s -> num_moves++;
}