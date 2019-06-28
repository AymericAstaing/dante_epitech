/*
** EPITECH PROJECT, 2018
** Linked
** File description:
** Linked Generator header
*/

#ifndef LINKED_H_
	#define LINKED_H_

typedef	struct	s_list		t_list;

struct s_list
{
	int data;
	t_list *next;
};

int		add_node(int data, t_list **list);
int		remove_node(t_list **list);
int		show_list(t_list **list);
#endif
