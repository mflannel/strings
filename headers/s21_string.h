/* Что сейчас необходимо сделать,
 *
 * ПРОТЕСТИРОВАТЬ
 *
 */

#ifndef UNTITLED_HEADERS_H
#define UNTITLED_HEADERS_H
#endif

#define BUFFSIZE 1024                       //Размер буфера
#define s21_NULL ((void *)0)                //Собственный НУЛЛ

#include <stdarg.h>                         //Вариадические функции
#include <stdlib.h>                         //Маллок и прочие сепульки
#include <math.h>                           //Лимиты инф
#include <float.h>                          //Лимиты ДБЛМАКС

typedef long unsigned s21_size_t;      //Собственный size_t

struct s_format {
    int isInt;
    int flagPlus;
    int flagMinus;
    int flagSpace;
    int width;
    int precision;
    int precisionWillBeSpecified;
    int precisionSetByZero;
    int length_h;
    int length_l;
    int isLongDouble;
    int isAsteriskWidth;
    int isAsteriskFloatWidthDescription;
    int precisionIsNull;
    int widthMustBeWrittenByZero;
    int widthZeroDetected;
    int spec;
};

s21_size_t      s21_strlen                  (const char *str);
int		        s21_isDigit                 (int character);
int             s21_sprintf                 (char *str, const char *format, ...);
void            *s21_memchr                 (const void *arr, int c, s21_size_t n);
void	        *s21_memmove                (void *dst, const void *src, s21_size_t len);
void	        *s21_memcpy                 (void *dst, const void *src, s21_size_t n);
int		        s21_memcmp                  (const void *s1, const void *s2, s21_size_t n);
void            *s21_memset                 (void *b, int c, s21_size_t len);
char            *s21_strcat                 (char * dest, const char * src);
char            *s21_strncat                (char *dest, const char *str, s21_size_t n);
char	        *s21_strdup                 (const char *s1);
char            *s21_strcpy                 (char *dest, const char *src);

///Функции-помощники для Sprintf!

void            helper_initStruct           (struct s_format *formatParams);
int             helper_isSpec               (char c, struct s_format *formatParams);
void            helper_writeInBuffer        (const char **format, char **str, struct s_format *formatParams, va_list vlist, char *buff);
void            helper_writeChar            (const char **format, char **str, struct s_format *formatParams, char c);
void            helper_writePercent         (const char **format, char **str);
static void	    helper_isNegative           (int *n, int *neg);
void	        helper_bZero                (void *s, s21_size_t n);
void	        *helper_memalloc            (s21_size_t size);
char		    *helper_itoa                (int n);
void	        helper_strdel               (char **as);
int		        helper_countNumerals        (long double chislo);
char	        *helper_strNew              (s21_size_t size);
char            *helper_round               (char *str, int accuracy, int precisionSetByZero);
void			helper_cutStr               (char *str, int pres, int isSetByZero);
void			helper_convertInteger       (double *fpNumber, char **str, int *i, long int multiplier);
void			helper_convertDecimal       (char **str, int *i, float fpNumber, int accuracy);
void			helper_convertDblInteger    (long double *ldblNumber, char **str, int *i, long int multiplier);
void			helper_convertDblDecimal    (char **str, int *i, long double chislo, int accuracy);
char			*helper_floatMaxConversion  (char *str);
long long int	helper_findMultiplier       (long double fpNumber, int *size);
char	        *helper_ftoa                (long double f, struct s_format formatParams);
char	        *helper_dtoa                (long double ldNumber, struct s_format formatParams);
void	        helper_isNegative           (int *n, int *neg);
char		    *helper_utoa                (unsigned int n);
char		    *helper_ldtoa               (long int n);

void            writeInt                    (char *buff, struct s_format *formatParams, char *string);
void            handleFlags                 (char *buff, struct s_format *formatParams);
void            handlePrec                  (char *buff, struct s_format *formatParams);

void            handleString                (struct s_format *formatParams, char *buff, char *str);
void            handleWideString            (struct s_format *formatParams, char *buff, wchar_t *wstr);

void            writeFloat                  (char *buff, struct s_format *formatParams, char *string);