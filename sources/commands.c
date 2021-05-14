/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-1-minishell1-ines.maaroufi
** File description:
** commands
*/

#include "../includes/minishell.h"

char *entry_command(void)
{
    char *buffer;
    size_t buffsize = 0;
    int entry = 0;

    buffer = malloc(buffsize * sizeof(char));
    if (isatty(0))
        my_putstr("$> ");
    entry = getline(&buffer, &buffsize, stdin);
    if (entry == -1)
        return (NULL);
    if (buffer[my_strlen(buffer) - 1] == '\n')
        buffer[my_strlen(buffer) - 1] = '\0';
    return (buffer);
}

int check_commands(char **tab, env_t *ev)
{
    char *commands[] = {"setenv", "unsetenv", "env", "cd"};

    if (my_strcmp(tab[0], commands[0]) == 0) {
        if (tab[2] == NULL) return (1);
        ev->env = my_setenv(tab[1], tab[2], ev->env);
        return (1);
    }
    if (my_strcmp(tab[0], commands[1]) == 0) {
        if (tab[1] == NULL) return (1);
        ev->env = my_unsetenv(tab[1], ev->env);
        return (1);
    }
    if (my_strcmp(tab[0], commands[2]) == 0) {
        my_env(ev->env);
        return (1);
    }
    if (my_strcmp(tab[0], commands[3]) == 0) {
        ev->env = cd(tab[1], ev->env);
        return (1);
    }
    return (0);
}