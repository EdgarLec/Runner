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

void change_skin(all *pic)
{
    if (pic->color == 0) {
            pic->perso = open_picture("pic/perso2.png", 2, 2);
            pic->color = 1;
        } else {
            pic->perso = open_picture("pic/perso.png", 2, 2);
            pic->color = 0;
        }
        set_perso(pic);
}

int evnt_menu(sfEvent event, all *pic)
{
    if (event.type == sfEvtMouseButtonPressed) {
        sfMouseButtonEvent pos = event.mouseButton;
        sfVector2u s = sfRenderWindow_getSize(pic->window);
        if (pos.x * W_ / s.x >= 500 && pos.x * W_ / s.x <= 1400 && pos.y
        * L_ / s.y >= 650 && pos.y * L_ / s.y <= 770) {
            des(pic);
            return 84;
        }
        if (pos.x * W_ / s.x >= 500 && pos.x * W_ / s.x <= 1400 && pos.y
        * L_ / s.y >= 450 && pos.y * L_ / s.y <= 570) {
            pic->bool.in_menu = 0;
            free_map(pic);
            pic->bool.procedural = 1;
            sfRenderWindow_setMouseCursorVisible(pic->window, 0);
            set_pic(pic);
        }
        evt_menu2(pic, pos, s);
    }
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyO))
        change_skin(pic);
}

void free_map(all *pic)
{
    for (int i = 0; pic->map[i] != 0 && (pic->bool.in_menu == 0); i++) {
        for (int j = 0; j <= pic->bool.size; j++) {
            (pic->map[i][j].secpic != 0) ?
            sfSprite_destroy(pic->map[i][j].secpic) : 0;
            (pic->map[i][j].pic != 0) ?
            sfSprite_destroy(pic->map[i][j].pic) : 0;
        }
        free(pic->map[i]);
    }
    free(pic->map);
}

void draw_won(all *pic)
{
    new_best_score(pic);
    sfRenderWindow_drawSprite(pic->window, pic->ps.back, 0);
    if (pic->bool.lose == 0)
        sfRenderWindow_drawSprite(pic->window, pic->vic.you_won, 0);
    else {
        pic->rec_p.top = 800;
        sfSprite_setTextureRect(pic->perso, pic->rec_p);
        sfRenderWindow_drawSprite(pic->window, pic->lose, 0);
        sfRenderWindow_drawSprite(pic->window, pic->ylose, 0);
    }
    sfRenderWindow_drawSprite(pic->window, pic->sc.d1, 0);
    sfRenderWindow_drawSprite(pic->window, pic->sc.d10, 0);
    sfRenderWindow_drawSprite(pic->window, pic->sc.d100, 0);
    sfRenderWindow_drawSprite(pic->window, pic->sc.best_score, 0);
    sfRenderWindow_drawSprite(pic->window, pic->sc.b1, 0);
    sfRenderWindow_drawSprite(pic->window, pic->sc.b10, 0);
    sfRenderWindow_drawSprite(pic->window, pic->sc.b100, 0);
    pic->bool.is_won = 1;
}

void color_stop2(all *pic, sfVector2i pos, sfVector2u s)
{
    if (pos.x * W_ / s.x >= 700 && pos.x * W_ / s.x <= 1600 && pos.y
    * L_ / s.y >= 600 && pos.y * L_ / s.y <= 760) {
        sfSprite_setColor(pic->ps.bc_mn, (sfColor){_A, _A, _A, _A});
    } else
        sfSprite_setColor(pic->ps.bc_mn, (sfColor){_A, _A, _A, 200});
    if (pos.x * W_ / s.x >= 700 && pos.x * W_ / s.x <= 1600 && pos.y
    * L_ / s.y >= 800 && pos.y * L_ / s.y <= 960) {
        sfSprite_setColor(pic->ps.quit, (sfColor){_A, _A, _A, _A});
    } else
        sfSprite_setColor(pic->ps.quit, (sfColor){_A, _A, _A, 200});
}
