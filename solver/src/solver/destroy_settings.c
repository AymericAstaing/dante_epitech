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

int	destroy_settings(t_cell **map, t_solver_info *s_info, t_list **list)
{
	int	i = 0;
	t_list	*curr = NULL;

	while (i < (s_info->y_map)) {
		for (int j = 0; j < s_info->x_map; j++)
			free(map[i][j].neighbour);
		free(map[i]);
		i++;
	}
	while ((curr = *list) != NULL) {
		*list = (*list)->next;
		free (curr);
	}
	free(map);
	free(s_info);
	return (SUCCESS);
}