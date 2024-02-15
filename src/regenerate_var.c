/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** regenerate_var
*/
#include "../include/my.h"
void regenerate_pwd(env_t *env)
{
    char **pwd;

    pwd = malloc(sizeof(char *) * 4);
    pwd[3] = NULL;
    pwd[0] = malloc(sizeof(char) * 1);
    pwd[0][0] = '\0';
    pwd[1] = malloc(sizeof(char) * 4);
    pwd[1][3] = '\0';
    my_str_copy(pwd[1], "PWD", 0);
    pwd[2] = getcwd(NULL, 0);
    create_new_var(env, pwd);
    free_arr(pwd);
    create_env_from_lk(env);
}
