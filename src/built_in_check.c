/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** built_in_check
*/
#include "../include/my.h"
int built_in_check(char *bin)
{
    if (str_compare(bin, "cd") == 0) {
        return 0;
    }
    if (str_compare(bin, "setenv") == 0) {
        return 0;
    }
    if (str_compare(bin, "unsetenv") == 0) {
        return 0;
    }
    if (str_compare(bin, "env") == 0) {
        return 0 ;
    }
    return -1;
}
