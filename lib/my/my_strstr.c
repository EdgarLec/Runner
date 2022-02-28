/*
** EPITECH PROJECT, 2021
** my_strstr.c
** File description:
** strstr
*/
#include <stdio.h>

static int is_same(char const *s1 , char const *s2, int n)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && i < n) {
        if (s1[i] != s2[i])
            return 0;
        i++;
    }
    return 1;
}

char *my_strstr(char *str , char const *to_find)
{
    int i = 0;
    int j = 0;
    int h = 0;

    while (to_find[h] != '\0') {
        h++;
    }
    while (str[i] != '\0') {
        if (is_same(&str[i], to_find, h)) {
            j = i;
            return &str[j];
        }
        i++;
    }
    return 0;
}
