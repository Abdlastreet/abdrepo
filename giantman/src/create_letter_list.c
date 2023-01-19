/*
** EPITECH PROJECT, 2023
** giantman
** File description:
** create_tree
*/
#include "../include/my.h"
l_recu_t create_letter_list(char *data)
{
    int n;
    recu_t *new;
    l_recu_t list = create_char_recu_list();
    list.bits = my_getnbr(data, 0);
    n = nbrlen(list.bits) + 1;
    while (data[n] != '\n' || data[n + 1] != '\n') {
        new = create_char_recu(data[n]);
        n++;
        new->recu = my_getnbr(data, n);
        n += nbrlen(new->recu) + 1;
        assign_char_recu(&list, new);
    }
    free(data);
    return list;
}
