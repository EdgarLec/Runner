/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf.c
*/
#include <stdio.h>
#include "include/my.h"
#include <stdarg.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my_struct.h"

int get_file_size(char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        return -1;
    char test[2];
    int i = 0;
    for (; read(fd, test, 1) == 1; i++);
    close(fd);
    return i;
}

void ground_perso(all *pic)
{
    for (int i = 0; i < 7; i++) {
        if (pic->map[i][3].type == 1) {
            pic->plc_p.y = pic->map[i][3].pos.y - 150;
            return;
        }
    }
    pic->plc_p.y += 160;
}

void print_usage(void)
{
    my_printf("Exemple:\n");
    my_printf("    ./my_runner map/map1\n\n");
    my_printf("Interactions:\n");
    my_printf("    space (in game) = jump\n");
    my_printf("    x = Quit\n");
    my_printf("    r = restart\n");
    my_printf("    [escape] = pause\n");
    my_printf("    o (in menu) = change skin\n   ");
    my_printf(" Click on “start txt” = start with the map in argument\n    C");
    my_printf("lick on “Procedural” = start with an infinite map\n\nIf you t");
    my_printf("ouch a light you win a point in the score.\nIf you have a swo");
    my_printf("rd you can kill one enemy and you win a point in the score.\n");
}
