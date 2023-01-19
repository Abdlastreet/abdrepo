/*
** EPITECH PROJECT, 2023
** antman
** File description:
** list_letter_recu_t
*/

#ifndef LIST_LETTER_RECU_T_H_
    #define LIST_LETTER_RECU_T_H_
    #include "my.h"
    #include "letter_recu_t.h"
typedef struct l_recu_s {
    recu_t *begin;
    recu_t *end;
    recu_t *begin2;
    recu_t *end2;
    int nbletters;
    int nbletters2;
    int bits;
} l_recu_t;

#endif /* !LIST_LETTER_RECU_T_H_ */
