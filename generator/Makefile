##
## EPITECH PROJECT, 2017
## Makefile Generator
## File description:
## Makefile for generator
##

#	Root path
ROOT		=		./

#	Sources path
F_SRC		=		$(ROOT)src/

#	Binary name
NAME		=		generator

#	Debug sources
SRC		=		$(F_SRC)main.c

SRC		+=		$(F_SRC)board/destroy_settings.c	\
				$(F_SRC)board/display_board.c		\
				$(F_SRC)board/change_cell.c		\
				$(F_SRC)board/create_imperfect_board.c	\
				$(F_SRC)board/generate.c		\
				$(F_SRC)board/remove_wall.c		\
				$(F_SRC)board/init_board.c

SRC		+=		$(F_SRC)linked/add_node.c		\
				$(F_SRC)linked/show_list.c		\
				$(F_SRC)linked/remove_node.c

#	Compile every source file to .o
OBJ		=		$(SRC:.c=.o)

#	Compiler
CC		=		gcc -g3

LIB		=		-L../lib/
LIB		+=		-I../lib/include -L../lib/ -lmyutils

LIBUTILS_MAKE	=		make -C ../lib/
LIBUTILS	=		lib/libutils.a

#	Compilation flags
CFLAGS		+=		-Wall -Werror -Wextra -pedantic -std=gnu99	\
				-I $(ROOT)../include/

CFLAGS		+=		$(LIB)

LDFLAGS		=		$(LIB)

#	Call compilation rule
all:				$(LIBUTILS) $(NAME)

#	Compile every file then pack them all !
$(NAME):			$(OBJ)
				$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)

#	Compile with g3 flag
debug:				fclean $(OBJ)
				$(CC) -o $(NAME) $(CFLAGS) -g3 $(OBJ) $(LDFLAGS)

$(LIBUTILS):
				$(LIBUTILS_MAKE)

clean:
				rm -f $(OBJ)
				$(LIBUTILS_MAKE) clean

fclean: 			clean
				rm -rf $(NAME)
				$(LIBUTILS_MAKE) fclean

#	Clean all then compile
re:				fclean all

.PHONY:				all clean fclean re

