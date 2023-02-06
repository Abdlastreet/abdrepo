##
## EPITECH PROJECT, 2022
## printf
## File description:
## testsMakefile
##

CC	=	gcc

RM	= 	rm -f

SRC	=	src/main.c\
		src/map_loader.c\
		src/storage_coordinates.c\
		src/x_coordinates.c\
		src/row_calculator.c\
		src/longest_line.c\
		src/game_coordinator.c\
		src/game_status.c\
		src/input_coordinator.c\
		src/p_finder.c\
		src/update_map.c\
		src/map_reset.c\
		src/o_map.c\
		src/display_map.c\
		src/display_message.c\
		src/display_usage.c\
		src/error_handling.c\
		src/my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME = my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(SRC) -lncurses -o $(NAME)

clean:
	$(RM) src/*.o
	$(RM) src/*#
	$(RM) src/*~
	$(RM) include/*#
	$(RM) include/*~
	$(RM) *.o
	$(RM) *#
	$(RM) *~

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
