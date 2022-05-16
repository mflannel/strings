//
// Created by Shirl Pate on 5/1/22.
//
#include "../../headers/s21_string.h"

//Проверяет  кейсы максмин
char	*checkFloatMaxMinCases(long double f_case, char *str) //БОЛЬШЕ ОДНОГО ВЫХОДА
{
    if (f_case == INFINITY)
        return (s21_strdup("inf"));
    if (f_case == -INFINITY)
        return (s21_strdup("-inf"));
    if (f_case == DBL_MAX || f_case == FLT_MAX)
        helper_floatMaxConversion(str);
    return (helper_strNew(2));
}

//Конвертирует флоат в строку
char	*helper_ftoa(long double f, struct s_format formatParams) //БОЛЬШЕ ОДНОГО ВЫХОДА
{
    int		i;
    double	fpNumber;
    int		size;
    char	*str;
    int		isNegative;

    i = 0;
    size = 1;
    isNegative = 0;
    fpNumber = f;

    if (fpNumber == INFINITY || fpNumber == -INFINITY || fpNumber == DBL_MAX || fpNumber == FLT_MAX)
        return (checkFloatMaxMinCases(fpNumber, str));
    if (fpNumber < 0)
        isNegative = 1;

    char *lenNum = (helper_itoa(fpNumber));

    size += (s21_strlen(lenNum) + isNegative);
    free(lenNum);
    size += formatParams.precision <= 0 ? 6 : formatParams.precision;
    size = size < 0 ? 6 : size;
    str = helper_strNew(size + 4);

    if (isNegative == 1)
        str[i++] = '-';

    helper_convertInteger(&fpNumber, &str, &i, (helper_findMultiplier(fpNumber, &size)));

    if ((formatParams.precision == 0 && formatParams.precisionWillBeSpecified == 1) || formatParams.precisionIsNull) {
        helper_cutStr(str, formatParams.precision, 1);
        return(str);
    }
    helper_convertDecimal(&str, &i, (float) fpNumber, size);
    str = helper_round(str, formatParams.precision, formatParams.precisionSetByZero);
    helper_cutStr(str, formatParams.precision, formatParams.precisionSetByZero);
    return (str);
}

//Конвертирует максимальный флоат
char			*helper_floatMaxConversion(char *str) //БОЛЬШЕ ОДНОГО ВЫХОДА
{
    int		i;
    char	float_max[50];

    i = 0;
    s21_strcpy(float_max, "340282346638528859811704183484516925440.000000\0");
    if (!(str = (char *)malloc(sizeof(float_max))))
        return (NULL);
    while (float_max[i] != '\0')
    {
        str[i] = float_max[i];
        i++;
    }
    return (str);
}
//Ищет множитель для работы с десятичной частью
long long int	helper_findMultiplier(long double fpNumber, int *size)
{
    long int	multiplier;
    long int	extra;

    extra = (long int)(fpNumber);
    multiplier = 1;
    while ((extra /= 10) != 0)
    {
        multiplier *= 10;
        size++;
    }
    return (multiplier);
}

//Конвертирует десятичную часть дабла
void			helper_convertDecimal(char **str, int *i, float fpNumber, int accuracy)
{
    int				j;
    long long int		tmp;
    char			*s;

    fpNumber *= 10;
    j = 0;
    s = *str;
    s[(*i)++] = '.';
    while (j++ < accuracy)
    {
        tmp = ((long int)fpNumber != 9) ? (long int)(fpNumber + 0.01) : (long int)fpNumber;
        s[(*i)++] = (char)(tmp + 48);
        fpNumber = (fpNumber - tmp) * 10;
    }
}

//Конвертирует целую часть дабла
void			helper_convertInteger(double *fpNumber, char **str, int *i, long int multiplier)
{
    char		*s;
    long int	b;

    b = (long int)*fpNumber;
    s = *str;
    if (b < 0)
    {
        *fpNumber *= -1;
        b *= -1;
    }
    if (b == 0)
    {
        s[(*i)++] = '0';
        return ;
    }
    *fpNumber -= (long double)b;
    while (multiplier >= 1)
    {
        s[(*i)++] = (char)((b / multiplier) + 48);
        b = b - (b / multiplier) * multiplier;
        multiplier /= 10;
    }
}

//Режет строку согласно необходимой точности
void			helper_cutStr(char *str, int pres, int isSetByZero)
{
    int	i;
    int	k;

    i = 0;
    if (isSetByZero) {
        k = 0;
    } else {
        k = pres <= 0 ? 6 : pres;
        while (str[i] != '.')
            str++;
    }

    while (k != 0 && *str)
    {
        str++;
        k--;
    }
    i -= isSetByZero ? 1 : 0;

    while (str[i++] != '\0')
        str[i] = '\0';
}

//Создает новую строку
char	*helper_strNew(s21_size_t size) //БОЛЬШЕ ОДНОГО ВЫХОДА
{
    char	*str;

    if (size + 1 < size)
        return (NULL);
    str = (char *)malloc(size + 1);
    if (str == 0)
        return (NULL);
    helper_bZero(str, size + 1);
    return (str);
}