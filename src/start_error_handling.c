/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** start_error_handling
*/
#include "../include/my.h"
int start_error_handling(int argc)
{
    if (argc != 1) {
        write(2, "Error : Too much arguments\n", 27);
        return 84;
    }
    return 0;
}
