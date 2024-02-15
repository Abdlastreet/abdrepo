/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_strcat
*/
#include "../include/my.h"
char *my_strcat(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    char *dest = malloc(sizeof(char) * (len1 + len2 + 1));

    dest[len1 + len2] = '\0';
    my_str_copy(dest, str1, 0);
    my_str_copy(dest, str2, len1);
    return dest;
}
