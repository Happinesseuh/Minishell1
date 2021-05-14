/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-1-minishell1-ines.maaroufi
** File description:
** functions_lib
*/

#include "../includes/minishell.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int x = 0;

    while (str[x] != '\0') {
        my_putchar(str[x]);
        x++;
    }
    return (x);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] > s2[i]) {
            return (1);
        }else if (s1[i] < s2[i]) {
            return (-1);
        }
    }
    if (s1[i] == s2[i]) {
        return (0);
    }
}

char *my_strcat(char *dest, char const *src, char c)
{
    int i = my_strlen(dest);
    int j = 0;

    dest[i] = c;
    i += 1;
    for (j = 0; src[j] != '\0'; j++) {
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int my_strlen(char const *str)
{
    int x = 0;

    while (str[x] != '\0') {
        x++;
    }
    return (x);
}