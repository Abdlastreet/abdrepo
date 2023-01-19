/*
** EPITECH PROJECT, 2023
** main of mockup
** File description:
** main
*/
#include "../include/my.h"
int main(int argc, char **argv)
{
    char *cryption;
    char *file = file_reader(argv[1]);
    l_recu_t list = char_recu(file);
    /*recu_t *current = list.begin;
    for (int n = 0; n < list.nbletters; n++) {
        printf("La lettre %c est presente %d fois\n", current->letter, current->recu);
        current = current->next;
    }*/
    create_hufmann_tree(&list);
    store_code(&list);
    cryption = store_cryption(file, &list);
    print_hufmann_tree(&list);
    print_crypted_char(cryption);
    return 0;
}
