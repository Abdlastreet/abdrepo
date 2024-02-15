/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** find_add_remove_var
*/
#include "../include/my.h"
void assign_line(env_t *env, env_line_t *envline)
{
    if (env->nblines == 0) {
        env->begin = envline;
        env->end = envline;
    } else {
        env->end->next = envline;
        env->end = envline;
    }
    env->nblines++;
}

env_line_t *find_env_var(char *var, env_t *env)
{
    int n = 0;
    env_line_t *current = env->begin;

    while (n < env->nblines) {
        if (str_compare(var, current->sepline[0]) != -1) {
            return current;
        }
        current = current->next;
        n++;
    }
    return NULL;
}
