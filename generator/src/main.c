/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** task01
*/

#include	"lib.h"
#include	<stdlib.h>
#include	<time.h>
#include	<string.h>
#include	<stdio.h>
#include	"../include/linked.h"
#include	"../include/generator.h"
#include	"../../include/dante.h"

int	check_params(char *arg1, char *arg2)
{
	if (arg1 == NULL || arg2 == NULL)
		return (ERROR);
	if (my_getnbr(arg1) < 1 || my_getnbr(arg2) < 1)
		return (ERROR);
	return (SUCCESS);
}

int	init_generator(t_cell ***map, t_game_info **g_i, char *x, char *y)
{
	if (!g_i)
		return (ERROR);
	(*g_i)->x_map = my_getnbr(x);
	(*g_i)->y_map = my_getnbr(y);
	if ((is_odd(my_getnbr(x))) && (is_odd(my_getnbr(y))))
		(*g_i)->odd_map = 1;
	else
		(*g_i)->odd_map = 0;
	(*map) = (t_cell **)malloc(sizeof(t_cell *) * (*g_i)->y_map);
	if (!map)
		return (ERROR);
	for (int i = 0; i < (*g_i)->y_map; i++) {
		(*map)[i] = (t_cell *)malloc(sizeof(t_cell) *
		(*g_i)->x_map);
		if (!(*map)[i])
			return (ERROR);
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_list		*history = NULL;
	t_cell		**map = NULL;
	t_game_info	*game_info = malloc(sizeof(t_game_info));

	srand(time(NULL));
	if (argc < 3 || check_params(argv[1], argv[2]) == ERROR)
		return (CEXITERROR);
	if (!(init_generator(&map, &game_info, argv[1], argv[2])))
		return (CEXITERROR);
	if (argc == 4 && strcmp(argv[3], "perfect") == 0)
		game_info->perfect = 1;
	else
		game_info->perfect = 0;
	if (!(init_board((&(*map)), *game_info, &history)))
		return (CEXITERROR);
	generate((&(*map)), *game_info, &history);
	remove_wall((game_info->x_map * game_info->y_map) - 1,
	game_info->x_map, (&(*map)));
	display_board((&(*map)), *game_info);
	destroy_settings((&(*map)), game_info, &history);
	return (CEXITSUCCESS);
}