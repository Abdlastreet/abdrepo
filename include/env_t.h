/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** env_t
*/

#ifndef ENV_T_H_
    #define ENV_T_H_
    #include "my.h"
    #include "env_line_t.h"
typedef struct env_s {
    int rtn;
    char **env;
    char **myenv;
    char *lastpwd;
    char *home;
    char *path;
    int cd;
    env_line_t *begin;
    env_line_t *end;
    int nblines;
} env_t;
#endif /* !ENV_T_H_ */
