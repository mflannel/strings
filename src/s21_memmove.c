#include "../headers/s21_string.h"

void	*s21_memmove(void *dst, const void *src, s21_size_t len)
{
    char	*src1;
    char	*dst1;
    size_t	i;

    if (dst != src)
    {
        i = -1;
        src1 = (char *)src;
        dst1 = (char *)dst;
        if (src1 < dst1)
            while (len-- > 0)
                *(dst1 + len) = *(src1 + len);
        else
            while (++i < len)
                *(dst1 + i) = *(src1 + i);
    }
    return (dst);
}
