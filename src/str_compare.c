/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** str_compare
*/
#include "../include/my.h"
int str_compare(char const *str, char const *model)
{
    int n = 0;

    if (my_strlen(str) != my_strlen(model)) {
        return -1;
    }
    while (model[n] != '\0') {
        if (str[n] != model[n]) {
            return -1;
        }
        n++;
    }
    return 0;
}
