#include "data.h"
#include "interface.h"
#include <stdio.h>

int validate_move(STATE *s, COORDINATES c) {
    COORDINATES prev_move = get_previous_move(s);
    if ((c.x == prev_move.x + 1 || c.x == prev_move.x - 1 || c.x == prev_move.x) && (c.y == prev_move.y + 1 || c.y == prev_move.y - 1 || c.x == prev_move.y) && get_house(s, c) == EMPTY) {
        printf("Move %d %d\n", c.x, c.y);
        return 1;
    }
    else {
        printf("Invalid move\n");
        return 0;
    }
}
