/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** controled_command
*/
#include "../include/my.h"
void execute_exit(char **w_arr, char *line, env_t *env)
{
    int rtn = env->rtn;

    if (str_compare(w_arr[0], "exit") != 0) {
        return;
    }
    free_env(env);
    free_arr(w_arr);
    free(line);
    exit(rtn);
}
