#include <stdlib.h>
#include "data.h"
#include "logic.h"
#include "linked_lists.h"

int max(int x, int y) {
	return x > y ? x : y;
}

int min(int x, int y) {
	return x < y ? x : y;
}

LIST possible_coordinates(STATE *s) {
	COORDINATE c = get_previous_move(s);
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
	int value[8][8] = {
		{   0, -5, -15, -30, -50, -70, -90, -150 },
		{  25, 15, -20, -35, -55, -75, -95,  -90 },
		{  30, 35,  15, -40, -60, -80, -75,  -70 },
		{  40, 45,  50,  20,   0, -60, -55,  -50 },
		{  60, 65,  70,  55,  20, -40, -35,  -30 },
		{  75, 80,  85,  70,  50,  15, -20,  -15 },
		{  90, 95,  80,  65,  50,  40,  10,   -5 },
		{ 150, 90,  75,  60,  45,  35,  30,    0 }
	};
	return value[c.y][c.x];
}

int minimax(STATE *s, COORDINATE c, int depth, int alpha, int beta, int maximizing_player) {
	STATE *ns = malloc(sizeof(STATE));
	*ns = *s;
	make_move(ns, c);
	if (!valid_moves(ns) && get_house(s, c) == EMPTY) {
		free(ns);
		if (maximizing_player) return 150;
		else return -150;
	}
	if (!depth || check_winner(s, c) || !valid_moves(ns)) {
		free(ns);
		return value_of(c);
	}
	if (maximizing_player) {
		int maxEval = -10000;
		for (LIST l = possible_coordinates(ns); !is_list_empty(l); l = remove_head(l)) {
			COORDINATE *nc = get_head(l);
			int eval = minimax(ns, *nc, depth - 1, alpha, beta, 0);
			maxEval = max(eval, maxEval);
			alpha = max(alpha, eval);
			if (beta <= alpha) break;
		}
		free(ns);
		return maxEval;
	}
	else {
		int minEval = 10000;
		for (LIST l = possible_coordinates(ns); !is_list_empty(l); l = remove_head(l)) {
			COORDINATE *nc = get_head(l);
			int eval = minimax(ns, *nc, depth - 1, alpha, beta, 1);
			minEval = min(eval, minEval);
			beta = min(beta, eval);
			if (beta <= alpha) break;
		}
		free(ns);
		return minEval;
	}
}

COORDINATE decide_between_equals(STATE *s, COORDINATE c1, COORDINATE c2) {
	if(get_current_player(s) == 1)
		return value_of(c1) > value_of(c2) ? c1 : c2;
	else 
		return value_of(c1) < value_of(c2) ? c1 : c2;
}

LIST free_coordinates(STATE *s, LIST l) {
	for(LIST pl = possible_coordinates(s); pl != NULL; pl = next(pl)) {
		COORDINATE *c = get_head(pl);
		if (!elem(l, c)) {
			l = insert_head(l, c);
			make_move(s, *c);
			l = free_coordinates(s, l);
		}
	}
	return l;
}


int num_free_coordinates(STATE *s) {
	STATE *ns = malloc(sizeof(STATE));
	*ns = *s;
	LIST l = initialize_list();
	l = free_coordinates(ns, l);
	return length(l);
}

int decide_depth(STATE *s) {
	int n = num_free_coordinates(s);
	if (n > 200)
		return 10;
	if (n > 130)
		return 11;
	else return n / 10;
}

COORDINATE find_best_coordinate(STATE *s) {
	COORDINATE c = get_previous_move(s);
	int maximizing_player = 2 - get_current_player(s);
	COORDINATE bc = c;
	if (maximizing_player) {
		int maxEval = -10000;
		for(LIST l = possible_coordinates(s); !is_list_empty(l); l = remove_head(l)) {
			COORDINATE *nc = get_head(l);
			int eval = minimax(s, *nc, decide_depth(s), -10000, 10000, maximizing_player);
			if (eval == maxEval)
				bc = decide_between_equals(s, bc, *nc);
			if (eval > maxEval) {
				maxEval = eval;
				bc = *nc;
			}
		}
	}
	else {
		int minEval = 10000;
		for(LIST l = possible_coordinates(s); !is_list_empty(l); l = remove_head(l)) {
			COORDINATE *nc = get_head(l);
			int eval = minimax(s, *nc, decide_depth(s), -10000, 10000, maximizing_player);
			if (eval == minEval)
				bc = decide_between_equals(s, bc, *nc);
			if (eval < minEval) {
				minEval = eval;
				bc = *nc;
			}
		}
	}
	return bc;
}

int numbEmpty(STATE *s, COORDINATE c) {
    STATE *ns = malloc(sizeof(STATE));
    *ns = *s;
    make_move(ns, c);
    int numb = 0;
    for(LIST l = possible_coordinates(ns); !is_list_empty(l); l = remove_head(l), numb ++);
    return numb - 1;
}

COORDINATE pairity(STATE *s) {
    COORDINATE c = get_previous_move(s);
    COORDINATE bc = c;
    for(LIST l = possible_coordinates(s); !is_list_empty(l); l = remove_head(l)) {
        COORDINATE *nc = get_head(l);
        int eval = numbEmpty(s, *nc);
        if (!(eval % 2))
            bc = *nc;
    }
    return bc;
}
