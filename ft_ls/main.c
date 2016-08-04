/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 16:14:48 by cdesvern          #+#    #+#             */
/*   Updated: 2016/07/30 23:53:09 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	parse_options(char *opt, t_flag *flag)
{


int	get_options(char **av, int ac, t_flag *flag)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			if ((parse_options(av[i], flag)) < 0)
				return (1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	*path;

	if (!(path = ft_memalloc(sizeof(char) * _POSIX_PATH_MAX)))
	{
		perrror(errno);
		return (-2);
	}
	if
