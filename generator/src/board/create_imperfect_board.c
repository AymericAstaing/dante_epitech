/*
** EPITECH PROJECT, 2018
** imperfect node
** File description:
** modify the maze to make it imperfect
*/

#include	"lib.h"
#include	"stdlib.h"
#include	"stdio.h"
#include	"../../include/linked.h"
#include	"../../include/generator.h"
#include	"../../include/dante.h"

int		create_imperfect_board(t_cell **map, t_game_info g_info)
{
	int	x_map = g_info.x_map;
	int	y_map = g_info.y_map;
	int	nbr_wall_to_broke = (x_map * y_map) * 0.1;
	int	max_rand = (x_map* y_map) - 1;
	int	rand_nbr = 0;

	while (nbr_wall_to_broke != 0) {
		rand_nbr = get_random(0, max_rand);
		if (map[rand_nbr / x_map][rand_nbr % x_map].value == WALL &&
		remove_wall(rand_nbr, g_info.x_map, map) == SUCCESS)
			nbr_wall_to_broke--;
	}
	return (SUCCESS);
}