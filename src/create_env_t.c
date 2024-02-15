/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** create_env_t
*/
#include "../include/my.h"
env_t create_env_t(char **env)
{
    env_t stenv;

    stenv.rtn = 0;
    stenv.cd = 0;
    stenv.nblines = 0;
    stenv.begin = NULL;
    stenv.end = NULL;
    stenv.env = env;
    stenv.home = malloc(sizeof(char) * 1);
    stenv.home[0] = '\0';
    stenv.lastpwd = malloc(sizeof(char) * 1);
    stenv.lastpwd[0] = '\0';
    stenv.path = malloc(sizeof(char) * 14);
    my_str_copy(stenv.path, "/usr/bin:/bin", 0);
    stenv.path[13] = '\0';
    stenv.myenv = copy_env(env);
    fill_env(&stenv);
    create_env_from_lk(&stenv);
    return stenv;
}

void fill_env(env_t *env)
{
    env_line_t *envline;
    int n = 0;

    while (env->env[n] != NULL) {
        envline = create_env_line(env->env[n]);
        assign_line(env, envline);
        n++;
    }
}

env_line_t *create_env_line(char *line)
{
    int len = my_strlen(line);
    env_line_t *envline = malloc(sizeof(env_line_t));
    char *cpline = malloc(sizeof(char) * (len + 1));

    cpline[len] = '\0';
    my_str_copy(cpline, line, 0);
    envline->line = cpline;
    envline->sepline = str_to_word_array(line, "=");
    envline->next = NULL;
    return envline;
}
