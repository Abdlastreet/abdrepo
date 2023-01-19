/*
** EPITECH PROJECT, 2022
** nbrlen
** File description:
** len of number
*/
#include <stdio.h>
int nbrlen(int nbr)
{
    int len = 0;
    if (nbr == 0) {
        return 1;
    }
    while (nbr != 0) {
        nbr = nbr / 10;
        len++;
    }
    return len;
}
