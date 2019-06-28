/*
** EPITECH PROJECT, 2017
** is_oddd.c
** File description:
** check_if_number_is_od
*/

#include	"../../include/dante.h"

int	is_odd(int n)
{
	if ((n % 2) != 0)
		return (ERROR);
	return (SUCCESS);
}
