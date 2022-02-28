/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf.c
*/
#include <stdio.h>
#include "my.h"
#include <stdarg.h>

int forint3(char *str2, int nbr, int i, int *flag)
{
    int rt = (flag[1] < flag[3]) ? flag[3] : flag[1];
    flag[3] != 0 ? flag[1] -= flag[3] - my_size_nbr(nbr) : 0;
    flag[0] == 1 && flag[2] == 1 ? my_putchar('+') : 0;
    for (; flag[1] - my_size_nbr(nbr) - flag[4] > 0
    && !is_in(str2, '-'); flag[1]--)
        flag[0] == 0 ? my_putchar(' ') : my_putchar('0');
    flag[2] == 1 && flag[0] == 0 ? my_putchar('+') : 0;
    for (; flag[3] - my_size_nbr(nbr) > 0; flag[3]--)
        flag[0] == 0 ? my_putchar('0') : my_putchar('0');
    my_put_nbr(nbr);
    for (; flag[1] - my_size_nbr(nbr) - flag[4] > 0
    && is_in(str2, '-'); flag[1]--)
        my_putchar(' ');
    return (rt > my_size_nbr(nbr) ? rt + flag[4]
    : my_size_nbr(nbr) + flag[4]);
}

int forint2(char *str2, int nbr, int i, int *flag)
{
    int x = -1;
    if (is_in("123456789", str2[i]))
        flag[1] += my_getnbr(str2 + i);
    for (; is_in("1234567890", str2[i]) == 1; i++);
    if (!(is_in(".lhdi", str2[i])))
        return my_putstr(str2);
    str2[i] == '.' ? flag[3] = my_getnbr(str2 + i + 1) : i--;
    i++;
    for (; is_in("1234567890", str2[i]) == 1; i++);
    if (!(is_in("lhdi", str2[i]))) {
        for (; str2[x] != '.'; x++, my_putchar(str2[x]));
        my_putchar('0');
        for (; str2[x] != 0; x++, my_putchar(str2[x]));
        return x;
    }
    return forint3(str2, nbr, i, flag);
}

int forint(char *str2, int nbr)
{
    int i = 1;
    int flag[6] = {0, 0, 0, 0, 0};
    for (; is_in("-+ #0", str2[i]) == 1; i++) {
        (str2[i] == '+' && nbr >= 0) ? (flag[2] = 1) && (flag[4]++) : 0;
        if (str2[i] == ' ' && !is_in(str2, '+') && nbr >= 0 && flag[4] == 0) {
            my_putchar(' ');
            flag[4]++;
        }
        str2[i] == '0' && !is_in(str2, '.') ? flag[0] = 1 : 0;
    }
    if (!(is_in("0.123456789lhdi", str2[i])))
        return my_putstr(str2);
    return forint2(str2, nbr, i, flag);
}

int is_ok(char *str, int i, va_list arg)
{
    char *str2 = my_strdup("%");
    for (int j = 1; is_in("-+ #0.123456789lh", str[i]) == 1; i++, j++) {
        str2 = my_realloc(str2, 2);
        str2[j] = str[i];
    }
    str2 = my_realloc(str2, 2);
    str2[my_strlen(str2)] = str[i];
    if (is_in("id", str[i]))
        return forint(str2, va_arg(arg, int));
    if (is_in("sS", str[i]))
        return fors(str2, my_strdup(va_arg(arg, char *)));
    if (is_in("buoxX", str[i]))
        return forusi(str2, va_arg(arg, unsigned int));
    if (str[i] == 'p')
        return forp(str2, va_arg(arg, unsigned long int));
    if (str[i] == 'c')
        return forc(str2, va_arg(arg, int));
    if (str[i] == '%')
        return my_putstr("%");
    return my_putstr(str2);
}

int my_printf(char *str, ...)
{
    int i = 0;
    int j = 0;
    va_list arg;
    va_start(arg, str);
    for (; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            j += is_ok(str, i + 1, arg);
            my_forr(&i, str);
            (str[i] == '%' || is_in("sScpxXoubid", str[i + 1]) == 1)
            ? i++ : 0;
        } else {
            my_putchar(str[i]);
            j++;
        }
    }
    va_end(arg);
    return j;
}
