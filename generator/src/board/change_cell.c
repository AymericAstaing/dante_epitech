/*
** EPITECH PROJECT, 2017
** remove wall
** File description:
** remove (x,y) wall of dante
*/

#include	"lib.h"
#include	"stdlib.h"
#include	"stdio.h"
#include	"../../include/linked.h"
#include	"../../include/generator.h"
#include	"../../../include/dante.h"

int	is_potential(int curr, int id_p, int x_m, int y_m)
{
	if ((id_p >= 0 &&
		id_p < (x_m * y_m)) && id_p >= (curr - (2 * x_m)) &&
		id_p <= (curr + 2 * (x_m)))
			return (SUCCESS);
	return (ERROR);
}

int	potential_id(int id, int *p_id, int x_m, int y_m, t_cell **map)
{
	int	*n = map[id / x_m][id % x_m].neighbour;
	int	j = 0;

	for (int i = 0; i < 4; i++) {
			if (is_potential(id, n[i], x_m, y_m) &&
				map[n[i] / x_m][n[i] % x_m].passed == 0) {
				p_id[j] = n[i];
				j++;
			}
	}
	p_id[j] = -1;
	return (j);
}

int	wall_id(int ex_cell, int new_cell, int x_m)
{
	if (new_cell == ex_cell + (2 * x_m))
		return (new_cell - x_m);
	if (new_cell == ex_cell -  (2 * x_m))
		return (new_cell + x_m);
	if (new_cell == ex_cell + 2)
		return (new_cell - 1);
	if (new_cell == ex_cell - 2)
		return (new_cell + 1);
	return (ERROR);
}

int	go_back(t_list **list, int *c_i)
{
	remove_node(list);
	if ((*list)->next == NULL) {
		free(c_i);
		return (-1);
	}
	return ((*list)->data);
}

int	change_cell(int x_m, int y_m, t_cell **map, t_list **list)
{
	int	*cells_id = malloc(sizeof(int) * 4);
	int	max_possibility = 0;
	int	selected_id = 0;
	int	id = (*list)->data;

	while (max_possibility == 0) {
		max_possibility = potential_id(id, cells_id,
			x_m, y_m, (&(*map)));
		if (max_possibility == 0) {
			id = go_back(list, cells_id);
			if (id == -1)
				return (SUCCESS);
		}
	}
	selected_id = cells_id[get_random(0, max_possibility - 1)];
	map[selected_id / x_m][selected_id % x_m].passed = 1;
	add_node(selected_id, list);
	remove_wall(wall_id(id, selected_id, x_m), x_m, map);
	free(cells_id);
	cells_id = NULL;
	return (ERROR);
}