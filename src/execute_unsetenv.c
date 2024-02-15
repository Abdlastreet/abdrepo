/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** execute_unsetenv
*/
#include "../include/my.h"
int execute_unsetenv(char **w_arr, env_t *env)
{
    int n = 1;
    int argc = nb_words(w_arr);
    int rtn = unsetenv_error_handling(w_arr);
    env_line_t *line;

    if (rtn != -1) {
        return rtn;
    }
    while (n < argc) {
        line = find_env_var(w_arr[n], env);
        if (line == NULL) {
        } else {
            remove_env_line(env, line);
        }
        n++;
    }
    create_env_from_lk(env);
    return 0;
}

int unsetenv_error_handling(char **w_arr)
{
    int argc = nb_words(w_arr);

    if (str_compare(w_arr[0], "unsetenv") == -1) {
        return 0;
    }
    if (argc == 1) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return 1;
    }
    return -1;

}
