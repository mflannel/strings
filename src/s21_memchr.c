#include "../headers/s21_string.h"

void	*s21_memchr(const void *arr, int c, s21_size_t n)
{
    size_t			i;
    unsigned char	*str;
    unsigned char	character;

    str = (unsigned char *)arr;
    character = (unsigned char)c;
    i = 0;
    while (i < n)
    {
        if (*str == character)
            return (str);
        str++;
        i++;
    }
    return (NULL);
}