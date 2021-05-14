/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-1-minishell1-ines.maaroufi
** File description:
** cd_and_execute
*/

#include "../includes/minishell.h"

char *get_access(char **get_env, char **tab)
{
    int acc_f;
    int acc_x;
    char *tmp = NULL;

    for (int i = 0; get_env[i] != NULL; i++) {
        tmp = my_strcat(my_strdup(get_env[i]), my_strdup(tab[0]), '/');
        acc_f = access(tmp, F_OK);
        acc_x = access(tmp, X_OK);
        if (acc_f != (-1) && acc_x != (-1))
            return (tmp);
    }
    tmp = tab[0];
    acc_f = access(tmp, F_OK);
    acc_x = access(tmp, X_OK);
    if (acc_f != (-1) && acc_x != (-1))
        return (tmp);
    return (NULL);
}

void execute(char *path, char **env)
{
    char **tab = my_str_to_word_array(my_strdup(path), " ");
    char **get_env = my_str_to_word_array
        (my_strdup(my_getenv(env, "PATH=")), ":");
    int cpid = fork();
    int status;

    if (cpid == 0) {
        if (execve(get_access(get_env, tab), tab, env) == -1) {
                my_putstr(path);
                my_putstr(": Command not found.\n");
        }
    } else {
        waitpid(cpid, &status, 0);
        if (WIFSIGNALED(status) && WTERMSIG(status) && !WCOREDUMP(status))
            my_putstr("Segmentation fault without core dumped\n");
        if (WIFSIGNALED(status) && WTERMSIG(status) && WCOREDUMP(status))
            my_putstr("Segmentation fault (core dumped)\n");
    }
}

void failed_open(int result, char *path)
{
    if (result < 0) {
        my_putstr(path);
        perror(" ");
    }
}

char **cd(char *path, char **env)
{
    char *dir = NULL;
    int result = 0;
    static int cd = 0;

    if (path == NULL || my_strcmp(path, "~") == 0) {
        env = my_setenv("OLDPWD", my_getenv(env, "PWD="), env);
        dir = my_getenv(env, "HOME="); cd = 1;
    } else if (my_strcmp(path, "-") == 0 && cd != 0)
        dir = my_getenv(env, "OLDPWD=");
    else {
        env = my_setenv("OLDPWD", my_getenv(env, "PWD="), env);
        dir = path; cd = 1;
    }
    if (path != NULL && my_strcmp(path, "-") == 0 && cd == 0)
        return (env);
    result = chdir(dir);
    failed_open(result, path);
    env = my_setenv("PWD", getcwd(dir, 1000), env);
    return (env);
}