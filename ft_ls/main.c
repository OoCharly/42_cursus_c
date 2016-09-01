/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 16:14:48 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/01 18:12:39 by cdesvern         ###   ########.fr       */
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
		else
			return (i);
		i++;
	}
	return (i);
}

int		ls_prelim(int ac, char **av, t_util *util)
{
	int		flag;
	t_pcmp	mastercmp;
	int		out;

	flag = 0;
	if(!(out = get_options(ac, av, &flag)))
		return (0);
	mastercmp = get_cmpfunction(flag);
	if(!(util = get_util(flag, mastercmp)))
		return (0);
	return (out);
}

int		main(int ac, char **av)
{
	t_util	util;
	char	*path;
	int		out;
	DIR		*dir;

	if (!(path = ft_memalloc(sizeof(char) * _POSIX_PATH_MAX)))
		return (2);
	if (!(out = ls_prelim(ac, av)))
		return (2);
	if (ac == out)
	{
		ft_strcat(path, ".");
		if(!(dir = opendir(path)))
			perror(errno);
		out = ft_ls(path, dir, util);
	}
	else
		out = ls_multi_arg(av + out, path, util);
	 



		
	
