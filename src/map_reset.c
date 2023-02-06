/*
** EPITECH PROJECT, 2022
** map_reset
** File description:
** reset_map using map copie
*/
#include "../include/my.h"
void map_reset(char **map, char **cmap, coordinates_t *coop)
{
    int r = 0;
    int c = 0;
    while (map[r] != NULL) {
        while (map[r][c] != '\0') {
            map[r][c] = cmap[r][c];
            c++;
        }
        c = 0;
        r++;
    }
    p_finder(map, coop);
}
