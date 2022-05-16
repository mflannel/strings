#include "../../headers/s21_string.h"

//Удаляет строку, вычищая память
void	helper_strdel(char **as) {
    if (as)
    {
        free(*as);
        *as = s21_NULL;
    }
}

//Возвращает длину предполагаемой строки исходя из количество цифр в числе
int		helper_countNumerals(long double chislo) {
    char	*str;
    int		k;

    str = helper_itoa((long long int)chislo);
    k = s21_strlen(str);
    //helper_strdel(&str);

    return (k);
}

//Конвертирует дабл
char    *helper_dtoa(long double ldNumber, struct s_format formatParams) {//БОЛЬШЕ ОДНОГО ВЫХОДА
    int			i;
    long double	chislo;
    int			size;
    char		*str;
    int			sign;

    chislo = ldNumber;
    i = 0;
    size = 1;
    sign = 0;
    if (chislo < 0)
        sign = 1;
    size += formatParams.precision <= 0 ? 6 : formatParams.precision;
    size += (100 + sign);
    str = helper_strNew(helper_countNumerals(chislo) + 1);
    if (sign == 1)
        str[i++] = '-';
    helper_convertDblInteger(&chislo, &str, &i, (helper_findMultiplier(chislo, &size)));
    if (formatParams.precision == 0 && formatParams.precisionWillBeSpecified == 1) {
        helper_cutStr(str, formatParams.precision, formatParams.precisionSetByZero);
        return(str);
    }
    helper_convertDblDecimal(&str, &i, chislo, (helper_countNumerals(chislo) + size + 4 + sign));
    str = helper_round(str, formatParams.precision, formatParams.precisionSetByZero);
    helper_cutStr(str, formatParams.precision, formatParams.precisionSetByZero);
    str[i - 1] = '\0';
    return (str);
}

//Конвертирует целую часть дабла
void    helper_convertDblDecimal(char **str, int *i, long double chislo, int accuracy) {
    int		j;
    int		tmp;
    char	*s;

    chislo *= 10;
    j = 0;
    s = *str;
    s[(*i)++] = '.';
    while (j++ < accuracy)
    {
        tmp = ((long long int)chislo != 9) ? (long long int)(chislo + 0.01) : (long long int)chislo;
        s[(*i)++] = (char)(tmp + 48);
        chislo = (chislo - tmp) * 10;
    }
}

//Конвертирует десятичную часть дабла
void    helper_convertDblInteger(long double *ldblNumber, char **str, int *i, long int multiplier) {
        char    *s;
        long int b;

        b = (long int)*ldblNumber;
        s = *str;
        if (b < 0) {
            *ldblNumber *= -1;
            b *= -1;
        }
        if (b == 0)
            s[(*i)++] = '0';
        *ldblNumber -= (long double)b;
        while (multiplier >= 1)
        {
            s[(*i)++] = (char)((b / multiplier) + 48);
            b = b - (b / multiplier) * multiplier;
            multiplier /= 10;
        }
}

//Округлятор последней цифры
char    *helper_round(char *str, int accuracy, int precisionSetByZero) {
    int i = 0;

    while(str[i] != '.') {
        i++;
    }
    if (accuracy == 0 && precisionSetByZero) {
        accuracy = 0;
    } else if (accuracy == 0) {
        accuracy = 6;
    }
    i += accuracy + 1;
    if (str[i] >= '5') {
        str[--i] += 1;
    }
    return (str);
}
