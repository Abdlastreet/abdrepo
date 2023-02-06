/*
** EPITECH PROJECT, 2022
** display_message
** File description:
** displays message
*/
#include "../include/my.h"
void display_message(WINDOW *win, int rp, int lenml)
{
    while (LINES < rp || COLS < lenml) {
        wclear(win);
        mvwprintw(win, LINES / 2, COLS / 2 - 6, "%s", "small window");
        wrefresh(win);
        wgetch(win);
    }
}
