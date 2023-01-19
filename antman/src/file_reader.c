/*
** EPITECH PROJECT, 2023
** file reader
** File description:
** file reader
*/
#include "../include/my.h"
char *file_reader(char const *filepath)
{
    struct stat statbuf;
    int fd = open(filepath, O_RDONLY);
    stat(filepath, &statbuf);
    char *file = malloc(sizeof(char) * (statbuf.st_size + 1));
    read(fd, file, statbuf.st_size);
    close(fd);
    return file;
}
