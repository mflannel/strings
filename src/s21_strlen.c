#include "../headers/s21_string.h"

s21_size_t s21_strlen(const char *str) {

    const char *strtmp = str;
    int i = 0;
    while (strtmp[i] != '\0') {
        i++;
    }
    return (i);
}