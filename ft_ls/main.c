/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 16:14:48 by cdesvern          #+#    #+#             */
/*   Updated: 2016/08/31 18:25:09 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

pcmp	get_cmpfunction(unsigned int flag)
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
		return ((flag & OPT_REV) ? $ls_by_rname : &ls_by_name);
}

int		parse_options(char ch, unsigned int *flag)
{ 
	if (ch == 't')
		*flag |= BY_MTIME;
	else if (ch == 'l')
		*flag = (*flag | OPT_LNG) & ~OPT_GRP;
	else if (ch == 'R' && !(*flag & OPT_DIR))
		*flag |= OPT_REC;
	else if (ch == 'a')
		*flag |= OPT_ALL;
	else if (ch == 'r')
		*flag |= OPT_REV;
	else if (ch == 'd')
		*flag = (flag | OPT_DIR) & ~OPT_REC;
	else if (ch == 't')
		*flag |= BY_TIME;
	else if (ch == 'S')
		*flag |= BY_SIZE;
	else
		return (-1);
	return (0);
}

int		get_options(int ac, char **av, unsigned int *flag)
{
	unsigned int		i;
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
					ft_printf("%c\n", ch);
					return (usage());
				}
		}
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		flag;
	t_pcmp	mastercmp;
	t_util	util;

	flag = 0;
	get_options(ac, av, &flag);
	mastercmp = get_cmpfunction(flag);
	util = get_util(flag, mastercmp);


	return (0);
}
