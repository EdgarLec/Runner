/*
** EPITECH PROJECT, 2021
** cat.c
** File description:
** cat.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

char *my_realloc(char *str, int size)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + size + 1));
    if (new_str == 0)
        return 0;
    for (int i = 0; i < my_strlen(str) + size + 1; new_str[i] = 0, i++);
    my_strcpy(new_str, str);
    free(str);
    return new_str;
}
