/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** string to int
*/
#include "../include/my.h"
int my_getnbr(char const *str, int n)
{
    int ng = 1;
    int nb = 0;
    while (str[n] != '\0') {
        if ((str[n] > 47 && str[n] < 58) &&
(nb == 214748364 && (str[n] < 55 || str[n] > 57)) || nb > 214748364) {
            return 0;
        }
        if ((str[n] > 47 && str[n] < 58) && str[n - 1] == '-' && ng == 1)
            ng = 1;
        if (str[n] > 47 && str[n] < 58)
            nb = (nb * 10) + (str[n] - 48);
        if ((str[n] < 48 || str[n] > 57) && str[n] != '-' && str[n] != '+')
            return (nb * ng);
        n++;
    }
    nb = nb * ng;
    return nb;
}
