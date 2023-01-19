##
## EPITECH PROJECT, 2022
## printf
## File description:
## testsMakefile
##

CC	=	gcc

RM	= 	rm -f

SRC	=	src/main.c\
		src/file_reader.c\
		src/my_getnbr.c\
		src/data_hufmann_tree.c

OBJ	=	$(SRC:.c=.o)

NAME = giantman

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
	$(RM) ../testfile/*~
	$(RM) ../testfile/*#

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
