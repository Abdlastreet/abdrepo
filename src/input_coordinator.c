/*
** EPITECH PROJECT, 2022
** input coordinator
** File description:
** coordinates input
*/
#include "../include/my.h"
void input_coordinator(char **map, char **cmap, char inpt, coordinates_t *coop)
{
    if (inpt == 65)
        up_update(map, coop);
    if (inpt == 66)
        down_update(map, coop);
    if (inpt == 67)
        right_update(map, coop);
    if (inpt == 68)
        left_update(map, coop);
    if (inpt == 32)
        map_reset(map, cmap, coop);
}
