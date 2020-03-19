#ifndef __LOGIC_H__
#define __LOGIC_H__

void make_move(STATE *, COORDINATE);
int validate_move(STATE *, COORDINATE);
int check_winner(STATE *, COORDINATE);
int valid_moves(STATE *);

#endif