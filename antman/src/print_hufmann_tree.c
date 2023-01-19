/*
** EPITECH PROJECT, 2023
** antman
** File description:
** print_hufmann_tree
*/
#include "../include/my.h"
void print_hufmann_tree(l_recu_t *list)
{
    recu_t *current = list->begin2;
    for (int n = 0; n < list->nbletters2; n++) {
        my_putchar(current->letter);
        my_put_nbr(current->recu);
        my_putchar(',');
        current = current->next2;
    }
}
