/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 16:14:48 by cdesvern          #+#    #+#             */
/*   Updated: 2016/08/24 18:49:13 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	parse_options(char ch, t_flag *flag)
{ 
		if (ch == 't')
			flag->f_mtimesort = 1;
		else if (ch == 'l')
		{
			flag->f_longform = 1;
			flag->f_grouponly = -1;
		}
		else if (ch == 'R' && !flag->f_listdir)
			flag->f_recursive = 1;
		else if (ch == 'a')
			flag->f_listdot = 1;
		else if (ch == 'r')
			flag->f_reversesort = 1;
		else if (ch == 'd')
		{
			flag->f_listdir = 1;
			flag->f_recursive = 0;
		}
		else
			return (-1);
		return (0);
}

int	get_options(char **av, int ac, t_flag *flag)
{
	int		i;
	char	*opt;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			opt = av[i];
			while (*++opt)
				if (parse_options(*opt, flag));
						return (usage(errno));
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	return (0);
}
