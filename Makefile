##
## EPITECH PROJECT, 2022
## makefile
## File description:
## testsMakefile
##

CC	=	gcc

RM	= 	rm -f

SRC	=	src/main.c\
		src/start_error_handling.c\
		src/shell_coordinator.c\
		src/command_interpreter.c\
		src/str_to_word_array.c\
		src/str_compare.c\
		src/free_arr.c\
		src/slash_check.c\
		src/built_in_check.c\
		src/create_bin_path.c\
		src/execute_binary.c\
		src/execute_bin_binary.c\
		src/execute_my_binary.c\
		src/execute_cd.c\
		src/execute_env.c\
		src/execute_setenv.c\
		src/execute_unsetenv.c\
		src/execute_exit.c\
		src/execute_controle_d.c\
		src/my_putchar.c\
		src/my_putstr.c\
		src/my_strlen.c\
		src/nb_words.c\
		src/copy_env.c\
		src/create_env_t.c\
		src/create_env_from_lk.c\
		src/free_env.c\
		src/find_add_var.c\
		src/remove_var.c\
		src/my_strcat.c\
		src/regenerate_var.c\
		src/cd_error_handling.c\
		src/update_var.c\
		src/setenv_error_handling.c

OBJ	=	$(SRC:.c=.o)

NAME = mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -g $(SRC) -o $(NAME)

clean:
	$(RM) src/*.o
	$(RM) src/*#
	$(RM) src/*~
	$(RM) include/*#
	$(RM) include/*~
	$(RM) *.o
	$(RM) *#
	$(RM) *~
	$(RM) *.log

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
