/*
** EPITECH PROJECT, 2023
** antman
** File description:
** assign_char_recu
*/
#include "../include/my.h"
void assign_char_recu(l_recu_t *list, recu_t *letter)
{
    if (list->nbletters == 0) {
        list->begin = letter;
        list->end = letter;
    } else {
        list->end->next = letter;
        list->end = letter;
    }
    list->nbletters++;
}

void assign_char_recu2(l_recu_t *list, recu_t *letter)
{
    if (list->nbletters2 == 0) {
        list->begin2 = letter;
        list->end2 = letter;
    } else {
        list->end2->next2 = letter;
        list->end2 = letter;
    }
    list->nbletters2++;
}
