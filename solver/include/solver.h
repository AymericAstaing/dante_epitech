/*
** EPITECH PROJECT, 2018
** Dante
** File description:
** Dante General header
*/

#ifndef SOLVER_H_
	#define SOLVER_H_

typedef	struct	s_cell		t_cell;
typedef	struct	s_list		t_list;
typedef	struct	s_solver_info	t_solver_info;

struct s_solver_info
{
	int x_map;
	int y_map;
};

struct s_cell
{
	int passed;
	double distance;
	char value;
	int *neighbour;
};

struct s_list
{
	int data;
	t_list *next;
};

int	destroy_settings(t_cell **, t_solver_info *, t_list **);
int	add_node(int, t_list **);
int	remove_node(t_list **);
int	check_text(char *);
int	show_list(t_list **);
int	get_x_map(char *);
int	get_y_map(char *);
void	reverse_list(t_list **ll);
int	parse_board(t_cell **, t_solver_info, t_list **, char *);
int	display_resolution(t_cell **, t_solver_info *, t_list **);
int	find_path(t_cell **, t_solver_info *, t_list **);
int	solve(t_cell **, t_solver_info *, t_list **);
int	init_board(t_cell **, t_solver_info, t_list **, char **);
int	get_distance_between_cell(double, double, double, double);
#endif