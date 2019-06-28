/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** PSU_minishell1_2018
*/

#include	"lib.h"
#include	"../../include/dante.h"
#include	"stdlib.h"

int my_strlen (char const *str)
{
	int	i = 0;

	if (str == NULL)
		return (ERROR);
	while (str[i] != END) {
		i++;
	}
	return (i);
}
