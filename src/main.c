#include <stdio.h>
#include "../headers/s21_string.h"


int  main() {
//
//
//    char buff[10000];
//    char buff1[10000];
    char buff2[10000];
    char buff3[10000];
//    char buff4[10000];
//    char buff5[10000];
//    char buff6[10000];
//    char buff7[10000];
//    char buff8[10000];
//    char buff9[10000];
//    char buff10[10000];
//    char buff11[10000];
//    char buff12[10000];
//    char buff13[10000];
//    char buff14[10000];
//    char buff15[10000];
//    char buff16[10000];
//    char buff17[10000];
//    char buff18[10000];
//    char buff19[10000];
//    char buff20[10000];
//    char buff21[10000];
//    char buff22[10000];





    /* Test1 */

//
//    printf("TEST1\n");
//    sprintf(buff, "%d\n", 3);
//    printf(buff);
//    printf("\n");
//    s21_sprintf(buff1, "%d\n", 3);
//    printf(buff1);
//
//    printf("\n");
//    printf("\n");

    /* Test2 */
    printf("TEST2\n");
    sprintf(buff2, "%-010.10d%10.3f%+10.4d", 252, 243, 256, 15);
    printf(buff2);
    printf("\n");
    s21_sprintf(buff3, "%-010.10d%10.3f%+10.4d", 252, 243, 256, 15);
    printf(buff3);

//    /* Test3 */
//    printf("TEST3\n");
//    sprintf(buff4, "%34.10d%.10d%15d%25.10s", 25, 1234, 4567, "HELLOMYDEARFRIEND");
//    //sprintf(buff, "%+34.10d%d%15d%25s", 25, 1234, 4567, "HELLOMYDEARFRIEND");
//    printf(buff4);
//    printf("\n");
//    s21_sprintf(buff5, "%34.10d%.10d%15d%25.10s", 25, 1234, 4567, "HELLOMYDEARFRIEND");
//    printf(buff5);
//
//////    helper_bZero(buff, s21_strlen(buff));
//////    helper_bZero(buff, s21_strlen(buff));
//
//    printf("\n");
//    printf("\n");
//
//    /* Test4 */
//    printf("TEST4\n");
//    int p = 43252342;
//    sprintf(buff6, "%010.15d%15.20i%20d%20d", 1234, 567890, p, 123456789);
//    printf(buff6);
//    printf("\n");
//    s21_sprintf(buff7, "%010.15d%15.20i%20d%20d", 1234, 567890, p, 123456789);
//    printf(buff7);
//
////    helper_bZero(buff, s21_strlen(buff));
////    helper_bZero(buff, s21_strlen(buff));
//
//    printf("\n");
//    printf("\n");
////
//    /* Test5 */
//    printf("TEST5\n");
//    int h = 34;
//    sprintf(buff8, "%-25.10d%-30.2d%10.12d%11d%*d%*.*d%+-25.*d%+10.2ld%-11.*hd", 253, 335, 1234, 34, 10, 25, 5, 15, 345, 5, 666, 456789l, 5, h);
//    printf(buff8);
//    printf("\n");
//    s21_sprintf(buff9, "%-25.10d%-30.2d%10.12d%11d%*d%*.*d%+-25.*d%+10.2ld%-11.*hd", 253, 335, 1234, 34, 10, 25, 5, 15, 345, 5, 666, 456789l, 5, h);
//    printf(buff9);
//
////    helper_bZero(buff, s21_strlen(buff));
////    helper_bZero(buff, s21_strlen(buff));
//
//    printf("\n");
//    printf("\n");
////
//    /* Test6 */
//    printf("TEST6\n");
//    long l = 2353423523424;
//    sprintf(buff10, "%+50.i%-10.20i%10.i%012i%*.*i%-10.*i%+10.1li%*.25hi",
//            34567, 225, 5230, 125, 10, 5, 456, 10, 377, l, 12, h);
//    printf(buff10);
//    printf("\n");
//    s21_sprintf(buff11, "%+50.i%-10.20i%10.i%012i%*.*i%-10.*i%+10.1li%*.25hi",
//                34567, 225, 5230, 125, 10, 5, 456, 10, 377, l, 12, h);
//    printf(buff11);
//
//    printf("\n");
//    printf("\n");
//
//    /* Test7 */
//    printf("TEST7\n");
//    char c1 = 'c';
//    char c2 = 'T';
//    sprintf(buff12, "%10c%-10c%25c%-30c%25c%*c%2c%*c%lc%-50lc",
//            'a', 'e', 'f', 'R', 'Q', 10, 'P', 'L', 20, 'x', c1, c2);
//    printf(buff12);
//    printf("\n");
//    s21_sprintf(buff13, "%10c%-10c%25c%-30c%25c%*c%2c%*c%lc%-50lc",
//                'a', 'e', 'f', 'R', 'Q', 10, 'P', 'L', 20, 'x', c1, c2);
//    printf(buff13);
//
//
//    printf("\n");
//    printf("\n");
//
//    /* Test8 */
//    printf("TEST8\n");
//
//    sprintf(buff13,"%-10.f%+-10.f%15.f%+*.10f%*.16f%-10.*f%25.*f%25.1f%+10.2f%*.*f",
//            2546.4324, 3452.4325, 5678.43256, 25, 456789.243242, 10, 3456789123.43245, 2, 12345.6788,
//            1, 34.4325432, 4325678.43242, 34567.2345432, 10, 2, 34567.43244);
//    printf(buff13);
//    printf("\n");
//    s21_sprintf(buff14, "%-10.f%+-10.f%15.f%+*.10f%*.16f%-10.*f%25.*f%25.1f%+10.2f%*.*f",
//                2546.4324, 3452.4325, 5678.43256, 25, 456789.243242, 10, 3456789123.43245, 2, 12345.6788,
//                1, 34.4325432, 4325678.43242, 34567.2345432, 10, 2, 34567.43244);
//    printf(buff14);
//
//
//    printf("\n");
//    printf("\n");
//
//    /* Test9 */
//    printf("TEST9\n");
//
//    unsigned short x = 115;
//    unsigned long k = 123325242342l;
//
//    sprintf(buff15, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu",
//            4321, 34567, 2342, 12346, 234542, 10, 234523, 10, 5, 2345, 20, 2432, k, x);
//    printf(buff15);
//    printf("\n");
//    s21_sprintf(buff16, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu",
//                4321, 34567, 2342, 12346, 234542, 10, 234523, 10, 5, 2345, 20, 2432, k, x);
//    printf(buff16);
//
//
//
//    printf("\n");
//    printf("\n");
//
//    /* Test10 */
//    printf("TEST10\n");
//
//    wchar_t s[10] = {'h', 'e', 'l', 'l', 'o'};
//
//    sprintf(buff17, "%s%23s%-15s%10.s%15.s%16.*s%*.*s%*s%15ls%15.3ls",
//            "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", 10, "QWERTY",
//            15, 4, "AAAAABOOOOOBAAA", 10, "ABOBAAAAA", s, s);
//    printf(buff17);
//    printf("\n");
//    s21_sprintf(buff18, "%s%23s%-15s%10.s%15.s%16.*s%*.*s%*s%15ls%15.3ls",
//                "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", 10, "QWERTY",
//                15, 4, "AAAAABOOOOOBAAA", 10, "ABOBAAAAA", s, s);
//    printf(buff18);
//
//    helper_bZero(buff, s21_strlen(buff));
//    helper_bZero(buff, s21_strlen(buff));
//
//    printf("\n");
//    printf("\n");
//
//    /* Test11 */
//    printf("TEST11\n");
//
//    sprintf(buff19, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
//    printf(buff19);
//    printf("\n");
//    s21_sprintf(buff20, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
//    printf(buff20);
//
//    helper_bZero(buff, s21_strlen(buff));
//    helper_bZero(buff, s21_strlen(buff));
//
//    printf("\n");
//    printf("\n");


}