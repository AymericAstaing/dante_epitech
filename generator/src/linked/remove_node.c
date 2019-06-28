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

int		remove_node(t_list **list)
{
	t_list * next_node = NULL;

	if (list == NULL)
		return (ERROR);
	next_node = (*list)->next;
	free(*list);
	*list = next_node;
	return (SUCCESS);
}