##
## EPITECH PROJECT, 2017
## Makefile Global
## File description:
## Compile Al Folder
##

RM	= rm -rf

all	:
		make -s -C solver/
		make -s -C generator/

clean	:
		make clean -s -C solver/
		make clean -s -C generator/

fclean	:	clean
		make fclean -s -C solver/
		make fclean -s -C generator/

re	:	fclean all

.PHONY	:	all clean fclean re
	