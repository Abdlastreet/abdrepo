/*
** EPITECH PROJECT, 2023
** main of mockup
** File description:
** main
*/
#include "../include/my.h"
int main(int argc, char **argv)
{
    char *file = file_reader(argv[1]);
    int bits = my_getnbr(file, 0);
    char *raw_data = data_hufmann_tree(file, argv[1], bits);
    printf("%s\n", raw_data);
    return 0;
}
