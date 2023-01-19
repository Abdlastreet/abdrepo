/*
** EPITECH PROJECT, 2023
** antman
** File description:
** letter_recu_t
*/

#ifndef LETTER_RECU_T_H_
    #define LETTER_RECU_T_H_
typedef struct recu_s {
    char letter;
    int recu;
    int isnode;
    char branch;
    char *code;
    int codelen;
    struct recu_s *zero;
    struct recu_s *one;
    struct recu_s *back;
    struct recu_s *next;
    struct recu_s *next2;
} recu_t;
#endif /* !LETTER_RECU_T_H_ */
