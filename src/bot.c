#include <stdlib.h>
#include "data.h"
#include "logic.h"
#include "lists.h"

int max(int x, int y) {
	return x > y ? x : y;
}

int min(int x, int y) {                    
	return x < y ? x : y;
}

LIST possible_coordinates(STATE *s, COORDINATE c) {
	LIST l = initialize_list();
	if (c.x >= 1 && c.y >= 1 && get_house(s, (COORDINATE){c.x - 1, c.y - 1}) != BLACK) {
		COORDINATE *tl = malloc(sizeof(COORDINATE));
		*tl = (COORDINATE){c.x - 1, c.y - 1};
		l = insert_head(l, tl);
	}
	if (c.x >= 1 && get_house(s, (COORDINATE){c.x - 1, c.y}) != BLACK) {
		COORDINATE *ml = malloc(sizeof(COORDINATE));
		*ml = (COORDINATE){c.x - 1, c.y};
		l = insert_head(l, ml);
	}
	if (c.x >= 1 && c.y <= 6 && get_house(s, (COORDINATE){c.x - 1, c.y + 1}) != BLACK) {
		COORDINATE *bl = malloc(sizeof(COORDINATE));
		*bl = (COORDINATE){c.x - 1, c.y + 1};
		l = insert_head(l, bl);
	}
	if (c.x <= 6  && get_house(s, (COORDINATE){c.x + 1, c.y}) != BLACK) {
		COORDINATE *mr = malloc(sizeof(COORDINATE));
		*mr = (COORDINATE){c.x + 1, c.y};
		l = insert_head(l, mr);
	}
	if (c.y >= 1 && get_house(s, (COORDINATE){c.x, c.y - 1}) != BLACK) {
		COORDINATE *tm = malloc(sizeof(COORDINATE));
		*tm = (COORDINATE){c.x, c.y - 1};
		l = insert_head(l, tm);
	}
	if (c.y >= 1 && c.x <= 6 && get_house(s, (COORDINATE){c.x + 1, c.y - 1}) != BLACK) {
		COORDINATE *tr = malloc(sizeof(COORDINATE));
		*tr = (COORDINATE){c.x + 1, c.y - 1};
		l = insert_head(l, tr);
		}
	if (c.y <= 6 && get_house(s, (COORDINATE){c.x, c.y + 1}) != BLACK) {
		COORDINATE *bm = malloc(sizeof(COORDINATE));
		*bm = (COORDINATE){c.x, c.y + 1};
		l = insert_head(l, bm);
	}
	if (c.y <= 6 && c.x <= 6 && get_house(s, (COORDINATE){c.x + 1, c.y + 1}) != BLACK) {
		COORDINATE *br = malloc(sizeof(COORDINATE));
		*br = (COORDINATE){c.x + 1, c.y + 1};
		l = insert_head(l, br);
	}
	return l;
}

int value_of(COORDINATE c) {
	if (c.x == 0 && c.y == 7) return 10;
	if (c.x <= 1 && c.y >= 6) return 7;
	if (c.x <= 2 && c.y >= 5) return 5;
	if (c.x <= 3 && c.y >= 4) return 3;
	if (c.x <= 4 && c.y >= 3) return 1;
	if (c.y == 0 && c.x == 7) return -10;
	if (c.y <= 1 && c.x >= 6) return -8;
	if (c.y <= 2 && c.x >= 5) return -6;
	if (c.y <= 3 && c.x >= 4) return -3; 
	return 0;	
}

int minimax(STATE *s, COORDINATE c, int depth, int maximizing_player) {
	if (!valid_moves(s)) {
		if (maximizing_player) return 10;
		else return -10;
	}
	if (!depth || check_winner(s, c) || !valid_moves(s))
		return value_of(c) * (depth + 1);
	STATE *ns = malloc(sizeof(STATE));
	*ns = *s;
	make_move(ns, c);
	if (maximizing_player) {
		int maxEval = -100;
		for (LIST l = possible_coordinates(s, c); !is_list_empty(l); l = remove_head(l)) {
			COORDINATE *nc = get_head(l);
			int eval = minimax(ns, *nc, depth - 1, 0);
			maxEval = max(eval, maxEval);
		}
		free(ns);
		return maxEval;
	}
	else {
		int minEval = 100;
		for (LIST l = possible_coordinates(s, c); !is_list_empty(l); l = remove_head(l)) {
			COORDINATE *nc = get_head(l);
			int eval = minimax(ns, *nc, depth - 1, 1);
			minEval = min(eval, minEval);
		}
		free(ns);
		return minEval;
	}
}

COORDINATE find_best_coordinate(STATE *s) {
	COORDINATE c = get_previous_move(s);
	int maximizing_player = 2 - get_current_player(s);
	COORDINATE bc = c;
	if (maximizing_player) {
		int maxEval = -20;
		for(LIST l = possible_coordinates(s, c); !is_list_empty(l); l = next(l)) {	
			COORDINATE *nc = get_head(l);
			int eval = minimax(s, *nc, 3, maximizing_player);
			if (eval > maxEval) {
				maxEval = eval;
				bc = *nc;
			}
		}
	}
	else {
		int minEval = 20;
		for(LIST l = possible_coordinates(s, c); !is_list_empty(l); l = remove_head(l)) {	
			COORDINATE *nc = get_head(l);
			int eval = minimax(s, *nc, 3, maximizing_player);
			if (eval < minEval) {
				minEval = eval;
				bc = *nc;
			}
		}
	}
	return bc;
}
