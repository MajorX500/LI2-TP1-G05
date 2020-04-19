#ifndef __BOT_H__
#define __BOT_H__

int max(int, int);

int min(int, int);

LIST possible_coordinates(STATE *, COORDINATE);

int value_of(COORDINATE);

int minmax(STATE *, COORDINATE, int, int);

COORDINATE find_best_coordinate(STATE *);

#endif
