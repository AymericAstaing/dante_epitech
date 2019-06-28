/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** PSU_minishell1_2018
*/

#include	"stdlib.h"
#include	"unistd.h"
#include	"../../include/dante.h"
#include	"lib.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}
