/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** my_strcmp.c
*/
#include "my.h"
int my_strcmp(char const *str, char const *expected)
{
    int i = 0;

    while (str[i] != '\0' && expected[i] != '\0') {
        if (str[i] != expected[i])
            return 1;
        i++;
    }
    if (str[i] != expected[i])
        return 1;
    return 0;
}
