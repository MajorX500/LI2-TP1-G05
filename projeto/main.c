/**
@file main.c
Main
*/

#include <stdlib.h>
#include <stdio.h>
#include "linked_lists.h"
#include "data.h"
#include "interface.h"
#include "algorithms.h"

int main() {
   STATE *s = starting_state();
   draw(s, stdout);
   CMD(s);
   free(s);
   return 0;
}
