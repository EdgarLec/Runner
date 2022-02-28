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

int call_event(all *pic)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(pic->window, &event)) {
        int tmp = 0;
        if (evnt(event, pic) == 84)
            return 84;
        pic->bool.in_menu == 1 ? tmp = evnt_menu(event, pic) : 0;
        if (tmp == 84)
            return 84;
        pic->bool.is_stop == 1 ? tmp = evnt_stop(event, pic) : 0;
        if (tmp == 84)
            return 84;
    }
    return 0;
}

void main2(all *pic)
{
    sfClock *clock = sfClock_create();
    sfClock *clock2 = sfClock_create();
    for (int x = 0; sfRenderWindow_isOpen(pic->window);) {
        if (call_event(pic) == 84)
            return;
        if (pic->plc_p.y > 1030)
            pic->bool.lose = 1;
        if (pic->bool.is_stop == 0)
            move_sprite(pic, &clock, &clock2);
        draw(pic);
        if (pic->bool.is_stop == 1)
            draw_stop(pic);
        if (((pic->bool.procedural == 0 && pic->bool.block_passed > pic->
        bool.size - 5) || pic->bool.lose == 1)
        && pic->bool.is_stop == 0 && pic->bool.in_menu == 0)
            draw_won(pic);
        sfRenderWindow_display(pic->window);
    }
    sfClock_destroy(clock);
    sfClock_destroy(clock2);
}

void des_song(all *pic)
{
    sfMusic_destroy(pic->s.mus);
    sfMusic_destroy(pic->s.run);
    sfMusic_destroy(pic->s.forest);
    sfSound_destroy(pic->s.ting);
    sfSoundBuffer_destroy(pic->s.tingbuf);
    sfSound_destroy(pic->s.woosh);
    sfSoundBuffer_destroy(pic->s.wooshbuf);
}

void des(all *pic)
{
    free_map(pic);
    sfRenderWindow_close(pic->window);
}

int main(int argc, char *argv[])
{
    all pic_sound;
    srand(time(NULL));
    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == 0) {
            print_usage();
            return 0;
        }
        pic_sound.map_path = argv[1];
    }
    pic_sound.bool.procedural = 0;
    pic_sound.window = sfRenderWindow_create((sfVideoMode){W_, L_, 32}
    , "My_runner", sfClose | sfResize, NULL);
    pic_sound.perso = open_picture("pic/perso.png", 2, 2);
    if (set_sys(&pic_sound) == 84 || set_pic(&pic_sound) == 84)
        return 84;
    pic_sound.bool.in_menu = 1;
    main2(&pic_sound);
    des_all(&pic_sound);
    return 0;
}
