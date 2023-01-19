/*
** EPITECH PROJECT, 2023
** antman
** File description:
** my_strcopy
*/
#include "../include/my.h"
int my_strcopy(char *dest, char *str, int st)
{
    int n = 0;
    while (str[n] != '\0') {
        dest[st] = str[n];
        st++;
        n++;
    }
    return st;
}
