/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** remove_var
*/
#include "../include/my.h"
void remove_env_line(env_t *env, env_line_t *line)
{
    env_line_t *current = env->begin;
    env_line_t *culast = env->begin;

    while (current != line) {
        culast = current;
        current = current->next;
    }
    env->nblines--;
    if (env->nblines == 0) {
        remove_only_var(env, current);
        return;
    } if (current == env->begin) {
        remove_first_var(env, current);
        return;
    } if (current == env->end) {
        remove_last_var(env, current, culast);
        return;
    }
    culast->next = current->next;
    free_var(current);
}

void remove_only_var(env_t *env, env_line_t *current)
{
    env->begin = NULL;
    env->end = NULL;
    free_var(current);
}

void remove_first_var(env_t *env, env_line_t *current)
{
    env->begin = current->next;
    free_var(current);
}

void remove_last_var(env_t *env, env_line_t *current, env_line_t *culast)
{
    env->end = culast;
    free_var(current);
}
