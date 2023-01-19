/*
** EPITECH PROJECT, 2023
** antman
** File description:
** print_crypted_char
*/
#include "../include/my.h"
void print_crypted_char(char *cryption)
{
    char buf;
    int pr = 7;
    for (int n = 0; cryption[n] != '\0'; n++) {
        if (pr == -1) {
            my_putchar(buf);
            pr = 7;
        }
        if (cryption[n] == '0') {
            buf = buf & ~(1 << pr);
        } else {
            buf = buf | (1 << pr);
        }
        pr--;
    }
    my_putchar(buf);
}
