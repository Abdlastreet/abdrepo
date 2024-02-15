/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** execute_controle_d
*/
#include "../include/my.h"
void execute_controle_d(ssize_t size, char *line, env_t *env)
{
    int rtn = env->rtn;

    if (size != -1) {
        return;
    }
    free_env(env);
    free(line);
    exit(rtn);
}
