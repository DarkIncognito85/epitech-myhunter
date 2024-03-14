/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** my_revstr.c
*/
#include "my.h"

void my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char tmp;

    while (str[i] != '\0')
        i++;
    i--;
    while (i > j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i--;
        j++;
    }
}
