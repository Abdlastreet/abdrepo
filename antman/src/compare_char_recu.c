/*
** EPITECH PROJECT, 2023
** antman
** File description:
** compare_char_recu
*/
#include "../include/my.h"
int compare_char_recu(l_recu_t *list, char c)
{
    recu_t *current;
    if (list->nbletters == 0) {
    } else {
        current = list->begin;
    }
    for (int n = 0; n < list->nbletters; n++) {
        if (current->letter == c) {
            current->recu++;
            return 1;
        }
        current = current->next;
    }
    current = create_char_recu(c);
    assign_char_recu(list, current);
    assign_char_recu2(list, current);
    return 0;
}
