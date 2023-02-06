/*
** EPITECH PROJECT, 2022
** error_handling
** File description:
** handles errors
*/
#include "../include/my.h"
int error_handling(int argc, char **argv)
{
    if (argc != 2) {
        write(2, "wrong arguments number\n", 23);
        return 84;
    }
    if (flag_checker(argv[1]) == 0) {
        return 1;
    }
    if (file_opening_checker(argv[1]) == 84) {
        write(2, "problem with opening file\n", 26);
        return 84;
    }
    if (map_validity_checker(argv[1]) == 84) {
        write(2, "non valid map\n", 14);
        return 84;
    }
    return 0;
}

int map_validity_checker(const char *filepath)
{
    int n = 0;
    char *m = buffer_loader(filepath);
    while (m[n] != '\0') {
        if (character_cheker(m[n]) == 1) {
            return 84;
        }
        n++;
    }
    return 0;
}

int character_cheker(char c)
{
    int n = 0;
    const char *vlid = "#XOP \n";
    while (vlid[n] != '\0') {
        if (c == vlid[n]) {
            return 0;
        }
        n++;
    }
    return 1;
}

int file_opening_checker(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        close(fd);
        return 84;
    }
    close(fd);
    return 0;
}

int flag_checker(char *f)
{
    if (my_strlen(f) != 2) {
        return 84;
    }
    if (f[0] != '-' && f[1] != 'h') {
        return 84;
    }
    return 0;
}
