/*
** EPITECH PROJECT, 2021
** is_in
** File description:
** is_in
*/
#include <stdio.h>
#include "my.h"
#include <stdarg.h>

int is_in(char *str, char c)
{
    for (int i = 0; str[i] != 0; i++)
        if (str[i] == c)
            return 1;
    return 0;
}
