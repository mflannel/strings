#include "../../headers/s21_string.h"

void handlePrec(char *buff, struct s_format *formatParams) {
    char tmp[BUFFSIZE] = {'\0'};
    int isNeg = 0;
    int len = s21_strlen(buff);

    if (buff[0] == '-') {
        tmp[0] = '-';
        len--;
        isNeg = 1;
    }

    if (formatParams->precision > len) {
        int i;
        for (i = isNeg; i < formatParams->precision - len + isNeg; i++)
            tmp[i] = '0';

        for (int j = isNeg; buff[j]; i++, j++)
            tmp[i] = buff[j];

        s21_strcpy(buff, tmp);
    }
    if (formatParams->precisionWillBeSpecified && formatParams->precision == 0 &&
        formatParams->isInt && buff[0] == '0')
        buff[0] = '\0';
};

void handleFlags(char *buff, struct s_format *formatParams) {
    char tmp[BUFFSIZE + 1] = {'\0'};
    if (formatParams->flagPlus && !formatParams->spec) {
        tmp[0] = buff[0] == '-' ? buff[0] : '+';
        s21_strcpy(tmp + 1, buff[0] == '-' ? buff + 1 : buff);
        s21_strcpy(buff, tmp);
    } else if (formatParams->flagSpace && buff[0] != '-' && formatParams->spec != 1) {
        tmp[0] = ' ';
        s21_strcpy(tmp + 1, buff);
        s21_strcpy(buff, tmp);
    }
    if (formatParams->width > (int)s21_strlen(buff)) {
        int i = formatParams->width - s21_strlen(buff);
        if (!formatParams->flagMinus) {
            s21_memset(tmp, formatParams->widthMustBeWrittenByZero ? '0' : ' ', i);
            s21_strcpy(tmp + i, buff);
        } else {
            s21_strcpy(tmp, buff);
            s21_memset(tmp + s21_strlen(tmp), ' ', i);
        }
        s21_strcpy(buff, tmp);
    }
}

void writeInt(char *buff, struct s_format *formatParams, char *string) {
    s21_memcpy(buff, string, s21_strlen(string));
    handlePrec(buff, formatParams);
    handleFlags(buff, formatParams);
}

void handleString(struct s_format *formatParams, char *buff, char *str) {
    char tmp[BUFFSIZE] = {'\0'};
    s21_strcpy(tmp, str);
    if (formatParams->precisionWillBeSpecified)
        tmp[formatParams->precision] = '\0';

    int shift = formatParams->width - s21_strlen(tmp);
    int len = s21_strlen(tmp);
    if (formatParams->precisionIsNull)
        s21_memset(tmp, ' ', len);
    if (formatParams->flagMinus && shift > 0) {
        s21_strcpy(buff, tmp);
        s21_memset(buff + len, ' ', shift);
    } else if (shift > 0) {
        s21_memset(buff, ' ', shift);
        s21_strcpy(buff + shift, tmp);
    } else {
        s21_strcpy(buff, tmp);
    }
}

void handleWideString(struct s_format *formatParams, char *buff, wchar_t *wstr) {
    char tmp[BUFFSIZE] = {'\0'};
    char str[BUFFSIZE] = {'\0'};

    wcstombs(str, wstr, BUFFSIZE);
    s21_strcpy(tmp, str);
    if (formatParams->precisionWillBeSpecified)
        tmp[formatParams->precision] = '\0';

    int shift = formatParams->width - s21_strlen(tmp);
    int len = s21_strlen(tmp);

    if (formatParams->flagMinus && shift > 0) {
        s21_strcpy(buff, tmp);
        s21_memset(buff + len, ' ', shift);
    } else if (shift > 0) {
        s21_memset(buff, ' ', shift);
        s21_strcpy(buff + shift, tmp);
    } else {
        s21_strcpy(buff, tmp);
    }
}

void writeFloat(char *buff, struct s_format *formatParams, char *string) {
    s21_memcpy(buff, string, s21_strlen(string));
    handleFlags(buff, formatParams);
}