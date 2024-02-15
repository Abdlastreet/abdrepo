/*
** EPITECH PROJECT, 2023
** bsminishell1
** File description:
** free_str
*/
#include "../include/my.h"
void free_arr(char **arr)
{
    int n = 0;

    while (arr[n] != NULL) {
        free(arr[n]);
        n++;
    }
    free(arr);
}
