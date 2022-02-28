/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf.c
*/
#include <stdio.h>
#include "my.h"

void double_free(int size, char **str)
{
    for (int i = 0; i < size; i++)
        free(str[i]);
    free(str);
}
