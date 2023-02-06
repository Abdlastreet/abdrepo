/*
** EPITECH PROJECT, 2022
** p_finder
** File description:
** finds first P coordinates
*/
#include "../include/my.h"
int p_finder(char **map, coordinates_t *coop)
{
    int r = 0;
    int c = 0;
    while (map[r] != NULL) {
        while (map[r][c] != '\0' && map[r][c] != 'P') {
            c++;
        }
        if (map[r][c] == 'P') {
            coop->r = r;
            coop->c = c;
            return 0;
        }
        c = 0;
        r++;
    }
    return 0;
}
