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

int	existing_coor(int coor, t_solver_info solver_info)
{
	if (coor >= 0 && coor < (solver_info.x_map * solver_info.y_map))
		return (SUCCESS);
	return (ERROR);
}

int	next(t_list **list, int selected_id)
{
	if (selected_id == -1) {
		remove_node(list);
		return (-1);
	}
	add_node(selected_id, list);
	return (SUCCESS);
}

int	potential_cell(t_cell **map, int best_distance, int x, int y)
{
	if (map[x][y].distance < best_distance &&
	map[x][y].value != WALL && map[x][y].passed == 0)
		return (SUCCESS);
	return (ERROR);
}

int	store_cell(t_cell **map, int future, int x_map, int *best, int *id)
{
	map[future / x_map][future % x_map].passed = 1;
	*best = map[future / x_map][future % x_map].distance;
	*id = future;
	return (SUCCESS);
}

int	find_path(t_cell **map, t_solver_info *solver_info, t_list **list)
{
	int	id = (*list)->data;
	int	x_map = solver_info->x_map;
	int	i = 0;
	int	future_id = 0;
	int	best_distance = 1000000;
	int	best_id = -1;

	while (i < 4) {
		future_id = map[id / x_map][id % x_map].neighbour[i];
		if (existing_coor(future_id, *solver_info) &&
		potential_cell(map, best_distance, future_id / x_map,
		future_id % x_map))
			store_cell(map, future_id, x_map,
			&best_distance, &best_id);
		i++;
	}
	if (next(list, best_id) == -1)
		return ((*list)->data);
	return (best_id);
}