/*
** EPITECH PROJECT, 2023
** print cryption
** File description:
** prints cryption
*/
#include "../include/my.h"
char *store_cryption(char *file, l_recu_t *list)
{
    recu_t *current;
    int st = 0;
    int len = find_crypt_len(file, list);
    char *cryption = malloc(sizeof(char) * (len + 1));
    for (int n = 0; file[n] != '\0'; n++) {
        current = find_letter(list, file[n]);
        st = my_strcopy(cryption, current->code, st);
    }
    my_put_nbr(len);
    my_putchar(',');
    return cryption;
}

int find_crypt_len(char *file, l_recu_t *list)
{
    int len = 0;
    recu_t *current;
    for (int n = 0; file[n] != '\0'; n++) {
        current = find_letter(list, file[n]);
        len += current->codelen;
    }
    return len;
}

recu_t *find_letter(l_recu_t *list, char c)
{
    recu_t *current = list->begin2;
    while (current->letter != c) {
        current = current->next2;
    }
    return current;
}
