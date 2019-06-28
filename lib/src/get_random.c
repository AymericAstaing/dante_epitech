/*
** EPITECH PROJECT, 2017
** get_random.c
** File description:
** get random nbr between min and max
*/

#include	"stdlib.h"
#include	<time.h>
#include	"../../include/dante.h"
#include	"lib.h"

int	get_random(const int min, const int max)
{
	return ((rand() % (max - min + 1)) + min);
}
