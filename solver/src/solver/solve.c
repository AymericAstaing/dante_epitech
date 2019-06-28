/*
** EPITECH PROJECT, 2017
** solve dante
** File description:
** task01
*/

#include	"lib.h"
#include	"stdlib.h"
#include	"stdio.h"
#include	"../../include/solver.h"
#include	"../../../include/dante.h"

int	solve(t_cell **map, t_solver_info *s_info, t_list **list)
{
	int	current = 0;
	int	end_cell_id = (s_info->x_map *
	(s_info->y_map - 1)) + (s_info->x_map - 1);

	while (current != end_cell_id) {
		current = find_path((&(*map)), s_info, list);
	}
	reverse_list(list);
	display_resolution(map, s_info, list);
	return (SUCCESS);
}