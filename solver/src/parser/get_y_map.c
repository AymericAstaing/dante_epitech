/*
** EPITECH PROJECT, 2017
** get y map
** File description:
** get y of txt board
*/

#include	"lib.h"
#include	"stdlib.h"
#include	"stdio.h"
#include	"../../../include/dante.h"

int	get_y_map(char *file_name)
{
	FILE	*file = fopen(file_name, "r");
	int	c = 0;
	int	count = 0;

	while ((c = fgetc(file)) != EOF) {
		if ((char) c == NEWLINE)
			count++;
	}
	pclose(file);
	return (count);
}