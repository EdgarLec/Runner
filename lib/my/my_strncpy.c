/*
** EPITECH PROJECT, 2021
** my_strncpy.c
** File description:
** copy n char
*/
#include <stdio.h>

char *my_strncpy(char *dest , char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (i < n)
        dest[i] = '\0';
    return dest;
}
