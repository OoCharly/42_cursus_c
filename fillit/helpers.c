/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 18:36:33 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/26 14:08:29 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		usage(int ac)
{
	if (ac == 0)
	{
		ft_putstr("fillit: missing file operand\n");
		return (0);
	}
	else
	{
		ft_putstr("fillit: too musch argument\n./fillit FILE\n");
		return (0);
	}
}

void	init_tets(char *s)
{
	int	i;

	i = 0;
	while (i < 4)
		s[i++] = '\0';
}

char	***ft_triplemalloc(int i_max)
{
	int		i;
	int		y;
	char	***s;

	i = 0;
	if (!(s = (char ***)malloc(sizeof(char **) * (i_max + 1))))
		return (NULL);
	while (i < i_max)
	{
		y = 0;
		if (!(s[i] = (char **)malloc(sizeof(char *) * 4)))
			return (NULL);
		while (y < 4)
		{
			if (!(s[i][y] = (char *)malloc(sizeof(char) * 4)))
				return (NULL);
			init_tets(s[i][y]);
			y++;
		}
		i++;
	}
	s[i_max] = NULL;
	return (s);
}

int		ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_pow(nb, power - 1));
}
