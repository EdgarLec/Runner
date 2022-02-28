/*
** EPITECH PROJECT, 2021
** my_str_islower.c
** File description:
** only lowercase
*/

int my_str_islower(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= 122 && str[i] >= 97)
            i++;
        else
            return 0;
    }
    return 1;
}
