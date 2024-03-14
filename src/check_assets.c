/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** check_assets.c
*/
#include <fcntl.h>
#include <stdio.h>
#include "my.h"

int check_asset(char *filename)
{
    int fd = open(filename, O_RDONLY);

    close(fd);
    if (fd < 0){
        my_putstr(filename);
        return 84;
    }
    return 0;
}

int check_assets_part1(void)
{
    if (check_asset("assets/bg-1.jpg") == 84)
        return 84;
    if (check_asset("assets/switch.png") == 84)
        return 84;
    if (check_asset("assets/bg-2.jpg") == 84)
        return 84;
    if (check_asset("assets/play.png") == 84)
        return 84;
    if (check_asset("assets/sprites.png") == 84)
        return 84;
    if (check_asset("assets/Games.ttf") == 84)
        return 84;
    if (check_asset("assets/gameover.png") == 84)
        return 84;
    return 0;
}

int check_assets(void)
{
    if (check_assets_part1() == 84){
        return 84;
    }
    if (check_asset("assets/firewall.png") == 84)
        return 84;
    if (check_asset("assets/alarm.ogg") == 84)
        return 84;
    if (check_asset("assets/minus.png") == 84)
        return 84;
    if (check_asset("assets/plus.png") == 84)
        return 84;
    if (check_asset("assets/mute.png") == 84)
        return 84;
    if (check_asset("assets/mute2.png") == 84)
        return 84;
    return 0;
}
