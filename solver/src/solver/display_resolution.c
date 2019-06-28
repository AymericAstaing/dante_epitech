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

int	check_if_exist(int value, t_list **list)
{
	struct s_list		*temp = *list;

	if ((*list) == NULL)
		return (ERROR);
	while (temp != NULL) {
		if (temp->data == value)
			return (SUCCESS);
		temp = temp->next;
	}
	return (ERROR);
}

int	display_resolution(t_cell **map, t_solver_info *s_i, t_list **list)
{
	int	line = 0;
	int	id = 0;
	struct s_list		*temp = *list;

	if (map == NULL)
		return (ERROR);
	for (;line < s_i->y_map; line++) {
		for (int j = 0; j < s_i->x_map; j++) {
			id = (s_i->x_map * line) + j;
			if (check_if_exist(id, list) == TRUE) {
				temp = temp->next;
				putchar('o');
			} else {
				putchar(map[line][j].value);
			}
		}
		if (line + 1 < s_i->y_map)
			putchar('\n');
	}
	return (SUCCESS);
}