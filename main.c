#include <stdlib.h>
#include "data.h"
#include "interface.h"

int main() {
    STATE *s = starting_state();
    draw(s);
    CMD(s);
    free(s);
    return 0;
}