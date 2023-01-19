/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** displays, one-by-one, the characters of a string
*/
#include "../include/my.h"
void my_putstr(char const *str)
{
    int len = my_strlen(str);
    write(1, str, len);
}
