/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** command_interpreter
*/
#include "../include/my.h"
int command_interpreter(char *line, ssize_t size, env_t *env)
{
    int rtn = 0;
    char **w_arr;

    if (size == 1)
        return 0;
    execute_controle_d(size, line, env);
    w_arr = str_to_word_array(line, " \t\n");
    if (nb_words(w_arr) == 0) {
        free_arr(w_arr);
        return 0;
    }
    execute_exit(w_arr, line, env);
    rtn += execute_my_binary(w_arr, env);
    rtn += execute_bin_binary(w_arr, env);
    rtn += execute_cd(w_arr, env);
    rtn += execute_env(w_arr, env);
    rtn += execute_setenv(w_arr, env);
    rtn += execute_unsetenv(w_arr, env);
    free_arr(w_arr);
    return rtn;
}
