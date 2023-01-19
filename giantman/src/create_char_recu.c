/*
** EPITECH PROJECT, 2023
** antman
** File description:
** create_char_recu
*/
#include "../include/my.h"
recu_t *create_char_recu(char c)
{
    recu_t *letter = malloc(sizeof(recu_t));
    letter->letter = c;
    letter->recu = 1;
    letter->isnode = 0;
    return letter;
}
