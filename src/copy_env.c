/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** copy_env
*/
#include "../include/my.h"
char **copy_env(char **env)
{
    int n = 0;
    int len = nb_words(env);
    char **new_env = malloc(sizeof(char *) * (len + 1));

    new_env[len] = NULL;
    while (env[n] != NULL) {
        len = my_strlen(env[n]);
        new_env[n] = malloc(sizeof(char) * (len + 1));
        new_env[n][len] = '\0';
        my_str_copy(new_env[n], env[n], 0);
        n++;
    }
    return new_env;
}
