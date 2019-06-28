/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** task01
*/

#include	"lib.h"
#include	"stdlib.h"
#include	"stdio.h"
#include	"../../include/linked.h"
#include	"../../include/generator.h"
#include	"../../include/dante.h"

int	is_exit(int x, int y, int x_map, int y_map)
{
	if ((x > (x_map - 3)) && (y > (y_map - 3)))
		return (TRUE);
	return (FALSE);
}

int	is_wall(int x, int y, int odd_map, int x_map, int y_map)
{
	if (odd_map == TRUE && is_exit(x, y, x_map, y_map))
		return (FALSE);
	if (!is_odd(y) || !is_odd(x))
		return (TRUE);
	return (FALSE);
}

int	get_hor_coor(int current, int curr_x, int x_map, int i)
{
	if (i == E && curr_x + 2 < x_map)
		return (current + 2);
	if (i == W && curr_x - 2 >= 0)
		return (current - 2);
	return (ERROR);
}

int	get_cell(int x, int y, t_game_info g_i, t_cell *cell)
{
	int	x_map = g_i.x_map;
	int	current = (x_map * y) + x;

	cell->neighbour = malloc((sizeof(int)) * 4);
	cell->neighbour[N] = current - (2 * x_map);
	cell->neighbour[S] = current + (2 * x_map);
	cell->neighbour[E] = get_hor_coor(current, x, x_map, E)	;
	cell->neighbour[W] = get_hor_coor(current, x, x_map, W);
	cell->passed = 0;
	if (is_wall(x, y, g_i.odd_map, x_map, g_i.y_map))
		cell->value = WALL;
	else
		cell->value = FREE_CELL;
	return (SUCCESS);
}

int	init_board(t_cell **map, t_game_info g_info, t_list **list)
{
	int	i = 0;

	add_node(0, list);
	while (i < g_info.y_map) {
		for (int j = 0; j < g_info.x_map; j++) {
			get_cell(j, i, g_info, (&(map[i][j])));
		}
		i++;
	}
	return (SUCCESS);
}
