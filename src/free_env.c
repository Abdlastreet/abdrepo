/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** free_env
*/
#include "../include/my.h"
void free_env(env_t *env)
{
    int n = 0;
    env_line_t *current = env->begin;
    env_line_t *next;

    free_arr(env->myenv);
    free(env->home);
    free(env->lastpwd);
    free(env->path);
    while (n < env->nblines) {
        next = current->next;
        free_var(current);
        current = next;
        n++;
    }
}

void free_var(env_line_t *var)
{
    free(var->line);
    free_arr(var->sepline);
    free(var);
}
