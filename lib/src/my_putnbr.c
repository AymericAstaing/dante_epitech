/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** lib
*/

#include	"stdlib.h"
#include	"../../include/dante.h"
#include	"lib.h"

void	my_putnbr(int nb)
{
	int	debut;
	int	fin;

	if (nb < 0) {
		my_putchar('-');
		my_putnbr(-nb);
	} else {
		fin = nb % 10;
		debut = nb / 10;
		if (debut != 0)
			my_putnbr(debut);
		my_putchar(fin + '0');
	}
}
