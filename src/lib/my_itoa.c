/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** my_itoa.c
*/

#include "my.h"
#include <stdlib.h>
char *my_itoa(int nb)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 100);

    if (nb == 0)
        return "0";
    while (nb != 0) {
        str[i] = nb % 10 + '0';
        nb = nb / 10;
        i++;
    }
    str[i] = '\0';
    my_revstr(str);
    return str;
}
