/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** env_line_t
*/

#ifndef ENV_LINE_T_H_
    #define ENV_LINE_T_H_
typedef struct env_line_s {
    char *line;
    char **sepline;
    struct env_line_s *next;
} env_line_t;
#endif /* !ENV_LINE_T_H_ */
