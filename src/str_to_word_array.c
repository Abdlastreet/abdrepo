/*
** EPITECH PROJECT, 2023
** str_to_word_array
** File description:
** strtowordarray
*/
#include "../include/my.h"
char **malloc_array(char *str, char *sep)
{
    int n = 0;
    int nbw = 0;
    char **arr;

    while (str[n] != '\0') {
        if (comp_sep(str[n], sep) == -1 && comp_sep(str[n + 1], sep) == 0) {
            nbw++;
        }
        n++;
    }
    arr = malloc(sizeof(char *) * (nbw + 1));
    arr[nbw] = NULL;
    return arr;
}

void malloc_lines(char *str, char **arr, char *sep)
{
    int n = 0;
    int i = 0;
    int wlen = 0;

    while (str[n] != '\0') {
        if (comp_sep(str[n], sep) == -1) {
            wlen++;
        }
        if (comp_sep(str[n], sep) == -1 && comp_sep(str[n + 1], sep) == 0) {
            arr[i] = malloc(sizeof(char) * (wlen + 1));
            wlen = 0;
            i++;
        }
        n++;
    }
}

void fill_lines(char *str, char **arr, char *sep)
{
    int n = 0;
    int i = 0;
    int j = 0;

    while (str[n] != '\0') {
        if (comp_sep(str[n], sep) == -1) {
            arr[i][j] = str[n];
            j++;
        }
        if (comp_sep(str[n], sep) == -1 && comp_sep(str[n + 1], sep) == 0) {
            arr[i][j] = '\0';
            i++;
            j = 0;
        }
        n++;
    }
}

int comp_sep(char c, char *sep)
{
    int n = 0;
    int len = my_strlen(sep) + 1;

    while (n < len) {
        if (sep[n] == c) {
            return 0;
        }
        n++;
    }
    return -1;
}

char **str_to_word_array(char *str, char *sep)
{
    char **arr = malloc_array(str, sep);

    malloc_lines(str, arr, sep);
    fill_lines(str, arr, sep);
    return arr;
}
