/*
** EPITECH PROJECT, 2022
** storage coordinates
** File description:
** find storages coordinates and put in in structures
*/
#include "../include/my.h"
int storage_counter(char *line)
{
    int c = 0;
    int stnb = 0;
    while (line[c] != '\0') {
        if (line[c] == 'O') {
            stnb++;
        }
        c++;
    }
    return stnb;
}

void storage_coo_save(char *line, storage_list_t *strlist, int r)
{
    int c = 0;
    while (line[c] != '\0') {
        if (line[c] == 'O') {
        strlist->storage_list[strlist->nbstorage].r = r;
        strlist->storage_list[strlist->nbstorage].c = c;
        strlist->storage_list[strlist->nbstorage].state = 0;
        strlist->nbstorage++;
        }
        c++;
    }
}

storage_list_t storage_coo_finder(char **map)
{
    storage_list_t strlist;
    int r = 0;
    int nbs = 0;
    strlist.nbstorage = 0;
    while (map[r] != NULL) {
        nbs += storage_counter(map[r]);
        r++;
    }
    r = 0;
    strlist.storage_list = malloc(sizeof(storage_t) * nbs);
    while (map[r] != NULL) {
        storage_coo_save(map[r], &strlist, r);
        r++;
    }
    return strlist;
}
