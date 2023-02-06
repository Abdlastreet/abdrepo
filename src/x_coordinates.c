/*
** EPITECH PROJECT, 2022
** storage coordinates
** File description:
** find x coordinates and put in in structures
*/
#include "../include/my.h"
int x_counter(char *line)
{
    int c = 0;
    int stnb = 0;
    while (line[c] != '\0') {
        if (line[c] == 'X') {
            stnb++;
        }
        c++;
    }
    return stnb;
}

void x_coo_save(char *line, storage_list_t *xlist, int r)
{
    int c = 0;
    while (line[c] != '\0') {
        if (line[c] == 'X') {
        xlist->storage_list[xlist->nbstorage].r = r;
        xlist->storage_list[xlist->nbstorage].c = c;
        xlist->storage_list[xlist->nbstorage].state = 0;
        xlist->nbstorage++;
        }
        c++;
    }
}

storage_list_t x_coo_finder(char **map)
{
    storage_list_t xlist;
    int r = 0;
    int nbs = 0;
    xlist.nbstorage = 0;
    while (map[r] != NULL) {
        nbs += x_counter(map[r]);
        r++;
    }
    r = 0;
    xlist.storage_list = malloc(sizeof(storage_t) * nbs);
    while (map[r] != NULL) {
        x_coo_save(map[r], &xlist, r);
        r++;
    }
    return xlist;
}
