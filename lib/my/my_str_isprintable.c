/*
** EPITECH PROJECT, 2021
** my_str_isprintable.c
** File description:
** only printable character
*/

int my_str_isprintable(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= 126 && str[i] >= 32)
            i++;
        else
            return 0;
    }
    return 1;
}
