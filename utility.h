#include <stdio.h>


char const* to_string(int coin_set[], int const size_coin_set)
{
    static char string[32];
    char *p = string;
    p += sprintf(p, "{");
    for(int i = 0; i != size_coin_set; ++i)
    {
        p += sprintf(p, "%s%d", i == 0 ? "" : ", ", coin_set[i]);
    }
    sprintf(p, "}");

    return string;
}
