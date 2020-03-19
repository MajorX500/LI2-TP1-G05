#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include "data.h"
#include "logic.h"

#define BUF_SIZE 1024

void draw(STATE *s) {
    int y, x, i = 8;
    for (y = 0, putchar('\n'); y < 8; y++, i--, putchar('\n'))
        for (x = 0, printf("%d ", i); x < 8; x++)
            printf(" %c", get_house(s, (COORDINATE){x, y}));
    puts("\n   a b c d e f g h\n");
}

int CMD(STATE *s) {
  char command[BUF_SIZE];
  do {
    if(fgets(command, 1024, stdin) == NULL) return 0;
    switch (command[0]) {
        case 'a' ... 'h': {
            if (command[0] == 'g' && command[1] == 'r')
                //gravar()
                ;
            else if (command[1] >= '1' && command[1] <= '8') {
                COORDINATE c = {command[0] - 'a', 7 - (command[1] - '1')};
                if (validate_move(s, c)) {
                    if (check_winner(s, c))
                        printf("Player %d wins!", check_winner(s, c));
                    make_move(s, c);
                    if (!valid_moves(s)) (printf("Player %d wins!",(get_current_player(s) + 1 % 2)));
                }
            }
            else puts("Invalid Command");
        }
    }
    draw(s);
  } while (strncmp (command, "Q", 1));
  return 1;
}