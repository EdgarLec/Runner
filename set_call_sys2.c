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

int set_sys4(all *pic)
{
    pic->s.ting = sfSound_create();
    pic->s.woosh = sfSound_create();
    pic->s.forest = sfMusic_createFromFile("sound/sound.ogg");
    pic->s.mus = sfMusic_createFromFile("sound/muse.ogg");
    pic->s.run = sfMusic_createFromFile("sound/run.ogg");
    pic->s.tingbuf = sfSoundBuffer_createFromFile("sound/ting.ogg");
    pic->s.wooshbuf = sfSoundBuffer_createFromFile("sound/woosh.ogg");
    if (pic->s.forest == 0 || pic->s.mus == 0 || pic->s.run == 0 || pic->s.
    tingbuf == 0 || pic->s.wooshbuf == 0)
        return 84;
    return 0;
}

void set_up_down(int j, int i, all *pic)
{
    switch (j) {
    case 10:
        pic->map[i][j].pos.y += 56;
        pic->map[i][j].secpos.y += 56;
        break;
    case 11:
        pic->map[i][j].pos.y += 128;
        pic->map[i][j].secpos.y += 128;
        break;
    case 12:
        pic->map[i][j].pos.y += 196;
        pic->map[i][j].secpos.y += 196;
        break;
    default:
        if (j >= 13) {
            pic->map[i][j].pos.y += 200;
            pic->map[i][j].secpos.y += 200;
        }
        break;
    }
}
