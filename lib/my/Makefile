##
## EPITECH PROJECT, 2020
## make file
## File description:
## compile all the files
##

all:    gcc cpylib cpymyh clean

gcc:
		gcc -c *.c
		ar rc libmy.a *.o

cpylib:
		cp libmy.a ../

cpymyh:
		cp my.h ../../include/

clean:
		rm -f *.o

fclean:
		rm -f libmy.a
