#include "../headers/s21_string.h"

void	*s21_memcpy(void *dst, const void *src, s21_size_t n)
{
    size_t i;

    if (dst != src)
    {
        i = 0;
        while (i < n)
        {
            ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
            i++;
        }
    }
    return (dst);
}
