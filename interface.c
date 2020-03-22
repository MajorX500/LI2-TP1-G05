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

void prompt(STATE *s){
  printf("# PL%d (%d) > " ,get_current_player(s), get_num_moves(s) / 2);
}

int CMD(STATE *s) {
    char command[BUF_SIZE];
    do {
    prompt(s);
    if(fgets(command, BUF_SIZE, stdin) == NULL) return 0;
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
            break;
        }
        case 'l': {
            char f[BUF_SIZE];
            sscanf(command, "%*s %s", f);
            FILE *file = fopen(f, "r");
            read(s, file);
            break;
        }
    }
    draw(s, stdout);
    } while (command[0] != 'Q');
    return 1;
}

