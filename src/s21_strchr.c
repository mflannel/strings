#include "../headers/s21_string.h"

char* s21_strchr(const char* str1, int c) {

        while (*str1 != '\0' && *str1 != (char) c) {
            ++str1;
        }
        if (*str1 == (char) c) {
            return (char *) str1;
        }
        return NULL;
}