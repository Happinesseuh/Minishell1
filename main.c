/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-1-minishell1-ines.maaroufi
** File description:
** main
*/

#include "./includes/minishell.h"

void print_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (i > 0)
            my_putchar('\n');
        for (int j = 0; tab[i][j] != '\0'; j++)
            my_putchar(tab[i][j]);
    }
}

char **my_str_to_word_array(char *str, char *separator)
{
    char **tab = NULL;
    char *tmp;
    int i = 1;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == separator[0])
            count++;
    tab = malloc(sizeof(char *) * (count + 2));
    tab[0] = strtok(str, separator);
    for (int i = 1; (tmp = strtok(NULL, separator)) != NULL; i++) {
        tab[i] = tmp;
    }
    return (tab);
}

char **tabdup(char **env)
{
    int count = 0;
    char **new_env = NULL;

    for (count = 0; env[count] != NULL; count++);
    new_env = malloc(sizeof(char *) * count);
    for (count = 0; env[count] != NULL; count++) {
        new_env[count] = my_strdup(env[count]);
    }
    new_env[count] = NULL;
    return (new_env);
}

void minishell(char *get, char **arg, env_t *ev)
{
    while (my_strcmp(get, "exit") != 0) {
        if (get == NULL)
            exit (0);
        if ((check_commands(arg, ev)) == 0) {
            execute(clean_str(get), ev->env);
        }
        get = entry_command();
        if (get == NULL)
            exit (0);
        arg = my_str_to_word_array(my_strdup(clean_str(get)), " ");
    }
}

int main(int ac, char **av, char **env)
{
    char *get = NULL;
    char **arg = NULL;
    env_t ev;

    if (env[0] == NULL)
        return (84);
    get = entry_command();
    if (get == NULL)
        exit (0);
    arg = my_str_to_word_array(my_strdup(clean_str(get)), " ");
    ev.env = tabdup(env);
    if (my_strcmp(get, "exit") == 0)
        exit(0);
    minishell(get, arg, &ev);
}