/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** setenv_error_handling
*/
#include "../include/my.h"
int setenv_error_handling(char **w_arr, env_t *env)
{
    int argc = nb_words(w_arr);

    if (str_compare(w_arr[0], "setenv") == -1) {
        return 0;
    }
    if (argc == 1) {
        for (int n = 0; env->myenv[n] != NULL; n++) {
            my_putstr(env->myenv[n]);
            my_putchar('\n');
        }
        return 0;
    }
    if (argc > 3) {
        write(2, "setenv: Too many arguments.\n", 28);
        return 1;
    }
    return alphanum_setenv_error_handling(w_arr);
}

int alphanum_setenv_error_handling(char **w_arr)
{
    char p;

    p = w_arr[1][0];
    if ((p < 65 || p > 90) && (p < 97 || p > 122)) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return 1;
    }
    if (check_alphanum(w_arr[1]) == -1) {
        write(2, "setenv: Variable name must contain", 34);
        write(2, " alphanumeric characters.\n", 26);
        return 1;
    }
    return -1;
}

int check_alphanum(char *str)
{
    int n = 0;
    char p;

    while (str[n] != '\0') {
        p = str[n];
        if ((p < 65 || p > 90) && (p < 97 || p > 122) && (p < 48 || p > 57)
        && (p != 46)) {
            return -1;
        }
        n++;
    }
    return 0;
}
