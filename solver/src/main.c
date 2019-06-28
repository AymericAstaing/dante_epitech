/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** task01
*/

#include	"../include/solver.h"
#include	"../../include/dante.h"
#include	<stdlib.h>
#include	"lib.h"

int	init_solver(t_cell ***map, t_solver_info **s_info, char *filename)
{
	if (!s_info)
		return (ERROR);
	(*s_info)->x_map = get_x_map(filename);
	(*s_info)->y_map = get_y_map(filename);
	(*map) = (t_cell **)malloc(sizeof(t_cell *) * (*s_info)->y_map);
	if (!map)
		return (ERROR);
	for (int i = 0; i < (*s_info)->y_map; i++) {
		(*map)[i] = (t_cell *)malloc(sizeof(t_cell) *
		(*s_info)->x_map);
		if (!(*map)[i])
			return (ERROR);
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_list		*path = NULL;
	t_cell		**map = NULL;
	t_solver_info	*solver_info = malloc(sizeof(t_solver_info));

	if (argc < 2)
		return (CEXITERROR);
	if (check_text(argv[1]) == ERROR)
		return (CEXITERROR);
	if (init_solver(&map, &solver_info, argv[1]) == ERROR)
		return (CEXITERROR);
	if (parse_board((&(*map)), *solver_info, &path, argv[1]) == ERROR)
		return (CEXITERROR);
	solve((&(*map)), solver_info, &path);
	destroy_settings((&(*map)), solver_info, &path);
	return (CEXITSUCCESS);
}