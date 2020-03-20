#ifndef __INTERFACE_H__
#define __INTERFACE_H__

void draw(STATE *, FILE *);
void save(STATE *, char *);
void move(STATE *, COORDINATE);
int CMD(STATE *);

#endif