/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** sf.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "my.h"
#include "sf.h"

sfTexture* load_texture(const char *filename)
{
    sfTexture* texture;

    texture = sfTexture_createFromFile(filename, NULL);
    return texture;
}

sfSprite* load_sprite(sfTexture *texture)
{
    sfSprite *sprite;

    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

sfFont* load_font(const char *filename)
{
    sfFont* font;

    font = sfFont_createFromFile(filename);
    return font;
}

sfMusic* load_music(const char *filename)
{
    sfMusic* music;

    music = sfMusic_createFromFile(filename);
    return music;
}

sfSprite* set_position(sfSprite *sprite, int x, int y)
{
    sfVector2f scale = {x, y};

    sfSprite_setPosition(sprite, scale);
    return sprite;
}
