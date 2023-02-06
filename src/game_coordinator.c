/*
** EPITECH PROJECT, 2022
** game_coordinator
** File description:
** coordinates input to display game output
*/
#include "../include/my.h"
int game_coordinator(char **map, char **cmap)
{
    coordinates_t coop;
    storage_list_t strlist = storage_coo_finder(map);
    int n = 0;
    int lenml = longest_line(map) - 1;
    int rp = row_calculator(map);
    int cp = my_strlen(map[rp / 2]) + COLS - 1;
    char inpt;
    p_finder(map, &coop);
    WINDOW *win = initscr();
    noecho();
    while (game_status(map, &strlist) == 0) {
        display_message(win, rp, lenml);
        display_map(win, map, rp, cp);
        inpt = getch();
        input_coordinator(map, cmap, inpt, &coop);
        o_map(map, &strlist);
    }
    display_map(win, map, rp, cp);
    endwin();
    return game_status(map, &strlist);
}
