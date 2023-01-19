/*
** EPITECH PROJECT, 2023
** antman
** File description:
** store_code
*/
#include "../include/my.h"
void store_code(l_recu_t *list)
{
    int cdlen;
    recu_t *current = list->begin2;
    for (int n = 0; n < list->nbletters2; n++) {
        cdlen = find_code_lengh(current);
        current->codelen = cdlen;
        current->code = malloc(sizeof(char) * (cdlen + 1));
        find_code(current, cdlen);
        current = current->next2;
    }
}

int find_code_lengh(recu_t *letter)
{
    int cdlen = 0;
    recu_t *current = letter;
    while (current->isnode != 2) {
        current = current->back;
        cdlen++;
    }
    return cdlen;

}

void find_code(recu_t *letter, int cdlen)
{
    int cd;
    cdlen--;
    recu_t *current = letter;
    while (current->isnode != 2) {
        current->branch;
        letter->code[cdlen] = current->branch;
        current = current->back;
        cdlen--;
    }
}
