/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf.c
*/
#include <stdio.h>
#include "my.h"
#include <stdarg.h>

int dis_forusi(char *str2, unsigned int nbr, int *flag)
{
    switch (str2[my_strlen(str2) - 1]) {
        case 'x': my_putnbr_base(nbr, "0123456789abcdef");
            break;
        case 'X': my_putnbr_base(nbr, "0123456789ABCDEF");
            break;
        case 'o': my_putnbr_base(nbr, "01234567");
            break;
        case 'u': my_putnbr_base(nbr, "0123456789");
            break;
        default: my_putnbr_base(nbr, "01");
            break;
    }
}

int size_forusi(char *str2, unsigned int nbr, int *flag)
{
    switch (str2[my_strlen(str2) - 1]) {
        case 'x': return my_size_nbr_base(nbr, 16);
            break;
        case 'X': return my_size_nbr_base(nbr, 16);
            break;
        case 'o': return my_size_nbr_base(nbr, 8);
            break;
        case 'u': return my_size_nbr_base(nbr, 10);
            break;
        default: return my_size_nbr_base(nbr, 2);
            break;
    }
}

int forusi3(char *str2, unsigned int nbr, int *flag)
{
    int rt = (flag[1] < flag[3]) ? flag[3] : flag[1];
    flag[3] != 0 ? flag[1] -= flag[3] - flag[5] : 0;
    flag[4] += is_in("xXb", str2[my_strlen(str2) - 1])
    && is_in(str2, '#') ? 2 : 0;
    flag[4] += 'o' == str2[my_strlen(str2) - 1] && is_in(str2, '#') ? 1 : 0;
    for (; flag[1] - flag[5] - flag[4] > 0 && !is_in(str2, '-')
    && flag[0] == 0; flag[1]--)
        my_putchar(' ');
    htag(str2);
    for (; flag[1] - flag[5] - flag[4] > 0 && !is_in(str2, '-')
    && flag[0] == 1; flag[1]--)
        my_putchar('0');
    for (; flag[3] - flag[5] > 0; flag[3]--)
        my_putchar('0');
    dis_forusi(str2, nbr, flag);
    for (; flag[1] - flag[5] - flag[4] > 0 && is_in(str2, '-'); flag[1]--)
        my_putchar(' ');
    return (rt > flag[5] ? rt + flag[4] : flag[5] + flag[4]);
}

int forusi2(char *str2, unsigned int nbr, int i, int *flag)
{
    int x = -1;
    if (is_in("123456789", str2[i]))
        flag[1] += my_getnbr(str2 + i);
    for (; is_in("1234567890", str2[i]) == 1; i++);
    if (!(is_in(".lhxXoub", str2[i])))
        return my_putstr(str2);
    str2[i] == '.' ? flag[3] = my_getnbr(str2 + i + 1) : i--;
    i++;
    for (; is_in("1234567890", str2[i]) == 1; i++);
    if (str2[i - 1] == '.' && !(is_in("lhxXoub", str2[i]))) {
        for (; str2[x] != '.'; x++, my_putchar(str2[x]));
        my_putchar('0');
        for (; str2[x] != 0; x++, my_putchar(str2[x]));
        return x;
    }
    return forusi3(str2, nbr, flag);
}

int forusi(char *str2, unsigned int nbr)
{
    int i = 1;
    int flag[6] = {0, 0, 0, 0, 0, 0};
    flag[5] = size_forusi(str2, nbr, flag);
    for (; is_in("-+ #0", str2[i]) == 1; i++) {
        str2[i] == '0' && !is_in(str2, '.') ? flag[0] = 1 : 0;
    }
    if (!(is_in("0.123456789lhxXoub", str2[i])))
        return my_putstr(str2);
    return forusi2(str2, nbr, i, flag);
}
