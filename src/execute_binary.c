/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** execute binary from path
*/
#include "../include/my.h"
int execute_binary(char **w_arr, env_t *env)
{
    int rtn;
    int status = 0;
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        execution_binary_child_process(w_arr, env->myenv);
    } else {
        wait(&status);
        rtn = execve_error_handling(status, w_arr);
        return rtn;
    }
}

void execution_binary_child_process(char **w_arr, char **env)
{
    int status = 0;

    status = execve(w_arr[0], w_arr, env);
    if (status == -1) {
        write(2, w_arr[0], my_strlen(w_arr[0]));
        write(2, ": ", 2);
        write(2, w_arr[0], my_strlen(w_arr[0]));
        write(2, ": cannot execute binary file\n", 29);
        exit(126);
    }
    exit(0);
}

int execve_error_handling(int status, char **w_arr)
{
    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV) {
        if (WCOREDUMP(status)) {
            write(2, "Segmentation fault (core dumped)\n", 33);
        } else {
            write(2, "Segmentation fault\n", 19);
        }
        return 139;
    }
    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGFPE) {
        if (WCOREDUMP(status)) {
            write(2, "Floating exception (core dumped)\n", 33);
        } else {
            write(2, "Floating exception\n", 19);
        }
        return 136;
    }
    if (WIFEXITED(status)) {
        return WEXITSTATUS(status);
    }
    return 0;
}
