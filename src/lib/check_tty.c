/*
** EPITECH PROJECT, 2023
** CSFML
** File description:
** check_tty.c
*/
#include <stdio.h>
#include "my.h"

int check_tty(char *envp[])
{
    for (int i = 0; envp[i] != NULL; i++) {
        if (envp[i][0] == 'D' && envp[i][1] == 'I' && envp[i][2] == 'S' &&
            envp[i][3] == 'P' && envp[i][4] == 'L' && envp[i][5] == 'A' &&
            envp[i][6] == 'Y' && envp[i][7] == '=') {
            return 0;
        }
    }
    my_putstr("Plop: Terminal is not supported\n");
    return 84;
}
