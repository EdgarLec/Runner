/*
** EPITECH PROJECT, 2021
** my_puchar.c
** File description:
** write
*/
#include <unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}
