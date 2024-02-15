/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** remodify_var
*/
#include "../include/my.h"
void update_pwd(env_t *env)
{
    char **pwd;
    env_line_t *line;

    pwd = malloc(sizeof(char *) * 4);
    pwd[3] = NULL;
    pwd[0] = malloc(sizeof(char) * 1);
    pwd[0][0] = '\0';
    pwd[1] = malloc(sizeof(char) * 4);
    pwd[1][3] = '\0';
    my_str_copy(pwd[1], "PWD", 0);
    pwd[2] = getcwd(NULL, 0);
    line = find_env_var("PWD", env);
    modify_env_var(line, env, pwd);
    free_arr(pwd);
    create_env_from_lk(env);
}

void update_path(env_t *env, env_line_t *path)
{
    int len = 0;

    if (path->sepline[1] == NULL) {
        free(env->path);
        env->path = malloc(sizeof(char) * 1);
        env->path[0] = '\0';
        return;
    }
    len = my_strlen(path->sepline[1]);
    free(env->path);
    env->path = malloc(sizeof(char) * (len + 1));
    env->path[len] = '\0';
    my_str_copy(env->path, path->sepline[1], 0);
}

void update_lastpwd(env_t *env)
{
    free(env->lastpwd);
    env->lastpwd = getcwd(NULL, 0);
}

void update_home(env_t *env, env_line_t *home)
{
    int len = 0;

    if (home->sepline[1] == NULL) {
        free(env->path);
        env->home = malloc(sizeof(char) * 1);
        env->home[0] = '\0';
        return;
    }
    len = my_strlen(home->sepline[1]);
    free(env->home);
    env->home = malloc(sizeof(char) * (len + 1));
    env->home[len] = '\0';
    my_str_copy(env->home, home->sepline[1], 0);
}

void check_update(env_t *env, env_line_t *current)
{
    if (str_compare(current->sepline[0], "PATH") == 0) {
        update_path(env, current);
    }
    if (str_compare(current->sepline[0], "HOME") == 0) {
        update_home(env, current);
    }
}
