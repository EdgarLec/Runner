/*
** EPITECH PROJECT, 2021
** my_str_isalpha.c
** File description:
** only letter
*/
#include <unistd.h>

int my_str_isalpha(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] <= 90 && str[i] >= 65 )
        || (str[i] <= 122 && str[i] >= 97))
            i++;
        else
            return 0;
    }
    return 1;
}
