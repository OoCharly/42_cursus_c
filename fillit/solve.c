/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 18:51:56 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/30 10:51:53 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		xor_tetros(int x, int y, char **tet, t_grid *grid)
{
	int		i;
	int		j;
	int		n;

	n = 0;
	i = 0;
	while (i < 4 && n < 4 && (i + y) < grid->len)
	{
		j = 0;
		while (j < 4 && (j + x) < grid->len)
		{
			if (grid->tab[i + y][j + x] != '.' || tet[i][j])
			{
				if ((grid->tab[i + y][j + x] != '.')
						&& tet[i][j])
					return (0);
				else if (tet[i][j])
					n++;
			}
			j++;
		}
		i++;
	}
	return ((n == 4) ? 1 : 0);
}

void	place_piece(int current, int *c, t_tetros *tetros, t_grid *grid)
{
	int		i;
	int		j;
	int		n;

	n = 0;
	i = 0;
	while (n < 4 && (i + c[1]) < grid->len)
	{
		j = 0;
		while (j < 4 && (j + c[0]) < grid->len)
		{
			if (tetros->tets[current][i][j])
			{
				n++;
				grid->tab[i + c[1]][j + c[0]] = 'A' + current;
			}
			j++;
		}
		i++;
	}
}

void	erase_piece(int current, int x, int y, t_grid *grid)
{
	int		i;
	int		j;
	int		n;

	n = 0;
	i = 0;
	while (n < 4 && (i + y) < grid->len)
	{
		j = 0;
		while (j < 4 && (j + x) < grid->len)
		{
			if (grid->tab[i + y][j + x] == ('A' + current))
			{
				n++;
				grid->tab[i + y][j + x] = '.';
			}
			j++;
		}
		i++;
	}
}

int		find_place(int *c, int current, t_tetros *tetros, t_grid *grid)
{
	while (!xor_tetros(c[0], c[1], tetros->tets[current], grid))
	{
		c[0]++;
		if (c[0] == grid->len)
		{
			c[1]++;
			c[0] = 0;
			if (c[1] == grid->len)
				return (0);
		}
	}
	return (1);
}

int		place(int current, t_tetros *tetros, t_grid *grid)
{
	int	coor[2];

	coor[0] = 0;
	coor[1] = 0;
	if (current == tetros->tot)
		return (1);
	while (coor[0] < (grid->len) && coor[1] < (grid->len))
	{
		if (!find_place(coor, current, tetros, grid))
		{
			return (0);
		}
		place_piece(current, coor, tetros, grid);
		if (place(current + 1, tetros, grid))
			return (1);
		else
		{
			erase_piece(current, coor[0], coor[1], grid);
			coor[0] = (++coor[0] == grid->len) ? 0 : coor[0];
			coor[1] += (coor[0] == 0) ? 1 : 0;
		}
	}
	return (0);
}
