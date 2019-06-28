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
#include	"../../../include/dante.h"

int	destroy_settings(t_cell **map, t_game_info *game_info, t_list **list)
{
	int	i = 0;
	t_list	*curr = NULL;

	while (i < (game_info->y_map)) {
		for (int j = 0; j < game_info->x_map; j++)
			free(map[i][j].neighbour);
		free(map[i]);
		i++;
	}
	while ((curr = *list) != NULL) {
		*list = (*list)->next;
		free (curr);
	}
	free(map);
	free(game_info);
	return (SUCCESS);
}