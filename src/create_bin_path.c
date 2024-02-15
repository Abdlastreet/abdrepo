/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** create_bin_path
*/
#include "../include/my.h"
void create_bin_path(char **bina, char *path)
{
    int j = 0;
    int lenb = my_strlen(*bina);
    int lenph = my_strlen(path);
    char *n_path = malloc(sizeof(char) * (lenb + lenph + 1));

    j += my_str_copy(n_path, path, j);
    j += my_str_copy(n_path, *bina, j);
    n_path[lenb + lenph] = '\0';
    free(*bina);
    *bina = malloc(sizeof(char) * (lenb + lenph + 1));
    my_str_copy(*bina, n_path, 0);
    (*bina)[lenb + lenph] = '\0';
    free(n_path);
    free(path);
}

int my_str_copy(char *dest, char *str, int i)
{
    int j = 0;

    while (str[j] != '\0') {
        dest[i] = str[j];
        i++;
        j++;
    }
    return j;
}
