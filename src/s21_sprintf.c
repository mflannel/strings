#include "../headers/s21_string.h"

//ЗДЕСЬ МЫ ПРОВЕРЯЕМ ИНПУТ (Format) НА НАЛИЧИЕ СПЕЦИФИКАТОРОВ И ОТМЕЧАЕМ ТО, ЧТО НАШЛИ В СТРУКТУРЕ inputLineParams
/*
 * Флаги:
 *        - '-' -> Результат преобразования выравнивается по левому краю
 *        - '+' -> Перед положительными числами выводится знак ' ', а перед отрицательными знак '-'
 *        - ' ' -> Если не указан +, то перед положительными числами на месте знака будет выводиться пробел
 *
 * Спецификаторы:
 *        - с -> char
 *        - d -> decimal
 *        - i -> int
 *        - f -> float
 *        - s -> string aka char*
 *        - u -> unsigned
 *        - % -> %
 *
 * Ширина:
 *        - (number) -> Минимальное количества символов для печати. Если значение для записи короче этого числа,
 *        результат набивается пустыми пробелами.
 *
 * Точность:
 *        - .number -> Только для числительных (d, i, o, u, x, X). Точность определяет минимальное количество цифр,
 *        которые будут записаны. Более детальное описание см. таск на платформе.
 *
 * Длина:
 *        - h -> Аргумент интерпретируется как short int или unsigned short int.
 *        - l -> Аргумент интерпретируется как long int или unsigned long int and as a wide character or wide character
 *        string for specifiers c and s.
 */

int parser(const char **inputLine, struct s_format *inputLineParams) {

    int flags = 0;

    while (**inputLine) {
        if (**inputLine == '-' || **inputLine == '+' || **inputLine == ' ') {
            if (**inputLine == '-')
                inputLineParams->flagMinus = 1;
            else if (**inputLine == '+')
                inputLineParams->flagPlus = 1;
            else if (**inputLine == ' ')
                inputLineParams->flagSpace = 1;
            (*inputLine)++;
        } else if (s21_isDigit(**inputLine) == 1) {
            if (**inputLine == '0' && inputLineParams->widthZeroDetected == 0) {
                (*inputLine)--;
                if (s21_isDigit(**inputLine) == 0) {
                    inputLineParams->widthMustBeWrittenByZero = 1;
                    inputLineParams->widthZeroDetected = 1;
                }
                (*inputLine)++;
            }
            inputLineParams->width = **inputLine - '0' + inputLineParams->width * 10;
            (*inputLine)++;
        } else if (**inputLine == '*') {
            (*inputLine)--;
            if (**inputLine != '.') {
                inputLineParams->isAsteriskWidth = 1;
                (*inputLine)++;
            } else
                (*inputLine)++;
            (*inputLine)++;
        } else if (**inputLine == '.') {
            (*inputLine)++;
            if ((!s21_isDigit(**inputLine)) && **inputLine != '*')
                inputLineParams->precisionIsNull = 1;
            if (**inputLine == '*') {
                inputLineParams->isAsteriskFloatWidthDescription = 1;
                inputLineParams->precisionWillBeSpecified = 1;
            } else if (**inputLine == 'L' || **inputLine == 'f' || s21_isDigit(**inputLine) == 1)
                inputLineParams->precisionWillBeSpecified = 1;
            else if (**inputLine == '0')
                inputLineParams->precisionSetByZero = 1;
            while (s21_isDigit(**inputLine)) {
                inputLineParams->precision = **inputLine - '0' + inputLineParams->precision * 10;
                (*inputLine)++;
            }
        } else if (**inputLine == 'h' || **inputLine == 'l' || **inputLine == 'L') {
            if (**inputLine == 'h')
                inputLineParams->length_h = 1;
            else if (**inputLine == 'l')
                inputLineParams->length_l = 1;
            else if (**inputLine == 'L')
                inputLineParams->isLongDouble = 1;
            (*inputLine)++;
        } else if (helper_isSpec(**inputLine, inputLineParams) == 1) {
            flags = 1;
            break;
        } else {
            flags = 0;
            break;
        }
    }
    return flags;
}

int s21_sprintf(char *str, const char *format, ...) {
    struct s_format formatParams;
    helper_initStruct(&formatParams);

    va_list vlist;
    va_start(vlist, format);

    while (*format) {
        if (*format != '%') {
            *str = *format;
            str++;
            format++;
        } else {
            //struct s_format formatParams;
            helper_initStruct(&formatParams);
            format++;
            char buff[BUFFSIZE] = {'\0'};
            if (parser(&format, &formatParams) == 1) {
                helper_writeInBuffer(&format, &str, &formatParams, vlist, buff);
            }
            for (int i = 0; buff[i]; i++, str++)
                *str = buff[i];
        }
    }
    va_end(vlist);
    return (s21_strlen(str));
}

void helper_writeInBuffer(const char **format, char **str, struct s_format *formatParams, va_list vlist, char *buff) {

    if (**format == 'c') {
        if (formatParams->isAsteriskWidth) {
            formatParams->width = va_arg(vlist, int);
        }
        char c = va_arg(vlist, int);
        helper_writeChar(format, str, formatParams, c);
    } else if (**format == 'L') {
        formatParams->isLongDouble = 1;
    } else if (**format == '%') {
        if (formatParams->isAsteriskWidth) {
            formatParams->width = va_arg(vlist, int);
        }
        helper_writePercent(format, str);
    } else if (**format == 's') {
        if (formatParams->isAsteriskWidth) {
            formatParams->width = va_arg(vlist, int);
        }
        if (formatParams->isAsteriskFloatWidthDescription) {
            formatParams->precision = va_arg(vlist, int);
        }
        if (formatParams->length_l) {
            wchar_t *stringd = va_arg(vlist, wchar_t *);
            handleWideString(formatParams, buff, stringd);
            (*format)++;
        } else {
            char *string = va_arg(vlist, char *);
            handleString(formatParams, buff, string);
            (*format)++;
        }
    } else if (**format == 'd' || **format == 'i') {
        formatParams->isInt = 1;
        if (formatParams->isAsteriskWidth)
            formatParams->width = va_arg(vlist, int);
        if (formatParams->isAsteriskFloatWidthDescription)
            formatParams->precision = va_arg(vlist, int);
        if (formatParams->length_l) {
            long int lint = va_arg(vlist, long int);
            if (lint < 0)
                formatParams->flagPlus = 0;
            char *tempr = helper_ldtoa(lint);
            writeInt(buff, formatParams, tempr);
            free (tempr);
            (*format)++;
        } else if (formatParams->length_h) {
            short int sint = va_arg(vlist, int);
            if (sint < 0)
                formatParams->flagPlus = 0;
            char *templ = helper_itoa(sint);
            writeInt(buff, formatParams, templ);
            free (templ);
            (*format)++;
        } else {
            int intParam = va_arg(vlist, int);
            if (intParam < 0)
                formatParams->flagPlus = 0;
            char *temp = helper_itoa(intParam);
            writeInt(buff, formatParams, temp);
            free (temp);
            (*format)++;
        }
    } else if (**format == 'f') {
        if (formatParams->isAsteriskWidth)
            formatParams->width = va_arg(vlist, int);
        if (formatParams->isAsteriskFloatWidthDescription) {
            if (!formatParams->precisionIsNull)
                formatParams->precision = va_arg(vlist, int);
            else
                formatParams->precision = 0;
        }
        if (formatParams->isLongDouble) {
            long double floatParam = va_arg(vlist, long double);
            char *s = helper_dtoa(floatParam, *formatParams);
            writeFloat(buff, formatParams, s);
            free(s);
            (*format)++;
        } else {
            double floatParam = va_arg(vlist, double);
            char *st = helper_ftoa(floatParam, *formatParams);
            writeFloat(buff, formatParams, st);
            free(st);
            (*format)++;
        }
    } else if (**format == 'u') {
        if (formatParams->isAsteriskWidth)
            formatParams->width = va_arg(vlist, int);
        if (formatParams->isAsteriskFloatWidthDescription) {
            if (!formatParams->precisionIsNull)
                formatParams->precision = va_arg(vlist, int);
            else
                formatParams->precision = 0;
        }
        unsigned int uint = (unsigned) va_arg(vlist, unsigned int);
        char *temp = helper_utoa(uint);
            writeInt(buff, formatParams, temp);
            free(temp);
            (*format)++;
    }
}