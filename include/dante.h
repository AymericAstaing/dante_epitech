/*
** EPITECH PROJECT, 2018
** Dante
** File description:
** Dante General header
*/

#ifndef DANTE_H_
#define DANTE_H_

static const int	CEXITSUCCESS = 1;
static const int	CEXITERROR = 84;
static const char	END = '\0';
static const char	NEWLINE = '\n';
static const char	LESS = '-';

enum		ret_state {
	ERROR = 0,
	SUCCESS
};

enum		value_cell {
	WALL = 'X',
	FREE_CELL = '*'
};

enum		bool_odd {
	FALSE = 0,
	TRUE
};

enum		coor_cell {
	N = 0,
	S,
	E,
	W
};

#endif
