/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_em_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 10:06:13 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/04 11:17:33 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_grid(t_grid *grid)
{
	int	i;

	i = 0;
	while (i < 52)
	{
		free(grid->tab[i]);
		i++;
	}
	free(grid->tab);
	free(grid);
}

void	free_tetros(t_tetros *tetros)
{
	int	j;
	int	p;

	p = 0;
	while (p < tetros->tot)
	{
		j = 0;
		while (j < 4)
		{
			free(tetros->tets[p][j]);
			j++;
		}
		free(tetros->tets[p]);
		p++;
	}
	free(tetros->tets);
}
