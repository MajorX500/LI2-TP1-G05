#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "logic.h"

#define BUF_SIZE 1024

void draw(STATE *s, FILE *f) {
    int y, x, i = 8;
    for (y = 0; y < 8; y++, i--, putc('\n', f))
        for (x = 0, fprintf(f, "%d ", i); x < 8; x++)
            fprintf(f, " %c", get_house(s, (COORDINATE){x, y}));
    fputs("\n   a b c d e f g h\n\n", f);
}

void save(STATE *s, FILE *file) {
    draw(s, file);
    fclose(file);
}

void read(STATE *s, FILE *file) {
    if (file == NULL) puts("Non existent file");
    else {
        for (int y = 0; y < 8; y++) {
            fgetc(file);
            for (int x = 0; x < 8;) {
                char c = fgetc(file);
                if (c != ' ') {
                    change_house(s, (COORDINATE){x,y}, c); 
                    x ++;
                }
            fgetc(file);
            }
        }
        fclose(file);
    }
}

void move(STATE *s, COORDINATE c) {
    if (check_winner(s, c))
        printf("Player %d wis.board!\n", check_winner(s, c));
    make_move(s, c);
    if (!valid_moves(s)) (printf("Player %d wins!\n",(get_current_player(s) + 1 % 2)));
}

int CMD(STATE *s) {
    char command[BUF_SIZE];
    do {
    if(fgets(command, 1024, stdin) == NULL) return 0;
    switch (command[0]) {
        case 'a' ... 'h': {
            if (command[0] == 'g' && command[1] == 'r') {
                char f[BUF_SIZE];
                sscanf(command, "%*s %s", f);
                FILE *file = fopen(f, "w");
                save(s, file);
            }
            else if (command[1] >= '1' && command[1] <= '8') {
                COORDINATE c = {command[0] - 'a', 7 - (command[1] - '1')};
                if (validate_move(s, c)) move(s, c);
                else puts ("Invalid Coordinate");
            }
            else puts("Invalid Command");
        }
        case 'l': {
            char f[BUF_SIZE];
            sscanf(command, "%*s %s", f);
            FILE *file = fopen(f, "r");
            read(s, file);
        }
    }
    draw(s, stdout);
    } while (command[0] != 'Q');
    return 1;
}