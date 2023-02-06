/*
** EPITECH PROJECT, 2022
** o_map
** File description:
** rewrites O in map
*/
#include "../include/my.h"
void o_map(char **map, storage_list_t *strlist)
{
    int n = 0;
    int r;
    int c;
    while (n != strlist->nbstorage) {
        r = strlist->storage_list[n].r;
        c = strlist->storage_list[n].c;
        if (map[r][c] != 'X' && map[r][c] != 'P') {
            map[r][c] = 'O';
            strlist->storage_list[n].state = 0;
        }
        if (map[r][c] == 'X') {
            strlist->storage_list[n].state = 1;
        }
        if (map[r][c] == 'P') {
            strlist->storage_list[n].state = 2;
        }
        n++;
    }
}
