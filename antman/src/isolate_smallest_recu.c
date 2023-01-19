/*
** EPITECH PROJECT, 2023
** antman
** File description:
** sort_list_char_recu
*/
#include "../include/my.h"
recu_t *smallest_char_recu(l_recu_t *list)
{
    recu_t *current = list->begin;
    recu_t *smallest = list->begin;
    for (int n = 0; n < list->nbletters; n++) {
        if (current->recu < smallest->recu) {
            smallest = current;
        }
        current = current->next;
    }
    return smallest;
}

int remove_char_recu(l_recu_t *list, recu_t *letter)
{
    recu_t *current = list->begin;
    recu_t *culast = list->begin;
    while (current != letter) {
        culast = current;
        current = current->next;
    }
    list->nbletters--;
    if (list->nbletters == 0) {
        list->begin = NULL;
        list->end = NULL;
        return 0;
    } if (current == list->begin) {
        list->begin = current->next;
        return 0;
    } if (current == list->end) {
        list->end = culast;
        return 0;
    }
    culast->next = current->next;
    return 0;
}
