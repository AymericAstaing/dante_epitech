/*
** EPITECH PROJECT, 2018
** Dante
** File description:
** Generator header
*/

#ifndef GENERATOR_H_
	#define GENERATOR_H_

typedef	struct	s_cell		t_cell;
typedef	struct	s_game_info	t_game_info;

struct s_cell
{
	int passed;
	char value;
	int *neighbour;
};

struct s_game_info
{
	int x_map;
	int y_map;
	int perfect;
	int odd_map;
};

int	create_imperfect_board(t_cell **map, t_game_info game_info);
int	init_board(t_cell **map, t_game_info game_info, t_list **list);
int	change_cell(int, int, t_cell **map, t_list **list);
int	remove_wall(int, int, t_cell **map);
int	get_malloced_struct(t_cell **map, t_game_info game_info);
int	generate(t_cell **map, t_game_info g_info, t_list **list);
int	display_board(t_cell **map, t_game_info game_info);
int	is_odd(int n);
int	destroy_settings(t_cell **map, t_game_info *game_info, t_list **);

#endif