#include "../headers/s21_string.h"

int		s21_isDigit(int character)
{
    if (character >= 48 && character <= 57)
        return (1);
    else
        return (0);
}