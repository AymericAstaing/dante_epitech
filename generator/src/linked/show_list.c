/*
** EPITECH PROJECT, 2018
** show_lst
** File description:
** display linked list
*/

#include	"lib.h"
#include	"stdlib.h"
#include	"stdio.h"
#include	"../../include/linked.h"
#include	"../../include/generator.h"
#include	"../../include/dante.h"

int		show_list(t_list **list)
{
	struct s_list		*temp = *list;

	if ((*list) == NULL)
		return (ERROR);
	while (temp != NULL) {
		my_putnbr(temp->data);
	if (temp->next != NULL)
		my_putchar(' ');
	temp = temp->next;
	}
	return (SUCCESS);
}