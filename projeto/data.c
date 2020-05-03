/**
@file data.c
Camada de dados
*/

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
    STATE *s = (STATE *) calloc(1, sizeof(STATE));
    clear_state(s);
    return s;
}

void clear_state(STATE *s){
  empty_board(s->board);
  s->previous_move.x = 4;
  s->previous_move.y = 3;
  s->current_player = 1;
  s->num_moves = 0;
}

int get_current_player(STATE *s) {
    return s->current_player;
}

HOUSE get_house(STATE *s, COORDINATE c) {
    return s->board[c.y][c.x];
}

int get_num_moves(STATE *s) {
    return s->num_moves;
}

COORDINATE get_previous_move(STATE *s) {
    return s->previous_move;
}

MOVE get_move(STATE *s, int i) {
    return s->moves[i];
}

void change_house(STATE *s, COORDINATE c, HOUSE h) {
    s->board[c.y][c.x] = h;
}

void update_previous_move(STATE *s, COORDINATE c) {
    s->previous_move = c;
}

void next_player(STATE *s) {
    s->current_player = 1 + (s->current_player % 2);
}

void set_player1(STATE *s) {
    s->current_player = 1;
}

void set_player2(STATE *s) {
    s->current_player = 2;
}

void next_move(STATE *s) {
    s->num_moves++;
}

void store_p1_coordinate(STATE *s, COORDINATE c) {
    s->moves[s->num_moves].player1 = c;
}

void store_p2_coordinate(STATE *s, COORDINATE c) {
    s->moves[s->num_moves].player2 = c;
}

COORDINATE get_player_coordinate(MOVE m, int p) {
    COORDINATE c;
    if (p == 1) c = m.player1;
    if (p == 2) c = m.player2;
    return c;
}

int get_player_point(COORDINATE c, char a) {
    int n = 0;
    if (a == 'x') n = c.x;
    if (a == 'y') n = c.y;
    return n;
}