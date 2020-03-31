#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "interface.h"
#include "logic.h"

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
            case 'm': draw_moves(s, stdout);
            case 'p': {
              int m;
              sscanf(command, "%*s %d",&m);
              if (m > s->num_moves) puts ("Invalid Play");
              else rollback(s,m);
            }
        }
        draw(s, stdout);
    } while (command[0] != 'Q');
    return 1;
}

void draw(STATE *s, FILE *f) {
    int y, x, i = 8;
    for (y = 0; y < 8; y++, i--, putc('\n', f))
        for (x = 0, fprintf(f, "%d ", i); x < 8; x++)
            fprintf(f, " %c", get_house(s, (COORDINATE){x, y}));
    fputs("\n   a b c d e f g h\n\n", f);
}

void draw_moves(STATE *s, FILE *file) {
    for (int i = 0; i <= get_num_moves(s) && !(get_num_moves(s) == i && get_current_player(s) == 1); i ++) {
        MOVE m = get_move(s, i);
        fprintf(file, "%02d: %c%d", i + 1, m.player1.x + 'a', 8 - m.player1.y);
        if (!(i == get_num_moves(s) && get_current_player(s) == 2))
            fprintf(file, " %c%d\n", m.player2.x + 'a', 8 - m.player2.y);
        else
            putc('\n', file);
    }
}

void save(STATE *s, FILE *file) {
    draw(s, file);
    draw_moves(s, file);
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
        fseek(file, 173, SEEK_SET);
        for (int i = 0, c; c != EOF; c = getc(file), i++) {
            fseek(file, 4, SEEK_CUR);
            char p1[2], p2[2];
            if (fscanf(file, "%s %s", p1, p2) == 2) {
                update_previous_move(s, (COORDINATE) {p2[0] - 'a', 7 - (p2[1] - '1')});
                store_p1_coordinate(s, (COORDINATE) {p1[0] - 'a', 7 - (p1[1] - '1')});
                store_p2_coordinate(s, (COORDINATE) {p2[0] - 'a', 7 - (p2[1] - '1')});
                update_num_moves(s, i + 1);
                set_player1(s);
            }
            else {
                fscanf(file, "%s", p1);
                update_previous_move(s, (COORDINATE) {p1[0] - 'a', 7 - (p1[1] - '1')});
                store_p1_coordinate(s, (COORDINATE) {p1[0] - 'a', 7 - (p1[1] - '1')});
                set_player2(s);
            }
        }
        fclose(file);
    }
}

void prompt(STATE *s){
  printf("# PL%d (%d) > ", get_current_player(s), get_num_moves(s));
}

void rollback(STATE *s,int num) { // como uma jogada são os moves dos dois jogadores, o o rollback fica sempre no jogador 1.
  int i=0;
  COORDINATE c;
  rollback_state(s);
  while (i!=num) {
      c = s->moves[i].player1;
      move(s,c);
      c = s->moves[i].player2;
      move(s,c);
    i++;
  }
  update_num_moves(s,num);
}
