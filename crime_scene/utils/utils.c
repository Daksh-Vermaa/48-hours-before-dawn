#include <string.h>

#include "utils.h"

void trim_newline (char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n' ){
        str[len - 1] = '\0';
    }
}
int str_equals (const char *a, const char *b) {
    return strcmp(a, b) == 0;
}