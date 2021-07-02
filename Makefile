##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## compile
##

SRC		=		main_bsq.c	\
				bsq_f.c

OBJ		=		$(SRC:.c=.o)

NAME	=		bsq

CC		=		gcc -g

all:	$(OBJ)
		cd lib/my/ && make
		gcc -o $(NAME) $(OBJ) -Llib/ -lmy

test_run:	all
			cd lib/my/tests && make

clean:
		rm -f *.o
		rm -f *~

fclean:	clean
		rm -f $(NAME)
		rm -f lib/libmy.a
		cd lib/my/ && make fclean

re:		fclean all
