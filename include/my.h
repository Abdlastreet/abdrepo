/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** contains functions prototypes
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "coo_list_t.h"
#include "curses.h"
#ifndef MY_H_
    #define MY_H_
char **map_loader(char const *filepath);
char *buffer_loader(char const *filepath);
storage_list_t storage_coo_finder(char **map);
storage_list_t x_coo_finder(char **map);
int row_calculator(char **map);
int longest_line(char **map);
int my_strlen(char *str);
int game_coordinator(char **map, char **cmap);
int game_status(char **map, storage_list_t *strlist);
void input_coordinator(char **map, char **cmap, char inpt, coordinates_t *coop);
char **up_update(char **map, coordinates_t *coop);
char **down_update(char **map, coordinates_t *coop);
char **right_update(char **map, coordinates_t *coop);
char **left_update(char **map, coordinates_t *coop);
int p_finder(char **map, coordinates_t *coop);
void map_reset(char **map, char **cmap, coordinates_t *coop);
void o_map(char **map, storage_list_t *strlist);
int win_cheker(char **map, storage_list_t *strlist);
int lose_cheker(char **map);
int x_cheker(char **map, int r, int c);
int error_handling(int argc, char **argv);
int map_validity_checker(const char *filepath);
int character_cheker(char c);
int file_opening_checker(const char *filepath);
void display_message(WINDOW *win, int rp, int lenml);
void display_map(WINDOW *win, char **map, int rp, int cp);
void display_usage(void);
int flag_checker(char *f);
#endif /* MY_H_ */
