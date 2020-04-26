#include <stdlib.h>
#include <stdio.h>
#include "lists.h"
#include "data.h"
#include "interface.h"
#include "bot.h"

int main() {
   STATE *s = starting_state();
   draw(s, stdout);
   CMD(s);
   free(s);
   return 0;
}

//void main () {
//    STATE *s = starting_state();
//    for (int y = 0; y < 8; y++, putc('\n', stdout))
//        for (int x = 0; x < 8; x++)
//            printf(" %d", value_of((COORDINATE){x, y}));
//}
