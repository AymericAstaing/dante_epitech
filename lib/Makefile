##
## EPITECH PROJECT, 2017
## Makefile Lib
## File description:
## Compile Lib
##

NAME	= libmyutils.a

SRCS	=	my_strcpy.c		\
		my_putstr.c		\
		my_putchar.c		\
		my_putnbr.c		\
		is_odd.c		\
		get_random.c		\
		my_getnbr.c		\
		my_strlen.c

MOD	= $(addprefix src/, $(SRCS:.c=.o))

CFLAGS	+= -W -Wall -Wextra
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I include/

RM	= rm -rf

$(NAME):  $(MOD)
	  ar rc $(NAME) $(MOD)

all:	$(NAME)

clean:	
	$(RM) $(MOD)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
