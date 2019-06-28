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

int	display_board(t_cell **map, t_game_info game_info)
{
	int	line = 0;

	if (map == NULL)
		return (ERROR);
	for (;line < game_info.y_map; line++) {
		for (int j = 0; j < game_info.x_map; j++) {
			putchar(map[line][j].value);
		}
		if (line + 1 < game_info.y_map)
			putchar('\n');
	}
	putchar('\n');
	return (SUCCESS);
}