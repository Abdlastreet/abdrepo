/*
** EPITECH PROJECT, 2023
** giantman
** File description:
** decrypt_file
*/
#include "../include/my.h"
void decrypt_file(l_recu_t *list, char *cryption)
{
    int ch = 0;
    int bts = 7;
    recu_t *current = list->begin;
    for (int n = 0; n < list->bits; n++) {
        if (bts == -1) {
            bts = 7;
            ch++;
        }
        if (cryption[ch] & (1 << bts)) {
            current = current->one;
        } else {
            current = current->zero;
        }
        if (current->isnode == 0) {
            printf("%c", current->letter);
            current = list->begin;
        }
        bts--;
    }
}
