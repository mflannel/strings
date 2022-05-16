#include "../headers/s21_string.h"

char	*s21_strdup(const char *s1)
{
    char	*s2;
    s21_size_t	len;
    s21_size_t	i;

    len = s21_strlen(s1);
    if (!(s2 = (char *)malloc(sizeof(char) * len + 1)))
        return (s21_NULL);
    i = 0;
    while (s1[i])
    {
        s2[i] = s1[i];
        i += 1;
    }
    s2[i] = '\0';
    return (s2);
}
