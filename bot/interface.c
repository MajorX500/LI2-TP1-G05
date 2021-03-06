/**
@file interface.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "interface.h"
#include "logic.h"
#include "linked_lists.h"
#include "algorithms.h"

int CMD(STATE *s) {
    char command[BUF_SIZE];
    int pos_cap = 0;
    do {
        prompt(s);
        if(fgets(command, BUF_SIZE, stdin) == NULL) return 0;
	if (command[0] >= 'a' && command[0] <= 'h') {
                if (command[0] == 'g' && command[1] == 'r') {
                    char f[BUF_SIZE];
                    sscanf(command, "%*s %s", f);
                    save(s, f);
                }
                else if (command[1] >= '1' && command[1] <= '8') {
                    COORDINATE c = {command[0] - 'a', 7 - (command[1] - '1')};
                    if (validate_move(s, c)) move(s, c);
                    else puts ("Invalid Coordinate");
                }
                else puts("Invalid Command");
		pos_cap = get_num_moves(s);
            }
	else if (command[0] == 'l') {
                char f[BUF_SIZE];
                sscanf(command, "%*s %s", f);
                read(s, f);
		pos_cap = get_num_moves(s);
            }
    	else if (command[0] == 'm') {
                draw_moves(s, stdout);
            }
	else if (command[0] == 'p') {
                int m;
                sscanf(command, "%*s %d",&m);
                if (m < 0 || m > pos_cap) puts ("Invalid Move");
                else rollback(s,m);
            }
	else if (command[0] == 'j') {
		if (!strncmp (command, "jog2", 4))
			move(s, pairity(s));
		else move(s, find_best_coordinate(s));
		pos_cap = get_num_moves(s);
        }
    else if (command[0] == 'z')
        printf("%d\n", num_free_coordinates(s));
	else if (command[0] != 'Q')
		puts("Invalid Command");
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
        fprintf(file, "%02d: %c%d", i + 1, get_player_point(get_player_coordinate(m, 1), 'x') + 'a', 8 - get_player_point(get_player_coordinate(m, 1), 'y'));
        if (!(i == get_num_moves(s) && get_current_player(s) == 2))
            fprintf(file, " %c%d\n", get_player_point(get_player_coordinate(m, 2), 'x') + 'a', 8 - get_player_point(get_player_coordinate(m, 2), 'y'));
        else
            putc('\n', file);
    }
}

void save(STATE *s, char *f) {
    FILE *file = fopen(f, "w");
    int y, x, i = 8;
    for (y = 0; y < 8; y++, i--, putc('\n', file))
        for (x = 0; x < 8; x++) {
            char h = get_house(s, (COORDINATE){x, y});
            if (h == '@') h = '*';
            fprintf(file, "%c", h);
        }
    putc('\n', file);
    draw_moves(s, file);
    fclose(file);
}

void read(STATE *s, char *f) {
    	FILE *file = fopen(f, "r");
	char c;
    	clear_state(s);
	if (file == NULL) puts("Non existent file");
    	for (int y = 0; y < 8; fgetc(file),y++)
    		for (int x = 0; x < 8; x++) {
              		c = fgetc(file);	
			if (c == '*') c = '@';
                	change_house(s, (COORDINATE){x,y}, c);
            	}
	fseek(file, 1, SEEK_CUR);
        for (int i = 0; c != EOF; c = getc(file), i++) {
            	char p1[2], p2[2];
            	int l = fscanf(file, "%*s %s %s", p1, p2);
            	if (l == 2) {
               		make_move(s, (COORDINATE) {p1[0] - 'a', 7 - (p1[1] - '1')});
                	make_move(s, (COORDINATE) {p2[0] - 'a', 7 - (p2[1] - '1')});
            	}
            	else if (l == 1)
                	make_move(s, (COORDINATE) {p1[0] - 'a', 7 - (p1[1] - '1')});
    	}
    	fclose(file);
}

void prompt(STATE *s) {
  printf("# PL%d (%d) > ", get_current_player(s), get_num_moves(s));
}

void rollback(STATE *s,int num) {
    clear_state(s);
    for (int i = 0; i < num; i++) {
        MOVE m = get_move(s, i);
        make_move(s, get_player_coordinate(m, 1));
        make_move(s, get_player_coordinate(m, 2));
    }
}
