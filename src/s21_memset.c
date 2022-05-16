#include "../headers/s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
    unsigned char *p = str;
    for (int i = 0; i < (int)n; i++) {
        *(p + i) = (unsigned char)c;
    }
    return p;
}
