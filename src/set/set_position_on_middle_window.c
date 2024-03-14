/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** set_position_on_middle_window.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include "sf.h"

int set_position_on_middle_window(sfSprite *sprite, sfRenderWindow *window)
{
    sfVector2u windowSize = sfRenderWindow_getSize(window);
    sfIntRect size = sfSprite_getTextureRect(sprite);
    int width = size.width;
    int height = size.height;
    int x = (float)(windowSize.x - width);
    int y = (float)(windowSize.y - height);

    set_position(sprite, x / 2, y / 2);
    return 0;
}

int set_pos_middle_offset(sfSprite *sprite, sfRenderWindow *win, int offset)
{
    sfVector2u windowSize = sfRenderWindow_getSize(win);
    sfIntRect size = sfSprite_getTextureRect(sprite);
    int width = size.width;
    int height = size.height;
    int x = (float)(windowSize.x - width);
    int y = (float)(windowSize.y - height);

    set_position(sprite, x / 2, (y / 2) - offset);
    return 0;
}

int set_pos_top_offset(sfSprite *sprite, sfRenderWindow *win, int offset)
{
    sfVector2u windowSize = sfRenderWindow_getSize(win);
    sfIntRect size = sfSprite_getTextureRect(sprite);
    int width = size.width;
    int height = size.height;
    int x = (float)(windowSize.x - width);
    int y = (float)(windowSize.y - height);

    set_position(sprite, x - offset, y);
    return 0;
}
