/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** displays a string
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}
