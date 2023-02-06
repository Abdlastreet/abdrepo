/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** lengh of string
*/
#include "../include/my.h"
int my_strlen(char *str)
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
