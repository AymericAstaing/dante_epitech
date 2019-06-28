/*
** EPITECH PROJECT, 2018
** Init
** File description:
** initialisation of linked list
*/


#include	"lib.h"
#include	"stdlib.h"
#include	"stdio.h"
#include	"../../include/linked.h"
#include	"../../include/generator.h"
#include	"../../include/dante.h"

int		add_node(int cell, t_list **list)
{
	t_list * new_cell;
	new_cell = malloc(sizeof(t_list));
	if (!(new_cell))
		return (ERROR);
	new_cell->data = cell;
	new_cell->next = *list;
	*list = new_cell;
	return (SUCCESS);
}