/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** sf2.c
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "my.h"
#include "sf.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value) {
        rect->left = 0;
    }
}

int move_position_negative(sfSprite *sprite, sfVector2f *pos, int x, int y)
{
    pos->x = pos->x - x;
    pos->y = pos->y - y;
    set_position(sprite, pos->x, pos->y);
    return 0;
}

int move_position_positive(sfSprite *sprite, sfVector2f *pos, int x, int y)
{
    pos->x = pos->x + x;
    pos->y = pos->y + y;
    set_position(sprite, pos->x, pos->y);
    return 0;
}

sfIntRect set_rect(sfSprite *sprite, int width, int height)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = width;
    rect.height = height;
    sfSprite_setTextureRect(sprite, rect);
    return rect;
}
