/*
** EPITECH PROJECT, 2022
** update map
** File description:
** update map
*/
#include "../include/my.h"
char **up_update(char **map, coordinates_t *coop)
{
    int r = coop->r - 1;
    int c = coop->c;
    while (map[r][c] == 'X') {
        r--;
    }
    if (map[r][c] == '#') {
        return map;
    }
    while (r != coop->r) {
        map[r][c] = map[r + 1][c];
        r++;
    }
    map[r][c] = ' ';
    coop->r--;
    return map;
}

char **down_update(char **map, coordinates_t *coop)
{
    int r = coop->r + 1;
    int c = coop->c;
    while (map[r][c] == 'X') {
        r++;
    }
    if (map[r][c] == '#') {
        return map;
    }
    while (r != coop->r) {
        map[r][c] = map[r - 1][c];
        r--;
    }
    map[r][c] = ' ';
    coop->r++;
    return map;
}

char **right_update(char **map, coordinates_t *coop)
{
    int r = coop->r;
    int c = coop->c + 1;
    while (map[r][c] == 'X') {
        c++;
    }
    if (map[r][c] == '#') {
        return map;
    }
    while (c != coop->c) {
        map[r][c] = map[r][c - 1];
        c--;
    }
    map[r][c] = ' ';
    coop->c++;
    return map;
}

char **left_update(char **map, coordinates_t *coop)
{
    int r = coop->r;
    int c = coop->c - 1;
    while (map[r][c] == 'X') {
        c--;
    }
    if (map[r][c] == '#') {
        return map;
    }
    while (c != coop->c) {
        map[r][c] = map[r][c + 1];
        c++;
    }
    map[r][c] = ' ';
    coop->c--;
    return map;
}
