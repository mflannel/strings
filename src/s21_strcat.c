#include "../headers/s21_string.h"

char * s21_strcat(char *dest, const char * src) {
    char * cp = dest;
    while ( *cp )
        ++cp;
    while ((*cp++ = *src++)) {}
    return( dest );
}
