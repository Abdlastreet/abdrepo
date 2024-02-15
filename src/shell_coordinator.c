/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** shell_coordinator
*/
#include "../include/my.h"
void shell_coordinator(env_t *env)
{
    int rtn = 0;
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t size = 0;

    while (1) {
        if (isatty(STDIN_FILENO)) {
            my_putstr("$> ");
        }
        size = getline(&line, &bufsize, stdin);
        env->rtn = command_interpreter(line, size, env);
    }
}
