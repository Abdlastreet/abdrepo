/*
** EPITECH PROJECT, 2022
** longest line
** File description:
** finds longest line size
*/
#include "../include/my.h"
int longest_line(char **map)
{
    int r = 0;
    int len = 0;
    while (map[r] != NULL) {
        if (my_strlen(map[r]) > len) {
            len = my_strlen(map[r]);
        }
        r++;
    }
    return len;
}
