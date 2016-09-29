/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_prelim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:47:53 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/29 16:01:48 by cdesvern         ###   ########.fr       */
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
		return ((flag & OPT_REV) ? &ls_by_rname : &ls_by_name);
}

static int		parse_options(char ch, int *flag)
{
	if (ch == 't')
		*flag |= BY_TIME;
	else if (ch == 'l')
		*flag = (*flag | OPT_LNG) & ~OPT_SCOL;
	else if (ch == 'R' && !(*flag & OPT_DIR))
		*flag |= OPT_REC;
	else if (ch == 'a')
		*flag |= OPT_ALL;
	else if (ch == 'r')
		*flag |= OPT_REV;
	else if (ch == 'd')
		*flag = (*flag | OPT_DIR) & ~OPT_REC;
	else if (ch == 'S')
		*flag |= BY_SIZE;
	else if (ch == '1')
		*flag = (*flag | OPT_SCOL) & (~OPT_LNG);
	else if (ch == 's')
		*flag |= OPT_BLK;
	else if (ch == 'f')
		*flag |= NO_SORT;
	else if (ch == 'g')
		*flag |= (OPT_GRP | OPT_LNG);
	else if (ch == 'i')
		*flag |= (OPT_INO);
	else if (ch == 'p')
		*flag |= OPT_SLH;
	else if (ch == 'F')
		*flag |= OPT_SUF;
	else if (ch == 'C')
		*flag &= (~OPT_LNG & ~OPT_SCOL);
	else if (ch == 'U')
		*flag = (*flag | BY_CTIME) & (~BY_ATIME & ~BY_STIME);
	else if (ch == 'u')
		*flag = (*flag | BY_ATIME) & (~BY_CTIME & ~BY_STIME);
	else if (ch == 'c')
		*flag = (*flag | BY_STIME) & (~BY_ATIME & ~BY_CTIME);
	else if (ch == 'T')
		*flag |= OPT_WTIME;
	else
		return (ch);
	return (0);
}

static int		get_options(int ac, char **av, int *flag)
{
	int		i;
	char	*opt;
	char	ch;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1])
		{
			if (av[i][1] == '-' && !av[i][2])
				return (i + 1);
			opt = av[i];
			while (*++opt)
				if ((ch = parse_options(*opt, flag)))
				{
					ft_putstr_fd("ls: illegal option -- ", 2);
					ft_putchar_fd(ch, 2);
					ft_putendl("");
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
	if ((out = get_options(ac, av, &flag)) < 0)
		exit(2);
	mastercmp = get_cmpfunction(flag);
	get_util(flag, mastercmp, util);
	return (out);
}
