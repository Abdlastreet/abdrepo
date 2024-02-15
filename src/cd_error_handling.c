/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** cd_error_handling
*/
#include "../include/my.h"
int cd_error_handling(char **w_arr, env_t *env)
{
    int argc = nb_words(w_arr);

    if (argc > 2) {
        write(2, "cd: Too many arguments.\n", 24);
        return 1;
    }
    if (argc == 1) {
        return -1;
    }
    if (str_compare(w_arr[1], "-") == 0 && env->cd == 0) {
        write(2, ": No such file or directory.\n", 29);
        return 1;
    }
    if (str_compare(w_arr[1], "~") == 0 || str_compare(w_arr[1], "-") == 0) {
        return -1;
    }
    return cd_filetype_error_handling(w_arr);
}

int cd_filetype_error_handling(char **w_arr)
{
    struct stat statbuf;

    stat(w_arr[1], &statbuf);
    if (access(w_arr[1], F_OK) == -1) {
        write(2, w_arr[1], my_strlen(w_arr[1]));
        write(2, ": No such file or directory.\n", 29);
        return 1;
    }
    if (S_ISDIR(statbuf.st_mode) == 0) {
        write(2, w_arr[1], my_strlen(w_arr[1]));
        write(2, ": Not a directory.\n", 19);
        return 1;
    }
    return -1;
}
