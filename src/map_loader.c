/*
** EPITECH PROJECT, 2022
** map_loader
** File description:
** load map to array
*/
#include "../include/my.h"
char *buffer_loader(char const *filepath)
{
    struct stat statbuf;
    int fd = open(filepath, O_RDONLY);
    char *buffer;
    stat(filepath, &statbuf);
    buffer = malloc(sizeof(char) * (statbuf.st_size + 1));
    read(fd, buffer, statbuf.st_size);
    close(fd);
    return buffer;
}

int lines_counter(char *buffer)
{
    int n = 0;
    int lines = 0;
    while (buffer[n] != '\0') {
        if (buffer[n] == '\n') {
            lines++;
        }
        n++;
    }
    return lines;
}

char **map_loader(char const *filepath)
{
    int n = 0; int n2 = 0;
    char *buffer = buffer_loader(filepath);
    int lines = lines_counter(buffer);
    int nbcline = 0;
    char **dest = malloc(sizeof(char *) * (lines + 1));
    int fd = open(filepath, O_RDONLY);
    while (buffer[n] != '\0') {
        if (buffer[n] == '\n') {
            dest[n2] = malloc(sizeof(char) * (nbcline + 2));
            read(fd, dest[n2], nbcline + 1);
            n2++;
            nbcline = 0;
        } else {
            nbcline++;
        }
        n++;
    }
    close(fd);
    free(buffer);
    return dest;
}
