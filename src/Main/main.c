#include <stdlib.h>
#include <stdio.h>
#include "../Data/data.h"
#include "../Interface/interface.h"

int main() {
    STATE *s = starting_state();
    draw(s, stdout);
    CMD(s);
    free(s);
    return 0;
}
