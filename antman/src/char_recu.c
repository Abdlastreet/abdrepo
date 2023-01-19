/*
** EPITECH PROJECT, 2023
** char recu
** File description:
** letter recurence
*/
#include "../include/my.h"
l_recu_t char_recu(char *file)
{
    l_recu_t list = create_char_recu_list();
    for (int n = 0; file[n] != '\0'; n++) {
        compare_char_recu(&list, file[n]);
    }
    return list;
}
