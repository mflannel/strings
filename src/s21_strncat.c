#include "../headers/s21_string.h"

char * s21_strncat (char *dest, const char *str, s21_size_t n) {
    char *start = dest;

    while (*dest++);
    dest--;

    while (n--) {
        if ((*dest++ = *str++) == '\0')
            return(start);
    }
    *dest = '\0';
    return(start);
}
