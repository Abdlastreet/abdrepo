/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/
#include <fcntl.h>
#ifndef MY_H_
    #define MY_H_
    #include "list_letter_recu_t.h"
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>
char *file_reader(char const *filepath);
l_recu_t create_char_recu_list(void);
int compare_char_recu(l_recu_t *list, char c);
void assign_char_recu(l_recu_t *list, recu_t *letter);
void assign_char_recu2(l_recu_t *list, recu_t *letter);
recu_t *create_char_recu(char c);
l_recu_t char_recu(char *file);
recu_t *smallest_char_recu(l_recu_t *list);
int remove_char_recu(l_recu_t *list, recu_t *letter);
void create_new_internal_node(l_recu_t *list);
void create_hufmann_tree(l_recu_t *list);
void store_code(l_recu_t *list);
int find_code_lengh(recu_t *letter);
void find_code(recu_t *letter, int cdlen);
void print_hufmann_tree(l_recu_t *list);
void my_putstr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_strlen(char const *str);
char *store_cryption(char *file, l_recu_t *list);
int find_crypt_len(char *file, l_recu_t *list);
recu_t *find_letter(l_recu_t *list, char c);
int my_strcopy(char *dest, char *str, int st);
void print_crypted_char(char *cryption);
#endif /* !MY_H_ */
