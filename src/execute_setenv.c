/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** execute_setenv
*/
#include "../include/my.h"
int execute_setenv(char **w_arr, env_t *env)
{
    int rtn = setenv_error_handling(w_arr, env);
    env_line_t *line;

    if (rtn != -1) {
        return rtn;
    }
    line = find_env_var(w_arr[1], env);
    if (line == NULL) {
        create_new_var(env, w_arr);
    } else {
        modify_env_var(line, env, w_arr);
    }
    create_env_from_lk(env);
    return 0;
}

void create_new_var(env_t *env, char **w_arr)
{
    int argc = nb_words(w_arr);
    int lenv = my_strlen(w_arr[1]);
    int lenc = 0;
    int st = 0;
    env_line_t *line = malloc(sizeof(env_line_t));

    if (argc == 3)
        lenc = my_strlen(w_arr[2]);
    line->line = malloc(sizeof(char) * (lenv + lenc + 1 + 1));
    line->line[lenv + lenc + 1] = '\0';
    st += my_str_copy(line->line, w_arr[1], st);
    st += my_str_copy(line->line, "=", st);
    if (argc == 3)
        st += my_str_copy(line->line, w_arr[2], st);
    line->sepline = str_to_word_array(line->line, "=");
    assign_line(env, line);
}

void modify_env_var(env_line_t *line, env_t *env, char **w_arr)
{
    int argc = nb_words(w_arr);
    int lenv = my_strlen(w_arr[1]);
    int lenc = 0;
    int st = 0;

    if (argc == 3)
        lenc = my_strlen(w_arr[2]);
    free(line->line);
    line->line = malloc(sizeof(char) * (lenv + lenc + 1 + 1));
    line->line[lenv + lenc + 1] = '\0';
    st += my_str_copy(line->line, line->sepline[0], st);
    st += my_str_copy(line->line, "=", st);
    if (argc == 3)
        st += my_str_copy(line->line, w_arr[2], st);
    free_arr(line->sepline);
    line->sepline = str_to_word_array(line->line, "=");
}
