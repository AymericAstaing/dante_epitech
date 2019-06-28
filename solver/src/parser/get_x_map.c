/*
** EPITECH PROJECT, 2017
** get x map
** File description:
** get x of txt board
*/

#include	"lib.h"
#include	"stdlib.h"
#include	"stdio.h"
#include	"../../../include/dante.h"

int	get_x_map(char *file_name)
{
	FILE	*file = fopen(file_name, "r");
	int	n = 0;
	int	c = 0;

	if (file == NULL)
		return (ERROR);
	while ((c = fgetc(file)) != NEWLINE)
		n++;
	pclose(file);
	return (n);
}