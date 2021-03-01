#include "helper.h"
#include <stdlib.h>
#include <string.h>

int rand_int(const int min, const int max)
{
    int ret;
    do {
        ret = min + rand() / ((RAND_MAX + 1u) / (max - min + 1));
    } while (ret > max);
    return ret;
}

char *strip_newline(char *const restrict str)
{
    str[strcspn(str, "\n")] = '\0';
    return str;
}
