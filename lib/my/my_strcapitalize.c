/*
** EPITECH PROJECT, 2021
** my_strcapitalize.c
** File description:
** cap for firs letter fo world
*/

static void go_cap(char *str, int i)
{
    if (str[i + 1] <= 122 && str[i + 1] >= 90) {
        str[i + 1] -= 32;
    }
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= 90 && str[i] >= 65)
            str[i] += 32;
        i++;
    }
    i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
            go_cap(str, i);
        if (i == 0 && str[i] <= 122 && str[i] >= 97)
            str[i] -= 32;
        i++;
    }
    return str;
}
