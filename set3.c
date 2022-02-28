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

void set_best_score(all *pic)
{
    int fd = open("score", O_RDONLY);
    char bs[4];
    bs[3] = '\0';
    read(fd, bs, 3);
    pic->bool.best_score = my_getnbr(bs);
    close(fd);
}

void new_best_score(all *pic)
{
    int fd = open("score", O_RDONLY | O_WRONLY);
    char bs[4];
    bs[3] = '\0';
    if (pic->bool.best_score < pic->bool.score) {
        bs[0] = (pic->bool.score / 100) % 10 + '0';
        bs[1] = (pic->bool.score / 10) % 10 + '0';
        bs[2] = (pic->bool.score) % 10 + '0';
        write(fd, bs, 3);
    }
    close(fd);
}

void set_won(all *pic)
{
    sfSprite_setPosition(pic->vic.you_won, (sfVector2f){600, 450});
    pic->bool.is_won = 0;
    sfSound_setBuffer(pic->s.ting, pic->s.tingbuf);
    sfSound_setBuffer(pic->s.woosh, pic->s.wooshbuf);
    sfSound_setVolume(pic->s.woosh, 30);
    pic->bool.lose = 0;
    pic->bool.anim = 0;
    pic->bool.atk = 0;
    pic->bool.is_atk = 0;
}

void set_menu(all *pic)
{
    sfSprite_setPosition(pic->mn.txt, (sfVector2f){500, 250});
    sfSprite_setColor(pic->mn.txt, (sfColor){_A, _A, _A, 200});
    sfSprite_setPosition(pic->mn.procedural, (sfVector2f){500, 450});
    sfSprite_setColor(pic->mn.procedural, (sfColor){_A, _A, _A, 200});
    sfSprite_setPosition(pic->mn.quit, (sfVector2f){500, 650});
    sfSprite_setColor(pic->mn.quit, (sfColor){_A, _A, _A, 200});
    set_won(pic);
    set_best_score(pic);
}

int set_perso(all *pic)
{
    pic->rec_p = (sfIntRect){80 , 1, 80, 80};
    sfSprite_setTextureRect(pic->perso, pic->rec_p);
    if (pic->bool.procedural == 0)
        pic->plc_p = (sfVector2f){400, 825};
    else
        pic->plc_p = (sfVector2f){360, 825};
    sfSprite_setPosition(pic->perso, pic->plc_p);
    if (pic->txtu.block == 0 || pic->txtu.grass == 0 || pic->txtu.lights == 0
    || pic->txtu.nme == 0 || pic->txtu.sword == 0)
        return 84;
    return 0;
}
