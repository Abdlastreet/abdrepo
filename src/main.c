/*
** EPITECH PROJECT, 2022
** main
** File description:
** main of sokoban
*/
#include "../include/my.h"
int main(int argc, char **argv)
{
    if (error_handling(argc, argv) == 84) {
        return 84;
    }
    if (error_handling(argc, argv) == 1) {
        display_usage();
        return 0;
    }
    char **map = map_loader(argv[1]);
    char **cmap = map_loader(argv[1]);
    int rtn = game_coordinator(map, cmap);
    free(map);
    free(cmap);
    if (rtn == 1) {
        return 0;
    }
    if (rtn == 2) {
        return 1;
    }
}
