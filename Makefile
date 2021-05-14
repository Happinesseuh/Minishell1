##
## EPITECH PROJECT, 2021
## B-PSU-101-PAR-1-1-minishell1-ines.maaroufi
## File description:
## Makefile
##

SRC	=	./sources/env.c\
		./sources/functions_lib.c\
		./sources/functions_lib2.c\
		./sources/commands.c\
		./sources/execute_commands.c\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:	$(OBJ)
	gcc $(OBJ) -o $(NAME) -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all tests_run clean fclean re