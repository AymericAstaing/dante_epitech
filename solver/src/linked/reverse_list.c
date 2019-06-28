/*
** EPITECH PROJECT, 2018
** Reverse
** File description:
** reverse linked list
*/


#include	"lib.h"
#include	"stdlib.h"
#include	"stdio.h"
#include	"../../include/solver.h"
#include	"../../include/dante.h"
#include	<stdlib.h>

void	reverse_list(t_list **ll)
{
	t_list		*prev = NULL;
	t_list		*current = *ll;
	t_list		*next = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*ll = prev;
}