/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 18:37:49 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/26 14:08:24 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_tetros(char *buff, int p, t_tetros *tetros)
{
	int	i;
	int	n;

	n = 0;
	i = -1;
	while (buff[++i] && (i / 5 != 4))
	{
		while (((i % 5) != 4) && buff[i])
		{
			if (buff[i] == '#')
			{
				tetros->tets[p][i / 5][i % 5] = 'A' + p;
				i++;
				n++;
			}
			else if (buff[i] == '.')
				i++;
			else
				return (0);
		}
		if (buff[i] != '\n')
			return (0);
	}
	return ((n == 4) ? i : 0);
}

int		get_tetros(char *buff, int n, t_tetros *tetros)
{
	int	i;
	int	p;
	int a;

	i = -1;
	p = 0;
	while (i++ < n)
	{
		a = check_tetros(&buff[i], p, tetros);
		if (a < 20)
			return (0);
		i += a;
		if (buff[i] != '\n' && buff[i] != '\0')
			return (0);
		if (!get_cohesion(p, tetros))
			return (0);
		p++;
	}
	return (i);
}

int		read_fillit(int fd, char *buff, t_tetros *tetros)
{
	int	a;
	int	n;

	n = read(fd, buff, 600);
	if (n < 20 || n > 545)
		return (0);
	a = n / 20;
	if (a > 20)
		a--;
	if ((a * 20) + (a - 1) != n)
		return (0);
	else
	{
		buff[n] = '\0';
		tetros->tot = a;
		return (n);
	}
}
