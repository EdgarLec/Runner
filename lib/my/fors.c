/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf.c
*/
#include <stdio.h>
#include "my.h"
#include <stdarg.h>

int fors(char *str2, char *argchar)
{
    int i = 1;
    int spc = 0;
    int size = -1;
    for (; is_in("-+ #0", str2[i]) == 1; i++);
    if (!(is_in("0.123456789lhsS", str2[i])))
        return my_putstr(str2);
    if (is_in("123456789", str2[i]) == 1)
        spc = my_getnbr(str2 + i);
    for (; is_in("0123456789", str2[i]) == 1; i++);
    (str2[i] == '.') ? size = my_getnbr(str2 + i + 1) : 0;
    for (; is_in(".0123456789", str2[i]) == 1; i++);
    if ((my_strlen(argchar) > size) && size != -1)
        argchar[size] = '\0';
    for (int tm = spc; tm - my_strlen(argchar) > 0 && !is_in(str2, '-'); tm--)
        my_putchar(' ');
    (is_in(str2, 's')) ? my_putstr(argchar) : 0;
    (is_in(str2, 'S')) ? my_putstrbug(argchar) : 0;
    for (int tm = spc; tm - my_strlen(argchar) > 0 && is_in(str2, '-'); tm--)
        my_putchar(' ');
    return (my_strlen(argchar) > spc) ? my_strlen(argchar) : spc;
}

int forc(char *str2, int c)
{
    int i = 1;
    int spc = 0;
    for (; is_in("-+ #0", str2[i]) == 1; i++);
    if (!(is_in("0.123456789lhc", str2[i])))
        return my_putstr(str2);
    if (is_in("123456789", str2[i]) == 1)
        spc = my_getnbr(str2 + i);
    for (; is_in("0123456789", str2[i]) == 1; i++);
    if (!(is_in(".lhc", str2[i])))
        return my_putstr(str2);
    for (; is_in(".0123456789", str2[i]) == 1; i++);
    if (!(is_in("lhc", str2[i])))
        return my_putstr(str2);
    for (int tm = spc; tm - 1 > 0 && !is_in(str2, '-'); tm--)
        my_putchar(' ');
    my_putchar(c);
    for (int tm = spc; tm - 1 > 0 && is_in(str2, '-'); tm--)
        my_putchar(' ');
    return (1 > spc) ? 1 : spc;
}
