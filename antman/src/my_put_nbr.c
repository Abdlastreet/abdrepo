/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** prints an int
*/
#include "../include/my.h"
int printing2(int nb, int k, int l)
{
    int nbc = 0;
    while (k != 0) {
        my_putchar(48);
        nbc = nbc + 1;
        k = k - 1;
    }
    if (nb < 0) {
        nb = nb * - 1;
    }
    if (nb > 2147483641) {
        my_putchar(l + 48);
        nbc = nbc + 1;
    }
    return (nbc);
}

int printing(int nb, int dest)
{
    int nbc = 0;
    if (nb < 0) {
        my_putchar(45);
        nbc = nbc + 1;
    }
    if (nb == 0) {
        my_putchar(48);
        nbc = nbc + 1;
    }
    while (dest > 0) {
        my_putchar((dest % 10) + 48);
        nbc = nbc + 1;
        dest = dest / 10;
    }
    return (nbc);
}

int my_put_nbr(int nb)
{
    int num = nb;
    int dest = 0;
    int k = 0;
    int l; int nbc;
    if (nb < 0)
        num = num * -1;
    if (num > 2147483641) {
        l = num % 10;
        num = num / 10;
    }
    while (num != 0) {
        dest = ((dest * 10) + num % 10);
        if (dest == 0)
            k = k + 1;
        num = num / 10;
    }
    nbc = printing(nb, dest);
    nbc = nbc + printing2(nb, k, l);
    return (nbc);
}
