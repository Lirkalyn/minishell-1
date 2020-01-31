##
## EPITECH PROJECT, 2019
## Day_10
## File description:
## makefile
##
.PHONY : clean fclean re

SRC	=	main.c \
		display.c \
		builtin.c \
		builtin2.c \
		splitter.c \
		my_str_to_word_array.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean $(NAME)
