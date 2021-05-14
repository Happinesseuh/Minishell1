/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-1-minishell1-ines.maaroufi
** File description:
** minishell
*/


#include <stddef.h>
#include <unistd.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>


#ifndef MINISHELL_H_
#define MINISHELL_H_

typedef struct envrionnement_s
{
    char **env;
}env_t;

/* LIB */
void my_putchar(char c);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src, char c);
int my_intlen(int nb);
char *int_to_str(int nb);
char *my_revstr(char *str);
char *my_strcat2(char *dest, char const *src);
char *my_strdup (char const *src);
char **my_str_to_word_array(char *str, char *separator);
int my_strncmp(char const *s1, char const *s2, int n);
char *clean_str(char *str);
/* ENVIRONNEMENT */
char *my_getenv(char **env, char *str);
void my_env(char **env);
char **my_setenv(char *var, char *value, char **env);
int is_existing(char *var, char **env);
char **my_unsetenv(char *var, char **env);
/*COMMANDS*/
char *entry_command(void);
int check_commands(char **tab, env_t *ev);
void execute(char *path, char **env);
char **cd(char *path, char **env);

#endif /* !MINISHELL_H_ */
