##
## EPITECH PROJECT, 2022
## printf
## File description:
## testsMakefile
##

CC	=	gcc

RM	= 	rm -f

SRC	=	src/main.c\
		src/char_recu.c\
		src/file_reader.c\
		src/compare_char_recu.c\
		src/create_char_recu_list.c\
		src/create_char_recu.c\
		src/assign_char_recu.c\
		src/isolate_smallest_recu.c\
		src/create_hufmann_tree.c\
		src/store_code.c\
		src/print_hufmann_tree.c\
		src/my_putstr.c\
		src/my_strlen.c\
		src/my_putchar.c\
		src/my_put_nbr.c\
		src/store_cryption.c\
		src/my_strcopy.c\
		src/print_crypted_char.c
OBJ	=	$(SRC:.c=.o)

NAME = antman

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(SRC) -o $(NAME)

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
