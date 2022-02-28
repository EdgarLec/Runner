/*
** EPITECH PROJECT, 2021
** my_str_isnum.c
** File description:
** only nbr
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= 58 && str[i] >= 48)
            i++;
        else
            return 0;
    }
    return 1;
}
