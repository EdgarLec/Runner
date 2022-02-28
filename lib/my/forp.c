/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf.c
*/
#include <stdio.h>
#include "my.h"
#include <stdarg.h>

int forp3(char *str2, unsigned long int nbr, int *flag)
{
    int rt = (flag[1] < flag[3]) ? flag[3] : flag[1];
    flag[3] != 0 ? flag[1] -= flag[3] - flag[5] : 0;
    flag[4] += 2;
    flag[0] == 1 && flag[2] == 1 ? my_putchar('+') : 0;
    for (; flag[1] - flag[5] - flag[4] > 0
    && !is_in(str2, '-') && flag[0] == 0; flag[1]--)
        my_putchar(' ');
    flag[2] == 1 && flag[0] == 0 ? my_putchar('+') : 0;
    my_putstr("0x");
    for (; flag[1] - flag[5] - flag[4] > 0
    && !is_in(str2, '-') && flag[0] == 1; flag[1]--)
        my_putchar('0');
    for (; flag[3] - flag[5] > 0; flag[3]--)
        flag[0] == 0 ? my_putchar('0') : my_putchar('0');
    my_putnbr_base_long(nbr, "0123456789abcdef");
    for (; flag[1] - flag[5] - flag[4] > 0 && is_in(str2, '-'); flag[1]--)
        my_putchar(' ');
    return (rt > flag[5] ? rt + flag[4] + 2 : flag[5] + flag[4]);
}

int forp2(char *str2, unsigned long int nbr, int i, int *flag)
{
    int x = -1;
    if (is_in("123456789", str2[i]))
        flag[1] += my_getnbr(str2 + i);
    for (; is_in("1234567890", str2[i]) == 1; i++);
    if (!(is_in(".lhp", str2[i])))
        return my_putstr(str2);
    str2[i] == '.' ? flag[3] = my_getnbr(str2 + i + 1) : i--;
    i++;
    for (; is_in("1234567890", str2[i]) == 1; i++);
    if (str2[i - 1] == '.' && !(is_in("lhp", str2[i]))) {
        for (; str2[x] != '.'; x++, my_putchar(str2[x]));
        my_putchar('0');
        for (; str2[x] != 0; x++, my_putchar(str2[x]));
        return x;
    }
    return forp3(str2, nbr, flag);
}

int forp(char *str2, unsigned long int nbr)
{
    int i = 1;
    int flag[6] = {0, 0, 0, 0, 0, 0};
    flag[5] = my_size_nbr_base(nbr, 16);
    for (; is_in("-+ #0", str2[i]) == 1; i++) {
        (str2[i] == '+' && nbr > 0) ? (flag[2] = 1) && (flag[4]++) : 0;
        str2[i] == '0' && !is_in(str2, '.') ? flag[0] = 1 : 0;
    }
    if (!(is_in("0.123456789lhp", str2[i])))
        return my_putstr(str2);
    return forp2(str2, nbr, i, flag);
}
