/**
@file bot.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "interface.h"
#include "logic.h"
#include "linked_lists.h"
#include "algorithms.h"

int main(int argc, char **argv) {
	if (argc == 3) {
		STATE *s = starting_state();
		read(s, argv[1]);
		move(s, find_best_coordinate(s));
		save(s, argv[2]);
		free(s);
		return 0;
	}
}
