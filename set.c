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

sfSprite *open_w_texture(sfTexture *texture, double x, double y)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {x, y};

    sfSprite_setScale(sprite, scale);
    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

sfSprite *open_picture(char *png, double x, double y)
{
    sfTexture *texture = sfTexture_createFromFile(png, 0);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {x, y};

    sfSprite_setScale(sprite, scale);
    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

int set_map(all *pic)
{
    int fd = open(pic->map_path, O_RDONLY);
    int file_s = get_file_size(pic->map_path);
    char **map = malloc(sizeof(char *) * (8));
    pic->map = malloc(sizeof(square *) * (8));
    if (map == 0 || pic->map == 0 || file_s == -1)
        return 84;
    pic->map[7] = 0;
    pic->bool.size = (file_s) / 7 - 1;
    for (int i = 0; i < 7; i++) {
        map[i] = malloc(sizeof(char) * ((file_s) / 7 + 1));
        pic->map[i] = malloc(sizeof(square) * ((file_s) / 7 + 1));
        if (map[i] == 0 || pic->map[i] == 0)
            return 84;
        read(fd, map[i], ((file_s) / 7));
        map[i][((file_s) / 7)] = 0;
        set_map2(pic, i, file_s, map);
    }
    double_free(7, map);
    return 0;
}

int set_pic2(all *pic)
{
    set_perso(pic);
    sfMusic_setLoop(pic->s.run, 1);
    sfMusic_setVolume(pic->s.run, 25);
    sfMusic_play(pic->s.run);
    sfSprite_setTextureRect(pic->lose, (sfIntRect){800 , 800, 160, 160});
    sfSprite_setPosition(pic->lose, (sfVector2f){760, 300});
    sfSprite_setPosition(pic->ylose, (sfVector2f){650, 650});
    sfMusic_setLoop(pic->s.forest, 1);
    sfMusic_setVolume(pic->s.forest, 20);
    sfMusic_play(pic->s.forest);
    sfMusic_setLoop(pic->s.mus, 1);
    sfMusic_setVolume(pic->s.mus, 20);
    sfMusic_play(pic->s.mus);
    pic->color = 0;
    pic->bool.score = 0;
    pic->bool.anim_mob = 0;
    pic->bool.is_stop = 0;
    pic->bool.block_passed = 0;
    pic->bool.is_jumping = 0;
    pic->bool.is_ground = 1;
}

int set_pic(all *pic)
{
    pic->bool.is_head_touch = 0;
    int verif = 0;
    pic->bk.r2 = (sfIntRect){0 , 0, W_, L_};
    sfSprite_setTextureRect(pic->bk.back2, pic->bk.r2);
    pic->bk.r3 = (sfIntRect){0 , 0, W_, L_};
    sfSprite_setTextureRect(pic->bk.back3, pic->bk.r3);
    pic->bk.r4 = (sfIntRect){0 , 0, W_, L_};
    sfSprite_setTextureRect(pic->bk.back4, pic->bk.r4);
    set_pic2(pic);
    sfRenderWindow_setFramerateLimit(pic->window, 60);
    set_sc(pic);
    set_stop(pic);
    if (pic->bool.procedural == 0)
        verif = set_map(pic);
    else
        verif = set_proced_map(pic);
    if (verif == 84)
        return 84;
    ground_perso(pic);
    return 0;
}
