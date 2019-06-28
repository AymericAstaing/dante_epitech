/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** task01
*/

#include	"lib.h"
#include	"stdlib.h"
#include	"stdio.h"
#include	"../../include/solver.h"
#include	"../../../include/dante.h"

int	get_char_board(char ***board, int x_map, int y_map, FILE *file)
{
	int	c = 0;
	int	line = 0;
	int	column = 0;

	for (int i = 0; i < y_map; i++) {
		(*board)[i] = malloc((sizeof(char)) * x_map);
		if (!(*board)[i])
			return (ERROR);
	}
	if ((*board) == NULL || file == NULL)
		return (ERROR);
	while ((c = fgetc(file)) != EOF) {
		if (c == NEWLINE) {
			line++;
			column = 0;
		} else {
			(*board)[line][column] = (char) c;
			column++;
		}
	}
	return (SUCCESS);
}

int	parse_board(t_cell **map, t_solver_info s_i, t_list **list, char * n)
{
	FILE	*file = fopen(n, "r");
	char	**board = (char **)malloc(sizeof(char *) * s_i.y_map);

	if (file == NULL)
		return (ERROR);
	if (!get_char_board(&(board), s_i.x_map, s_i.y_map, file))
		return (ERROR);
	init_board(map, s_i, list, board);
	for (int i = 0; i < s_i.y_map; i++)
		free(board[i]);
	free(board);
	pclose(file);
	return (SUCCESS);
}