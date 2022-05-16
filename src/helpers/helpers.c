#include "../../headers/s21_string.h"

int helper_isSpec(char c, struct s_format *formatParams) {
    int i = 0;
    if (c == 'd' || c == 'i' || c == 'c' || c == 'f' || c == 's' ||
        c == 'u' || c == '%') {
        i = 1;
    }
    formatParams->spec = (c == 'u' ? 1 : 0);
    return i;
}

//Инициализатор структуры
void helper_initStruct(struct s_format *formatParams) {
    formatParams->isInt                             = 0;
    formatParams->flagPlus                          = 0;
    formatParams->flagMinus                         = 0;
    formatParams->flagSpace                         = 0;
    formatParams->width                             = 0;
    formatParams->widthMustBeWrittenByZero          = 0;
    formatParams->widthZeroDetected                 = 0;
    formatParams->precision                         = 0;
    formatParams->precisionWillBeSpecified          = 0;
    formatParams->length_h                          = 0;
    formatParams->length_l                          = 0;
    formatParams->isAsteriskWidth                   = 0;
    formatParams->isAsteriskFloatWidthDescription   = 0;
    formatParams->precisionIsNull                   = 0;
    formatParams->precisionSetByZero                = 0;
    formatParams->isLongDouble                      = 0;
    formatParams->spec                              = 0;
}

//Записывает символ в буффер
void helper_writeChar(const char **format, char **str, struct s_format *formatParams, char c) {
    if (formatParams->flagMinus) {
        **str = c;
        (*str)++;
    }
    for (int i = 0; i < formatParams->width - 1; i++){
        **str = ' ';
        (*str)++;
    }
    if (!formatParams->flagMinus) {
        **str = c;
        (*str)++;
    }
    (*format)++;
}

//Записывает знак процента в буффер
void helper_writePercent(const char **format, char **str) {
    **str = '%';
    (*str)++;
    (*format)++;
}

//Булин положительности
void	helper_isNegative(int *n, int *neg) {
    if (*n < 0)
    {
        *n *= -1;
        *neg = 1;
    }
}

//Заполняет строку размером n терминаторами.
void	helper_bZero(void *s, s21_size_t n) {
    s21_size_t i;

    i = 0;
    while (i < n)
    {
        ((char *)s)[i] = 0;
        i++;
    }
}

//Выделяет память для чего-либо
void	*helper_memalloc(s21_size_t size) { //БОЛЬШЕ ОДНОГО ВЫХОДА
    void	*some;

    some = malloc(size);
    if (!some)
        return (s21_NULL);
    helper_bZero(some, size);
    return (some);
}

//Конвертирует интеджер в строку
char		*helper_itoa(int n) { //БОЛЬШЕ ОДНОГО ВЫХОДА
    int		tmpn;
    int		len;
    int		neg;
    char	*str;

    tmpn = n;
    len = 2;
    neg = 0;
    helper_isNegative(&n, &neg);

    while (tmpn /= 10)
        len++;
    if (!(str = helper_memalloc(len)))
        return (s21_NULL);
    len += neg;
    str[--len] = '\0';
    while (len--)
    {
        str[len] = n % 10 + '0';
        n = n / 10;
    }
    if (neg)
        str[0] = '-';
    return (str);
}

char		*helper_utoa(unsigned int n) { //БОЛЬШЕ ОДНОГО ВЫХОДА
    unsigned int		tmpn;
    int		len;
    char	*str;

    tmpn = n;
    len = 2;

    while (tmpn /= 10)
        len++;
    if (!(str = helper_memalloc(len)))
        return (s21_NULL);
    str[--len] = '\0';
    while (len--)
    {
        str[len] = n % 10 + '0';
        n = n / 10;
    }
    return (str);
}

char		*helper_ldtoa(long int n) { //БОЛЬШЕ ОДНОГО ВЫХОДА
    long int		tmpn;
    int		len;
    //int		neg;
    char	*str;

    tmpn = n;
    len = 2;
    //neg = 0;
    //helper_isNegative(&n, &neg);

    while (tmpn /= 10)
        len++;
    if (!(str = helper_memalloc(len)))
        return (s21_NULL);
    // len += neg;
    str[--len] = '\0';
    while (len--)
    {
        str[len] = n % 10 + '0';
        n = n / 10;
    }
    //if (neg)
    //    str[0] = '-';
    return (str);
}