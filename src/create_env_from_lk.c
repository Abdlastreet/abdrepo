/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** create_env_from_lk
*/
#include "../include/my.h"
void create_env_from_lk(env_t *lkenv)
{
    env_line_t *current = lkenv->begin;
    int n = 0;
    int len = 0;

    free_arr(lkenv->myenv);
    lkenv->myenv = malloc(sizeof(char *) * (lkenv->nblines + 1));
    lkenv->myenv[lkenv->nblines] = NULL;
    while (n < lkenv->nblines) {
        check_update(lkenv, current);
        len = my_strlen(current->line);
        lkenv->myenv[n] = malloc(sizeof(char) * (len + 1));
        lkenv->myenv[n][len] = '\0';
        my_str_copy(lkenv->myenv[n], current->line, 0);
        current = current->next;
        n++;
    }
}
