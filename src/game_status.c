/*
** EPITECH PROJECT, 2022
** game win or loose
** File description:
** return 2 if no win or loose
** return 0 if win, return 1 if loose
*/
#include "../include/my.h"
int game_status(char **map, storage_list_t *strlist)
{
    if (win_cheker(map, strlist) == 1) {
        return 1;
    }
    if (lose_cheker(map) == 1) {
        return 2;
    }
    return 0;
}

int win_cheker(char **map, storage_list_t *strlist)
{
    int n = 0;
    while (n != strlist->nbstorage) {
        if (strlist->storage_list[n].state != 1) {
            return 0;
        }
        n++;
    }
    return 1;
}

int lose_cheker(char **map)
{
    storage_list_t xlist = x_coo_finder(map);
    int n = 0;
    int r;
    int c;
    while (n != xlist.nbstorage) {
        r = xlist.storage_list[n].r;
        c = xlist.storage_list[n].c;
        if (x_cheker(map, r, c) == 0) {
            free(xlist.storage_list);
            return 0;
        }
        n++;
    }
    free(xlist.storage_list);
    return 1;
}

int x_cheker(char **map, int r, int c)
{
    if (map[r - 1][c] == '#' && map[r][c + 1] == '#') {
        return 1;
    }
    if (map[r][c + 1] == '#' && map[r + 1][c] == '#') {
        return 1;
    }
    if (map[r + 1][c] == '#' && map[r][c - 1] == '#') {
        return 1;
    }
    if (map[r][c - 1] == '#' && map[r - 1][c] == '#') {
        return 1;
    }
    return 0;
}
