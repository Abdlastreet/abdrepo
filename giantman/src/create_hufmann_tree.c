/*
** EPITECH PROJECT, 2023
** antman
** File description:
** create_hufmann_tree
*/
#include "../include/my.h"
void create_hufmann_tree(l_recu_t *list)
{
    recu_t *newnode;
    for (int n = 0; list->nbletters > 1; n++) {
        create_new_internal_node(list);
    }
    list->begin->isnode = 2;
    list->begin->branch = 2;
}

void create_new_internal_node(l_recu_t *list)
{
    recu_t *newnode = malloc(sizeof(recu_t));
    recu_t *smallest = smallest_char_recu(list);
    newnode->isnode = 1;
    newnode->letter = 'N';
    smallest->branch = '0';
    smallest->back = newnode;
    newnode->recu = smallest->recu;
    newnode->zero = smallest;
    remove_char_recu(list, smallest);
    smallest = smallest_char_recu(list);
    smallest->branch = '1';
    smallest->back = newnode;
    newnode->recu += smallest->recu;
    newnode->one = smallest;
    remove_char_recu(list, smallest);
    assign_char_recu(list, newnode);
}
