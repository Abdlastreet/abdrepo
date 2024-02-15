/*
** EPITECH PROJECT, 2023
** bsminishell1
** File description:
** nb_str
*/
#include "../include/my.h"
int nb_words(char **arr)
{
    int n = 0;

    while (arr[n] != NULL) {
        n++;
    }
    return n;
}
