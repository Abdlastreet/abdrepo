/*
** EPITECH PROJECT, 2023
** main of mockup
** File description:
** main
*/
#include "../include/my.h"
int main(int argc, char **argv)
{
    int sep = sep_finder(argv[1]);
    int fd = open(argv[1], O_RDONLY);
    char *data = huf_data_pull(sep, fd);
    char *cryption = crypt_data_pull(argv[1], sep, fd);
    l_recu_t list = create_letter_list(data);
    return 0;
}
