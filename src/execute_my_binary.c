/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** execute_my_binary
*/
#include "../include/my.h"
int execute_my_binary(char **w_arr, env_t *env)
{
    int rtn = 0;

    if (slash_check(w_arr[0]) == -1) {
        return 0;
    }
    if (my_binary_error_handling(w_arr[0]) == 1) {
        return 1;
    }
    rtn = execute_binary(w_arr, env);
    return rtn;
}

int my_binary_error_handling(char *comd)
{
    struct stat statbuf;

    if (access(comd, F_OK) == -1) {
        write(2, comd, my_strlen(comd));
        write(2, ": Command not found.\n", 21);
        return 1;
    }
    stat(comd, &statbuf);
    if (access(comd, X_OK) == -1 || S_ISDIR(statbuf.st_mode)) {
        write(2, comd, my_strlen(comd));
        write(2, ": Permission denied.\n", 21);
        return 1;
    }
    return 0;
}
