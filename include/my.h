/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/
#ifndef MY_H_
    #define MY_H_
    #include "env_t.h"
    #include <stddef.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <errno.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <signal.h>
int start_error_handling(int argc);
void shell_coordinator(env_t *env);
int command_interpreter(char *line, ssize_t size, env_t *env);
char **str_to_word_array(char *str, char *sep);
char **malloc_array(char *str, char *sep);
void malloc_lines(char *str, char **arr, char *sep);
void fill_lines(char *str, char **arr, char *sep);
int comp_sep(char c, char *sep);
void free_arr(char **arr);
void create_bin_path(char **bina, char *path);
void execute_exit(char **w_arr, char *line, env_t *env);
void execute_controle_d(ssize_t size, char *line, env_t *env);
int execute_binary(char **w_arr, env_t *env);
void execution_binary_child_process(char **w_arr, char **env);
int execve_error_handling(int status, char **w_arr);
int execute_my_binary(char **w_arr, env_t *env);
int my_binary_error_handling(char *comd);
int execute_bin_binary(char **w_arr, env_t *env);
int execute_cd(char **w_arr, env_t *env);
int execute_env(char **w_arr, env_t *env);
int execute_setenv(char **w_arr, env_t *env);
int setenv_error_handling(char **w_arr, env_t *env);
int execute_unsetenv(char **w_arr, env_t *env);
int unsetenv_error_handling(char **w_arr);
void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
int str_compare(char const *str, char const *model);
int slash_check(char *line);
int my_str_copy(char *dest, char *str, int st);
int nb_words(char **arr);
int built_in_check(char *bin);
char **copy_env(char **env);
env_t create_env_t(char **env);
void fill_env(env_t *env);
env_line_t *create_env_line(char *line);
void assign_line(env_t *env, env_line_t *envline);
void create_env_from_lk(env_t *lkenv);
void free_env(env_t *env);
env_line_t *find_env_var(char *var, env_t *env);
void modify_env_var(env_line_t *line, env_t *env, char **w_arr);
void create_new_var(env_t *env, char **w_arr);
void remove_env_line(env_t *env, env_line_t *line);
void remove_only_var(env_t *env, env_line_t *current);
void remove_first_var(env_t *env, env_line_t *current);
void remove_last_var(env_t *env, env_line_t *current, env_line_t *culast);
void free_var(env_line_t *var);
char *my_strcat(char *str1, char *str2);
int bin_binary_error_handling(char *comd, char *fold_path);
char *find_bin_folder(char *path, char *comd);
int check_folder(char *fold_path, char *comd);
void regenerate_pwd(env_t *env);
int cd_error_handling(char **w_arr, env_t *env);
int cd_filetype_error_handling(char **w_arr);
void execute_home_return(char **w_arr, env_t *env);
void execute_back_return(char **w_arr, env_t *env);
void execute_chdir(char **w_arr, env_t *env);
void update_pwd(env_t *env);
void update_path(env_t *env, env_line_t *path);
void update_lastpwd(env_t *env);
void update_home(env_t *env, env_line_t *home);
void check_update(env_t *env, env_line_t *current);
int alphanum_setenv_error_handling(char **w_arr);
int check_alphanum(char *str);
#endif /* !MY_H_ */
