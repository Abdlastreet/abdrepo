/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** execute_env
*/
#include "../include/my.h"
int execute_env(char **w_arr, env_t *env)
{
    int n = 0;

    if (str_compare(w_arr[0], "env") == -1) {
        return 0;
    }
    if (nb_words(w_arr) > 1) {
        write(2, "env: Too many arguments.\n", 25);
        return 1;
    }
    while (env->myenv[n] != NULL) {
        my_putstr(env->myenv[n]);
        my_putchar('\n');
        n++;
    }
    return 0;
}
