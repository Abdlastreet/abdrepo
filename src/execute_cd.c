/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** execute_cd
*/
#include "../include/my.h"
int execute_cd(char **w_arr, env_t *env)
{
    if (str_compare(w_arr[0], "cd") == -1)
        return 0;
    if (cd_error_handling(w_arr, env) != -1)
        return 1;
    if (find_env_var("PWD", env) == NULL)
        regenerate_pwd(env);
    execute_home_return(w_arr, env);
    execute_back_return(w_arr, env);
    execute_chdir(w_arr, env);
    return 0;
}

void execute_home_return(char **w_arr, env_t *env)
{
    int argc = nb_words(w_arr);
    env_line_t *path;

    if (argc != 1 && str_compare(w_arr[1], "~") != 0) {
        return;
    }
    env->cd = 1;
    update_lastpwd(env);
    chdir(env->home);
    update_pwd(env);
}

void execute_back_return(char **w_arr, env_t *env)
{
    int len = 0;
    char *lastpwdcp;
    int argc = nb_words(w_arr);

    if (argc == 1 || str_compare(w_arr[1], "-") != 0) {
        return;
    }
    len = my_strlen(env->lastpwd);
    lastpwdcp = malloc(sizeof(char) * (len + 1));
    lastpwdcp[len] = '\0';
    my_str_copy(lastpwdcp, env->lastpwd, 0);
    update_lastpwd(env);
    chdir(lastpwdcp);
    update_pwd(env);
    free(lastpwdcp);
}

void execute_chdir(char **w_arr, env_t *env)
{
    int argc = nb_words(w_arr);

    if (argc == 1) {
        return;
    }
    if (str_compare(w_arr[1], "~") == 0 || str_compare(w_arr[1], "-") == 0) {
        return;
    }
    env->cd = 1;
    update_lastpwd(env);
    chdir(w_arr[1]);
    update_pwd(env);
}
