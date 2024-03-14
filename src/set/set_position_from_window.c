/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** set_position_from_window.c
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include "sf.h"

sfVector2f set_position_from_window(sfSprite *sprite, sfRenderWindow *window)
{
    sfVector2u windowSize = sfRenderWindow_getSize(window);
    int width = sfSprite_getTextureRect(sprite).width;
    int random = random_nbr(0, windowSize.y - 100);
    sfVector2f position;

    if (width == 576){
        width = 96;
    }
    position = (sfVector2f){windowSize.x - width + 50, random};
    set_position(sprite, (windowSize.x - width + 50), random);
    return position;
}
