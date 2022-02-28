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

int evnt(sfEvent event, all *pic)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyX)) {
        des(pic);
        return 84;
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace) && pic->bool.is_ground == 1
    && pic->bool.is_stop == 0) {
        pic->bool.is_jumping = 35;
        pic->rec_p.top = 80 * 9;
        pic->rec_p.left = 80;
    }
    if (sfKeyboard_isKeyPressed(sfKeyR) && pic->bool.in_menu == 0) {
        free_map(pic);
        set_pic(pic);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && pic->bool.in_menu == 0) {
        if (event.key.code == sfKeyEscape)
            pic->bool.is_stop = (pic->bool.is_stop == 1) ? 0 : 1;
        (pic->bool.is_stop == 1) ? sfRenderWindow_setMouseCursorVisible(pic->
        window, 1) : sfRenderWindow_setMouseCursorVisible(pic->window, 0);
    }
}

void jump(all *pic)
{
    if (pic->bool.is_jumping > 0 || pic->bool.is_ground == 0) {
        pic->bool.is_jumping -= 2.5;
        pic->plc_p.y -= pic->bool.is_jumping;
        for (int i = 0; i < 7; i++)
            (pic->map[i][pic->bool.block_passed + 4].type == 1 &&
            pic->plc_p.y > pic->map[i][pic->bool.block_passed + 4]
            .pos.y - 135 && pic->plc_p.y < pic->map[i]
            [pic->bool.block_passed + 4].pos.y + 25) ? pic->plc_p.y
            = pic->map[i][pic->bool.block_passed + 4].pos.y - 135 : 0;
        sfSprite_setPosition(pic->perso, pic->plc_p);
        return;
    }
    pic->bool.is_jumping = -7.5;
    pic->bool.is_atk == 0 ? pic->rec_p.top = 2 : 0;
}

void move_sprite(all *pic, sfClock **clock, sfClock **clock2)
{
    if (sfClock_getElapsedTime(*clock2).microseconds >= 32500 && (pic->bool
    .in_menu == 0)) {
        if (pic->bool.is_atk > 0 && pic->bool.is_won == 0)
            move_atk(pic);
        pic->bool.is_won == 0 ? jump(pic) : 0;
        move_perso(pic);
        sfClock_restart(*clock2);
    }
    if (sfClock_getElapsedTime(*clock).microseconds >= 6000 &&
    pic->bool.is_won == 0) {
        pic->bk.r2.left >= 3136 ? pic->bk.r2.left = 0 : (pic->bk.r2.left += 4);
        sfSprite_setTextureRect(pic->bk.back2, pic->bk.r2);
        pic->bk.r3.left >= 2809 ? pic->bk.r3.left = 0 : (pic->bk.r3.left += 6);
        sfSprite_setTextureRect(pic->bk.back3, pic->bk.r3);
        pic->bk.r4.left >= 3718 ? pic->bk.r4.left = 0 : (pic->bk.r4.left += 9);
        sfSprite_setTextureRect(pic->bk.back4, pic->bk.r4);
        (pic->bool.in_menu == 0) ? move_block(pic) : 0;
        sfClock_restart(*clock);
    }
}

void draw(all *pic)
{
    sfRenderWindow_drawSprite(pic->window, pic->bk.back, 0);
    sfRenderWindow_drawSprite(pic->window, pic->bk.back2, 0);
    sfRenderWindow_drawSprite(pic->window, pic->bk.fog, 0);
    sfRenderWindow_drawSprite(pic->window, pic->bk.back3, 0);
    sfRenderWindow_drawSprite(pic->window, pic->bk.back4, 0);
    if (pic->bool.in_menu == 0)
        sfRenderWindow_drawSprite(pic->window, pic->perso, 0);
    for (int i = 0; pic->map[i] != 0 && (pic->bool.in_menu == 0); i++)
        for (int j = 0; j <= pic->bool.size; j++) {
            (pic->map[i][j].secpic != 0) ?
            sfRenderWindow_drawSprite(pic->window
            , pic->map[i][j].secpic, 0) : 0;
            (pic->map[i][j].pic != 0) ?
            sfRenderWindow_drawSprite(pic->window, pic->map[i][j].pic, 0) : 0;
        }
    if (pic->bool.in_menu == 0) {
        draw_ui(pic);
    } else
        draw_menu(pic);
}

void draw_lose(all *pic)
{
    sfClock *clock = sfClock_create();
    sfEvent event;
    unsigned int x = 0;
    new_best_score(pic);
    for (;sfClock_getElapsedTime(clock).microseconds < 1500000; x += 4) {
        sfRenderWindow_clear(pic->window, sfBlack);
        sfRenderWindow_drawSprite(pic->window, pic->lose, 0);
        x <= _A ? sfSprite_setColor(pic->ylose
        , (sfColor){_A, _A, _A, x}) : 0;
        sfRenderWindow_drawSprite(pic->window, pic->ylose, 0);
        sfRenderWindow_display(pic->window);
    }
    for (int i = 0; i == 0;)
        i = evt(pic, event);
}
