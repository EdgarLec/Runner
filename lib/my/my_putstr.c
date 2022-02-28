/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** write string
*/
#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return i;
}

int loop_tmp(int tmp)
{
    for (; tmp > 0; tmp--, my_putchar('0'));
    return tmp;
}

int my_putstrbug(char const *str)
{
    int i = 0;
    int tmp = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] > 127) {
            my_putchar(92);
            tmp = 2 - my_size_nbr_base(str[i], 8);
            tmp = loop_tmp(tmp);
            my_putnbr_base(str[i], "01234567");
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
    return i;
}
