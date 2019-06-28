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

int	remove_wall(int id, int x_map, t_cell **map)
{
	map[id / x_map][id % x_map].value = FREE_CELL;
	map[id / x_map][id % x_map].passed = 1;
	return (SUCCESS);
}