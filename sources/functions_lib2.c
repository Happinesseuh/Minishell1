/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-1-minishell1-ines.maaroufi
** File description:
** function_lib2
*/

#include "../includes/minishell.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i = 0; src[i] != '\0' ; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char const *src)
{
    char *j = malloc(sizeof(src) * (my_strlen(src)));

    my_strcpy(j, src);
    return (j);
}

char *clean_str(char *str)
{
    char *res = malloc(sizeof(char) * my_strlen(str));
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0 && (str[i] == ' ' || str[i] == '\t'))
            i += 1;
        if (!(str[i] == ' ' && str[i + 1] == ' ') &&
            !(str[i] == ' ' && str[i + 1] == '\0') && str[i] != '\t') {
            res[count] = str[i];
            count++;
        }
    }
    return (res);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int diff = 0;
    int equal = 1;

    for (i = 0; i != n && s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            diff += 1;
        }
    }
    return (diff);
}