/*
** EPITECH PROJECT, 2022
** display map
** File description:
** display map on terminal
*/
#include "../include/my.h"
void display_map(WINDOW *win, char **map, int rp, int cp)
{
    int n = 0;
    wclear(win);
    while (map[n] != NULL) {
        mvwprintw(win, (LINES - rp) / 2 + n, (COLS - cp) / 2, "%s", map[n]);
        n++;
    }
    wrefresh(win);
}
