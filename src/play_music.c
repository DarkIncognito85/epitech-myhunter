/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** play_music.c
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "sf.h"
int play_music(game_t *game)
{
    if (game->autorize_music == 0)
        return 0;
    sfMusic_setPlayingOffset(game->alarm, (sfTime){0});
    sfMusic_play(game->alarm);
    return 0;
}
