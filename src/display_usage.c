/*
** EPITECH PROJECT, 2022
** display usage
** File description:
** displays usage on terminal when -h
*/
#include "../include/my.h"
void display_usage(void)
{
    write(1, "USAGE\n     ./my_sokoban map\n", 28);
    write(1, "DESCRIPTION\n     map file representing ", 39);
    write(1, "the warehouse map, containing '#' for walls,\n", 45);
    write(1, "         'P' for the player, ", 29);
    write(1, "'X' for boxes and 'O' for storage locations.\n", 45);
}
