#include "data.h"
#include "interface.h"
#include <stdlib.h>

int main()
{
    STATE *s = starting_state();
    draw(s);
    CMD(s);
    free (s);
    return 0;
}
