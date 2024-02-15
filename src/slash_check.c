/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** slash_check
*/
#include "../include/my.h"
int slash_check(char *line)
{
    for (int n = 0; line[n] != '\0'; n++) {
        if (line[n] == '/') {
            return 0;
        }
    }
    return -1;
}
