/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf.c
*/
#include <stdio.h>
#include "my.h"
#include <stdarg.h>

void htag(char *str2)
{
    switch (str2[my_strlen(str2) - 1]) {
        case 'x': (is_in(str2, '#')) ? my_putstr("0x") : 0;
            break;
        case 'X': (is_in(str2, '#')) ? my_putstr("0X") : 0;
            break;
        case 'o': (is_in(str2, '#')) ? my_putstr("0") : 0;
            break;
        default: (is_in(str2, '#')) ? my_putstr("0b") : 0;
            break;
    }
}

void my_forr(int *i, char *str)
{
    for (; is_in("-+ #0.123456789lhzjt", str[(*i) + 1]) == 1; (*i)++);
}
