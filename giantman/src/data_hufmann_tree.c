/*
** EPITECH PROJECT, 2023
** giantman
** File description:
** data_hufmann_tree
*/
#include "../include/my.h"
char *data_hufmann_tree(char *file, char const *filepath, int bits)
{
    char *raw_data = create_raw_data(filepath, bits);
    return raw_data;

}

/*int find_last_comma(char *file)
{
    int pos;
    for (int n = 0; file[n] != '\0'; n++) {
        if (file[n] == ',') {
            pos = n;
        }
    }
    return pos;
}
*/

char *create_raw_data(char const *filepath, int bits)
{
    int strw;
    char *raw_data;
    int fd = open(filepath, O_RDONLY);
    struct stat statbuf;
    stat(filepath, &statbuf);
    strw = statbuf.st_size - (bits / 8);
    raw_data = malloc(sizeof(char) * (strw + 1));
    read(fd, raw_data, strw);
    close(fd);
    return raw_data;
}