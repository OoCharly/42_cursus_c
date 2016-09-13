/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_prelim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:47:53 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/13 17:33:07 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_pcmp	get_cmpfunction(int flag)
{
	if (flag & NO_SORT)
		return (NULL);
	else if (flag & BY_SIZE)
		return ((flag & OPT_REV) ? &ls_by_rsize : &ls_by_size);
	else if (flag & BY_TIME)
	{
		if (flag & BY_ATIME)
			return ((flag & OPT_REV) ? &ls_by_ratime : &ls_by_atime);
		else if (flag & BY_STIME)
			return ((flag & OPT_REV) ? &ls_by_rstime : &ls_by_stime);
		else if (flag & BY_CTIME)
			return ((flag & OPT_REV) ? &ls_by_rctime : &ls_by_ctime);
		else
			return ((flag & OPT_REV) ? &ls_by_rmtime : &ls_by_mtime);
	}
	else
	{
		ft_putendl("sort_by_name");
		return ((flag & OPT_REV) ? &ls_by_rname : &ls_by_name);
	}
}

static int		parse_options(char ch, int *flag)
{
	int	tmp;

	tmp = *flag;
	if (ch == 't')
		tmp |= BY_TIME;
	else if (ch == 'l')
		tmp = (tmp | OPT_LNG) & ~OPT_GRP;
	else if (ch == 'R' && !(tmp & OPT_DIR))
		tmp |= OPT_REC;
	else if (ch == 'a')
		tmp |= OPT_ALL;
	else if (ch == 'r')
		tmp |= OPT_REV;
	else if (ch == 'd')
		tmp = (tmp | OPT_DIR) & ~OPT_REC;
	else if (ch == 't')
		tmp |= BY_TIME;
	else if (ch == 'S')
		tmp |= BY_SIZE;
	else
		return (-1);
	*flag = tmp;
	return (0);
}

static int		get_options(int ac, char **av, int *flag)
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
				if (parse_options(*opt, flag))
				{
					perror("ls: illegal option -- ");
					return (usage());
				}
		}
		else
			return (i);
		i++;
	}
	return (i);
}

int				ls_prelim(int ac, char **av, t_util *util)
{
	int		flag;
	t_pcmp	mastercmp;
	int		out;

	flag = 0;
	if((out = get_options(ac, av, &flag)) < 0)
		exit (2);
	mastercmp = get_cmpfunction(flag);
	get_util(flag, mastercmp, util);
	return (out);
}

