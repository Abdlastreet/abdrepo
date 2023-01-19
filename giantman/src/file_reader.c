/*
** EPITECH PROJECT, 2023
** file reader
** File description:
** file reader
*/
#include "../include/my.h"
char *crypt_data_pull(char const *filepath, int sep, int fd)
{
    struct stat statbuf;
    stat(filepath, &statbuf);
    char *cryption = malloc(sizeof(char) * (statbuf.st_size - sep + 1));
    read(fd, cryption, statbuf.st_size - sep);
    close(fd);
    return cryption;
}

char *huf_data_pull(int sep, int fd)
{
    char *data = malloc(sizeof(char) * (sep + 1));
    read(fd, data, sep);
    return data;
}

int sep_finder(char const *filepath)
{
    int n = 0;
    struct stat statbuf;
    int fd = open(filepath, O_RDONLY);
    stat(filepath, &statbuf);
    char *file = malloc(sizeof(char) * (statbuf.st_size + 1));
    read(fd, file, statbuf.st_size);
    while (file[n] != '\n' || file[n + 1] != '\n') {
        n++;
    }
    close(fd);
    free(file);
    return n + 2;
}
