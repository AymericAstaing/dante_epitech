/*
** EPITECH PROJECT, 2018
** remove node
** File description:
** remove linked list node
*/

#include	"lib.h"
#include	"stdlib.h"
#include	"stdio.h"
#include	"../../include/linked.h"
#include	"../../include/generator.h"
#include	"../../include/dante.h"

int		check_perfect(t_cell **map, int x, int y)
{
	if (map[x - 2][y - 1].value != FREE_CELL || map[x - 1][y - 2].value != FREE_CELL)
		return (ERROR);
	if (map[x - 2][y - 1].value == FREE_CELL && map[x - 1][y - 2].value == FREE_CELL) {
		if (get_random(0, 1) == 0)
			map[x - 1][y - 2].value = WALL;
		else
			map[x - 2][y - 1].value = WALL;
		return (SUCCESS);
	}
	if (map[x - 2][y - 1].value == FREE_CELL) {
		map[x - 2][y - 1].value = WALL;
		return (SUCCESS);
	} else {
		map[x - 1][y - 2].value = WALL;
		return (SUCCESS);
	}
	return (ERROR);
}

int		generate(t_cell **map, t_game_info g_info, t_list **list)
{
	int	i = 0;

	while (i == 0) {
		if (change_cell(g_info.x_map, g_info.y_map,
		(&(*map)), list) == SUCCESS) {
			if (g_info.perfect == 0)
				create_imperfect_board(map, g_info);
			else
				check_perfect(map, g_info.x_map, g_info.y_map);
			return (SUCCESS);
		}
	}
	return (SUCCESS);
}