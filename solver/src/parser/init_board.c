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
#include	"../../include/dante.h"

int	get_hor_coor(int current, int curr_x, int x_map, int i)
{
	if (i == E && curr_x + 1 < x_map)
		return (current + 1);
	if (i == W && curr_x - 1  >= 0)
		return (current - 1);
	return (-1);
}

int	get_distance(int id, int x_map, int y_map)
{
	int distance = get_distance_between_cell(id / x_map, id % x_map,
			x_map - 1, y_map - 1);
	if ((distance) < 0)
		return (ERROR);
	return (distance);
}

int	get_cell(int x, int y, t_solver_info g_i, t_cell *cell, char value)
{
	int	x_map = g_i.x_map;
	int	current = (x_map * y) + x;

	cell->neighbour = malloc((sizeof(int)) * 4);
	cell->neighbour[N] = current - x_map;
	cell->neighbour[S] = current + x_map;
	cell->neighbour[E] = get_hor_coor(current, x, x_map, E);
	cell->neighbour[W] = get_hor_coor(current, x, x_map, W);
	cell->passed = 0;
	cell->value = value;
	cell->distance = get_distance(current, x_map, g_i.y_map);
	return (SUCCESS);
}

int	init_board(t_cell **map, t_solver_info s_i, t_list **list, char **b)
{
	int	i = 0;

	add_node(0, list);
	while (i < s_i.y_map) {
		for (int j = 0; j < s_i.x_map; j++) {
			get_cell(j, i, s_i, (&(map[i][j])), b[i][j]);
		}
		i++;
	}
	return (SUCCESS);
}
