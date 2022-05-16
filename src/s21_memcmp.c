#include "../headers/s21_string.h"

int		s21_memcmp(const void *s1, const void *s2, s21_size_t n)
{
    char				*str1;
    char				*str2;
    unsigned char		c1;
    unsigned char		c2;

    str1 = (char *)s1;
    str2 = (char *)s2;
    while (n--)
    {
        c1 = (unsigned char)*str1++;
        c2 = (unsigned char)*str2++;
        if (c1 != c2)
            return (c1 - c2);
    }
    return (0);
}
