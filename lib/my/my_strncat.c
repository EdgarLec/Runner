/*
** EPITECH PROJECT, 2021
** my_strncat.c
** File description:
** concat str n
*/

#include <stdio.h>

char *my_strncat(char *dest , char const *src, int n)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        i++;
    }
    while (src[j] != '\0' && j < n) {
        dest[i] = src[j];
        i++;
        j++;
    }
    return dest;
}
