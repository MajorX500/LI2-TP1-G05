#include "data.h"
#include "interface.h"
#include <stdio.h>

int validate_move(STATE *s, COORDINATES c)
{
    COORDINATES old_c = s -> previous_move;
    if ((c.x == old_c.x + 1 || c.x == old_c.x - 1) && (c.y == old_c.y + 1 || c.y == old_c.y - 1) && get_house(s, c) == EMPTY)
    {
        make_move(s, c);
        printf("Move %d %d\n", c.x, c.y);
        draw_board(s);
        return 1;
    }
    else
    {
        printf("Invalid move");
        return 0;
    }
}