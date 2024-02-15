/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** execute_bin_binary
*/
#include "../include/my.h"
int execute_bin_binary(char **w_arr, env_t *env)
{
    int rtn = 0;
    char *bin_fold;

    if (slash_check(w_arr[0]) == 0 || built_in_check(w_arr[0]) == 0) {
        return 0;
    }
    bin_fold = find_bin_folder(env->path, w_arr[0]);
    if (bin_binary_error_handling(w_arr[0], bin_fold) == 1) {
        return 1;
    }
    create_bin_path(&(w_arr[0]), bin_fold);
    rtn = execute_binary(w_arr, env);
    return rtn;
}

char *find_bin_folder(char *path, char *comd)
{
    int len;
    char *fold_path;
    int i = 0;
    char **allpath = str_to_word_array(path, ":");

    while (allpath[i] != NULL) {
        if (check_folder(allpath[i], comd) == 0) {
            len = my_strlen(allpath[i]);
            fold_path = malloc(sizeof(char) * (len + 1 + 1));
            fold_path[len + 1] = '\0';
            fold_path[len] = '/';
            my_str_copy(fold_path, allpath[i], 0);
            free_arr(allpath);
            return fold_path;
        }
        i++;
    }
    free_arr(allpath);
    return NULL;
}

int check_folder(char *fold_path, char *comd)
{
    char *nfold_path = my_strcat(fold_path, "/");
    char *bin_path = my_strcat(nfold_path, comd);

    if (access(bin_path, F_OK) == 0) {
        free(nfold_path);
        free(bin_path);
        return 0;
    }
    free(nfold_path);
    free(bin_path);
    return -1;
}

int bin_binary_error_handling(char *comd, char *fold_path)
{
    char *bin_path;
    struct stat statbuf;

    if (fold_path == NULL) {
        write(2, comd, my_strlen(comd));
        write(2, ": Command not found.\n", 21);
        free(fold_path);
        return 1;
    }
    bin_path = my_strcat(fold_path, comd);
    stat(bin_path, &statbuf);
    if (access(bin_path, X_OK) == -1 || S_ISDIR(statbuf.st_mode)) {
        write(2, comd, my_strlen(comd));
        write(2, ": Permission denied.\n", 21);
        free(bin_path);
        free(fold_path);
        return 1;
    }
    free(bin_path);
    return 0;
}
