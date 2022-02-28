##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC	=	main.c	\
		second.c	\
		third.c	\
		fourth.c	\
		fifth.c	\
		sixt.c	\
		set.c	\
		set2.c	\
		set3.c	\
		set4.c	\
		set_call_sys.c	\
		set_call_sys2.c	\
		move.c	\
		get_file_size.c	\
		proced1.c	\
		proced2.c

NAME	=	my_runner

OBJ	=	$(SRC:.c=.o)

MY	=	my.h

CC	=	cc

all:	exec_lib $(NAME)

exec_lib:
		cd lib/my/ && make

clean:
	rm -f $(OBJ)

$(NAME):	$(OBJ)
	gcc -g -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio	\
	-lm -o $(NAME) $(OBJ) -Llib/ -lmy

fclean: clean
	rm -f $(NAME)
	rm -f *.c~
	rm -f *.out
	rm -f vgcore*
	rm -f *.gcda
	rm -f *.gcno
	rm -f unit_tests*

lib_fclean:
		cd lib/my/ && make fclean

push_fclean: fclean
		cd lib/my/ && make fclean

re:	fclean all

tests_run: exec_lib
	gcc -o unit_tests $(SRC) tests/*.c -Llib/ -lmy --coverage -lcriterion
	./unit_tests
	gcovr --exclude tests
	gcovr -b --exclude tests
