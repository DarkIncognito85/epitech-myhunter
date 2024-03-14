/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** set_position_text.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include "sf.h"

int set_position_text(sfText *text, int offset)
{
    sfVector2f position;

    position.x = offset;
    position.y = 10;
    sfText_setPosition(text, position);
    return 0;
}

int set_position_text_middle(sfText *text, sfRenderWindow *window)
{
    sfVector2u windowSize = sfRenderWindow_getSize(window);
    sfVector2f position;

    position.x = (windowSize.x / 2) - 100;
    position.y = (windowSize.y / 2) + 100;
    sfText_setPosition(text, position);
    sfText_setCharacterSize(text, 50);
    return 0;
}

int set_position_hidden(sfText *text)
{
    sfVector2f position;

    position.x = -100;
    position.y = -100;
    sfText_setPosition(text, position);
    sfText_setCharacterSize(text, 50);
    return 0;
}

int set_position_heading(sfText *text)
{
    sfVector2f position;

    position.x = 200;
    position.y = 100;
    sfText_setPosition(text, position);
    sfText_setCharacterSize(text, 50);
    return 0;
}
