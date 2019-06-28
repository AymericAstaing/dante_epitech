/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** display string (simple)
*/

#include	"unistd.h"
#include	"lib.h"

void	my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}
