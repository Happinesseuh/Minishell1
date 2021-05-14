/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-1-minishell1-ines.maaroufi
** File description:
** env
*/

#include "../includes/minishell.h"
#include <string.h>
#include <stdlib.h>

void my_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (i != 0)
            my_putchar('\n');
        for (int j = 0; env[i][j] != '\0'; j++)
            my_putchar(env[i][j]);
    }
    my_putchar('\n');
}

char *my_getenv(char **env, char *str)
{
    char *result = NULL;
    int i = 0;

    for (; env[i] != NULL; i++)
        if (my_strncmp(str, env[i], my_strlen(str)) == 0) {
            break;
        }
    return (env[i] + my_strlen(str));
}

char **my_setenv_inexisting(char *var, char *value, char **env)
{
    int count = 0;
    char *var_alloc = var_alloc = malloc(sizeof(char) * (my_strlen(var) +
        my_strlen(value) + 2));
    char **new_env = NULL;
    int i = 0;

    for (count = 0; env[count] != NULL; count++);
    new_env = malloc(sizeof(char *) * count + 1);
    for (; env[i] != NULL; i++) {
        new_env[i] = malloc(sizeof(char) * my_strlen(env[i]));
        new_env[i] = env[i];
    }
    for (int j = 0; var[j] != 0; j++)
        var_alloc[j] = var[j];
    new_env[i] = my_strcat(var_alloc, value, '=');
    new_env[i + 1] = NULL;
    return (new_env);
}

char **my_setenv(char *var, char *value, char **env)
{
    int count = 0;
    char **new_env = NULL;
    char *var_alloc = malloc(sizeof(char) * (my_strlen(var) +
        my_strlen(value) + 2));
    char *name = NULL;

    for (int j = 0; env[j] != NULL; j++) {
        count = 0;
        name = malloc(sizeof(char) * 100);
        for (int k = 0; env[j][k] != '='; k++) {
            name[count] = env[j][k];
            count++;
        }
        name[count] = '\0';
        if (my_strcmp(var, name) == 0) {
            var_alloc = name;
            env[j] = my_strcat(var_alloc, value, '=');
            return (env);
        }
    }
    my_setenv_inexisting(var, value, env);
}

char **my_unsetenv(char *var, char **env)
{
    char **new_env = NULL;
    int count = 0;
    char *name = NULL;
    int i = 0;

    for (count = 0; env[count] != NULL; count++);
    new_env = malloc(sizeof(char *) * count + 1);
    for (int j = 0; env[j] != NULL; j++) {
        count = 0;
        name = malloc(sizeof(char) * my_strlen(env[j]));
        for (int k = 0; env[j][k] != '='; k++) {
            name[count] = env[j][k];
            count++;
        }
        name[count] = '\0';
        if (my_strcmp(var, name) != 0) {
            new_env[i] = malloc(sizeof(char) * my_strlen(env[j]));
            new_env[i] = env[j]; i++;
        }
    }
    return (new_env);
}