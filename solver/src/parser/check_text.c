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

int	check_text(char *file_name)
{
	FILE	*file = fopen(file_name, "r");
	char	*mem = malloc(sizeof(char) * 100000000);
	int	c = 0;
	int	i = 0;

	if (file == NULL)
		return (ERROR);
	while ((c = fgetc(file)) != EOF) {
		if ((char) c != WALL && (char) c != FREE_CELL && c != NEWLINE)
			return (ERROR);
		mem[i] = (char) c;
		i++;
	}
	mem[i] = '\0';
	if (mem[i - 2] != FREE_CELL) {
		free(mem);
		return (ERROR);
	}
	pclose(file);
	free(mem);
	return (SUCCESS);
}