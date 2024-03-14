/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** MY_H
*/


#ifndef LIB_H
    #define LIB_H
int my_strlen(char const *str);
int my_putstr(char const *str);
void my_putchar(char str);
void my_put_nbr(int nb);
int random_nbr(int min, int max);
char *my_itoa(int nb);
int check_tty(char *envp[]);
void my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
#endif /* !LIB_H */
