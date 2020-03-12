#include "data.h"

int main()
{
    STATE *s = starting_state();
    interpreter(s);
    free (s);
    return 0;
}