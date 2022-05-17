cmake_minimum_required(VERSION 3.22)
project(s21_string- C)

set(CMAKE_C_STANDARD 11)

add_executable(s21_string src/s21_strcmp.c src/s21_strcpy.c src/s21_strncmp.c src/s21_strncpy.c src/s21_strlen.c src/helpers/helpers.c src/main.c headers/s21_string.h src/s21_memchr.c src/s21_memcmp.c src/s21_memcpy.c src/s21_memmove.c src/s21_sprintf.c src/s21_memset.c src/s21_strcat.c src/s21_strncat.c src/s21_strchr.c src/s21_isDigit.c src/helpers/floatConvertions.c src/helpers/doubleConvertions.c src/s21_strdup.c src/helpers/buffWriting.c src/test.c)
