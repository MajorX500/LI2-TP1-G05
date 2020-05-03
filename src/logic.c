#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "interface.h"
#include "logic.h"

void make_move(STATE *s, COORDINATE c) {
    change_house(s, c, WHITE);
    change_house(s, get_previous_move(s), BLACK);
    update_previous_move(s, c);
    store_coordinate(s, c);
    next_player(s);
    if (get_current_player(s) == 1) next_move(s);
}

int validate_move(STATE *s, COORDINATE c) {
    COORDINATE prev_move = get_previous_move(s);
    HOUSE h = get_house(s, c);
    if ((abs(c.x - prev_move.x) <= 1) && (abs(c.y - prev_move.y) <= 1) && (h == EMPTY || h == H1 || h == H2)) return 1;
    else return 0;
}

int check_winner(STATE *s, COORDINATE c) {
    if (get_house(s, c) == H1) return 1;
    else if (get_house(s, c) == H2) return 2;
    else return 0;
}

int valid_moves(STATE *s) {
    int n = 0, x, y;
    COORDINATE c;
    for (y = 0; y < 8; y++)
        for (x = 0; x < 8; c = (COORDINATE) {x, y}, n += validate_move(s,c), x++);
    return n;
}

void move(STATE *s, COORDINATE c) {
    if (check_winner(s, c))
        printf("Player %d wins!\n", check_winner(s, c));
    make_move(s, c);
    if (!valid_moves(s)) (printf("Player %d wins!\n",1 + (get_current_player(s) % 2)));
}

void store_coordinate(STATE *s, COORDINATE c) {
    if (get_current_player(s) == 1) store_p1_coordinate(s, c);
    else store_p2_coordinate(s, c);
}
