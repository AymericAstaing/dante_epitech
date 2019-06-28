/*
** EPITECH PROJECT, 2017
** get x map
** File description:
** get x of txt board
*/

#include	<lib.h>
#include	<stdlib.h>
#include	<math.h>
#include	<stdio.h>
#include	"../../../include/dante.h"

int	get_distance_between_cell(double x1, double y1, double x2, double y2)
{
	double		d1 = (x2 - x1) * (x2 - x1);
	double		d2 = (y2 - y1) * (y2 - y1);
	double		value = sqrt(d1 + d2);
	return (value);
}