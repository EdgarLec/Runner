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
#include "include/my_struct.h"

void touch_wall(int i, all *pic)
{
    if (pic->bool.is_atk == -1 &&
    pic->map[i][pic->bool.block_passed + 3].type == 3)
        end_kill(pic, i);
    if (pic->map[i][pic->bool.block_passed + 4].type >= 1 && pic->plc_p.y -
    240 < pic->map[i][pic->bool.block_passed + 4].pos.y - 135 && pic->plc_p
    .y > pic->map[i][pic->bool.block_passed + 4].pos.y - 135) {
        if (pic->map[i][pic->bool.block_passed + 4].type == 1)
            pic->bool.lose = 1;
        touch_nme(pic, i);
        if (pic->map[i][pic->bool.block_passed + 4].type == 2) {
            sfSprite_setScale(pic->map[i][pic->bool.block_passed + 4]
            .pic, (sfVector2f){0, 0});
            pic->map[i][pic->bool.block_passed + 4].type = 0;
            pic->bool.score++;
            sfSound_play(pic->s.ting);
        }
        draw_sword(pic, i);
    }
}

void touch_ground(all *pic)
{
    sfSprite_setPosition(pic->ray_light
    , (sfVector2f){pic->map[0][pic->bool.size - 1].pos.x, 0});
    change_score(pic);
    pic->bool.is_ground = 0;
    pic->bool.is_head_touch = 0;
    if (pic->bool.size < pic->bool.block_passed + 4)
        return;
    for (int i = 0; i < 7; i++) {
        if (pic->map[i][pic->bool.block_passed + 4].type == 1 &&
        pic->plc_p.y - 260 == pic->map[i][pic->bool.block_passed + 4]
        .pos.y - 135) {
            pic->bool.is_head_touch = 1;
        }
        if (pic->map[i][pic->bool.block_passed + 4].type == 1 &&
        pic->plc_p.y == pic->map[i][pic->bool.block_passed + 4].pos.y - 135) {
            pic->bool.is_ground = 1;
        }
        touch_wall(i, pic);
    }
}

void change_score(all *pic)
{
    sfSprite_setTextureRect(pic->sc.d1, (sfIntRect)
    {0, (pic->bool.score % 10) * 102, 80, 100});
    sfSprite_setTextureRect(pic->sc.d10, (sfIntRect)
    {0, pic->bool.score / 10 % 10 * 102, 80, 100});
    sfSprite_setTextureRect(pic->sc.d100, (sfIntRect)
    {0, pic->bool.score / 100 % 10 * 102, 80, 100});
    sfSprite_setTextureRect(pic->sc.b1, (sfIntRect)
    {0, (pic->bool.best_score % 10) * 102, 80, 100});
    sfSprite_setTextureRect(pic->sc.b10, (sfIntRect)
    {0, pic->bool.best_score / 10 % 10 * 102, 80, 100});
    sfSprite_setTextureRect(pic->sc.b100, (sfIntRect)
    {0, pic->bool.best_score / 100 % 10 * 102, 80, 100});
}

void move_block(all *pic)
{
    pic->bool.anim_mob < 39 ? pic->bool.anim_mob++ : (pic->bool.anim_mob = 0);
    for (int i = 0; pic->map[i] != 0; i++) {
        for (int j = 0; j <= pic->bool.size; j++) {
            move_all_block(pic, i, j);
        }
    }
    touch_ground(pic);
}

int evt(all *pic, sfEvent event)
{
    while (sfRenderWindow_pollEvent(pic->window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyX)) {
            des(pic);
            return 1;
        }
        if (sfKeyboard_isKeyPressed(sfKeyR)) {
            free_map(pic);
            set_pic(pic);
            return 1;
        }
    }
    return 0;
}
