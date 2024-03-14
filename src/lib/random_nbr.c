/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** random_nbr.c
*/

#include <stdlib.h>
#include <time.h>

int random_nbr(int min, int max)
{
    int random_number;

    srand((unsigned int)time(NULL));
    random_number = rand() % (max - min + 1) + min;
    return random_number;
}
