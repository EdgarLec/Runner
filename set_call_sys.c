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

int set_sys3(all *pic)
{
    pic->mn.procedural = open_picture("pic/procedural.png", 1.2, 1.2);
    pic->bk.fog = open_picture("pic/fog.png", 1, 1);
    pic->bk.back2 = open_picture("pic/back2.png", 1, 1);
    pic->bk.back3 = open_picture("pic/back3.png", 1, 1);
    pic->bk.back4 = open_picture("pic/back4.png", 1, 1);
    pic->mn.txt = open_picture("pic/txt.png", 1.2, 1.2);
    pic->bk.back = open_picture("pic/background.png", 1, 1);
    pic->mn.quit = open_picture("pic/quit.png", 1.2, 1.2);
    if (pic->mn.procedural == 0 || pic->bk.fog == 0 || pic->bk.back2 == 0 ||
    pic->bk.back3 == 0 || pic->bk.back4 == 0 || pic->mn.txt == 0 || pic->mn.
    quit == 0 || pic->bk.back == 0)
        return 84;
    return 0;
}

int set_sys2(all *pic)
{
    pic->ps.bc_mn = open_picture("pic/bk_mn.png", 1.2, 1.2);
    pic->ps.quit = open_picture("pic/quit.png", 1.2, 1.2);
    pic->lose = open_picture("pic/perso.png", 2.5, 2.5);
    pic->sc.d1 = open_picture("pic/digit.png", 1, 1);
    pic->sc.d10 = open_picture("pic/digit.png", 1, 1);
    pic->sc.d100 = open_picture("pic/digit.png", 1, 1);
    pic->sc.b1 = open_picture("pic/digit.png", 1, 1);
    pic->sc.b10 = open_picture("pic/digit.png", 1, 1);
    pic->sc.b100 = open_picture("pic/digit.png", 1, 1);
    pic->ps.resume = open_picture("pic/resume.png", 1.2, 1.2);
    pic->ps.restart = open_picture("pic/restart.png", 1.2, 1.2);
    pic->ps.back = open_picture("pic/square.png", 24, 13);
    if (pic->ps.bc_mn == 0 || pic->ps.quit == 0 || pic->lose == 0 || pic->sc.d1
    == 0 || pic->sc.d10 == 0 || pic->sc.d100 == 0 || pic->sc.b1 == 0 || pic->sc
    .b10 == 0 || pic->sc.b100 == 0 || pic->ps.resume == 0 || pic->ps.restart ==
    0 || pic->ps.back == 0 || set_sys4(pic) == 84)
        return 84;
    return 0;
}

int set_sys(all *pic)
{
    pic->vic.you_won = open_picture("pic/won.png", 1.2, 1.2);
    pic->ray_light = open_picture("pic/ray_light.png", 2, 110);
    pic->txtu.block = sfTexture_createFromFile("pic/square.png", 0);
    pic->txtu.grass = sfTexture_createFromFile("pic/grass.png", 0);
    pic->txtu.lights = sfTexture_createFromFile("pic/light.png", 0);
    pic->txtu.nme = sfTexture_createFromFile("pic/nme.png", 0);
    pic->txtu.sword = sfTexture_createFromFile("pic/sword.png", 0);
    pic->ylose = open_picture("pic/ylose.png", 1, 1);
    pic->sc.best_score = open_picture("pic/bsc.png", 0.73333, 0.73333);
    if (pic->vic.you_won == 0 || pic->ray_light == 0 || pic->txtu.block == 0
    || pic->txtu.grass == 0 || pic->txtu.lights == 0 || pic->txtu.nme == 0 ||
    pic->txtu.sword == 0 || pic->ylose == 0 || set_sys2(pic) == 84 ||
    pic->sc.best_score == 0 || set_sys3(pic) == 84)
        return 84;
    return 0;
}

void des_all2(all *pic)
{
    sfSprite_destroy(pic->sc.b1);
    sfSprite_destroy(pic->sc.b10);
    sfSprite_destroy(pic->sc.b100);
    sfSprite_destroy(pic->ps.resume);
    sfSprite_destroy(pic->ps.restart);
    sfSprite_destroy(pic->ps.back);
    sfSprite_destroy(pic->sc.best_score);
    sfSprite_destroy(pic->bk.back);
    sfSprite_destroy(pic->bk.back2);
    sfSprite_destroy(pic->bk.back3);
    sfSprite_destroy(pic->bk.back4);
    sfSprite_destroy(pic->bk.fog);
    sfSprite_destroy(pic->mn.quit);
    sfSprite_destroy(pic->mn.txt);
    sfSprite_destroy(pic->mn.procedural);
    des_song(pic);
}

void des_all(all *pic)
{
    sfTexture_destroy(pic->txtu.block);
    sfTexture_destroy(pic->txtu.grass);
    sfTexture_destroy(pic->txtu.lights);
    sfTexture_destroy(pic->txtu.nme);
    sfTexture_destroy(pic->txtu.sword);
    sfSprite_destroy(pic->vic.you_won);
    sfSprite_destroy(pic->ray_light);
    sfSprite_destroy(pic->ylose);
    sfSprite_destroy(pic->ps.bc_mn);
    sfSprite_destroy(pic->ps.quit);
    sfSprite_destroy(pic->lose);
    sfSprite_destroy(pic->sc.d1);
    sfSprite_destroy(pic->sc.d10);
    sfSprite_destroy(pic->sc.d100);
    des_all2(pic);
}
