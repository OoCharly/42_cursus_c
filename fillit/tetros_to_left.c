/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetros_to_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 18:38:39 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/30 10:50:10 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_empty_lines(int p, t_tetros *tetros)
{
	int	i;
	int	l;

	i = -1;
	l = 0;
	while (i++ < 15)
	{
		while (i % 5 != 4)
		{
			if (tetros->tets[p][i / 5][i % 5])
				return (l);
			i++;
		}
		l++;
	}
	return (l);
}

int		get_empty_columns(int p, t_tetros *tetros)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (i++ < 15)
	{
		while (i % 5 != 4)
		{
			if (tetros->tets[p][i % 5][i / 5])
				return (c);
			i++;
		}
		c++;
	}
	return (c);
}

void	move_left(int p, int c, t_tetros *tetros)
{
	int	i;
	int	j;

	j = 0;
	while (c != 4)
	{
		i = 0;
		while (i < 4)
		{
			tetros->tets[p][i][j] = tetros->tets[p][i][c];
			i++;
		}
		j++;
		c++;
	}
	i = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
			tetros->tets[p][i++][j] = '\0';
		j++;
	}
}

void	move_up(int p, int l, t_tetros *tetros)
{
	int	i;
	int	j;

	j = 0;
	while (l != 4)
	{
		i = 0;
		while (i < 4)
		{
			tetros->tets[p][j][i] = tetros->tets[p][l][i];
			i++;
		}
		j++;
		l++;
	}
	while (j < 4)
	{
		i = 0;
		while (i < 4)
			tetros->tets[p][j][i++] = '\0';
		j++;
	}
}

int		rearrange_tetros(t_tetros *tetros)
{
	int	l;
	int	p;

	p = 0;
	while (p < tetros->tot)
	{
		l = get_empty_columns(p, tetros);
		if (l)
			move_left(p, l, tetros);
		l = get_empty_lines(p, tetros);
		if (l)
			move_up(p, l, tetros);
		p++;
	}
	return (1);
}
