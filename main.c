#include <stdlib.h>
#include <stdio.h>
#include "data.h"
#include "interface.h"

int main() {
    STATE *s = starting_state();
    draw(s, stdout);
    CMD(s);
    free(s);
    return 0;
}