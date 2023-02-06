/*
** EPITECH PROJECT, 2022
** row_calculator
** File description:
** calculates rows of map
*/
#include "../include/my.h"
int row_calculator(char **map)
{
    int n = 0;
    while (map[n] != NULL) {
        n++;
    }
    return n;
}
