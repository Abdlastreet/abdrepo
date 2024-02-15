/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main
*/
#include "../include/my.h"
int main(int argc, char **argv, char **env)
{
    env_t stenv;

    if (start_error_handling(argc) == 84) {
        return 84;
    }
    stenv = create_env_t(env);
    shell_coordinator(&stenv);
    return 0;
}
