/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_gets2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 17:20:36 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/29 19:26:01 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_color_offset(mode_t mode)
{
	if (S_IFDIR(mode))
	{
		if (S_ISWOTH(mode))
			return ((S_ISVTX(mode)) ? 18 : 20);
		return (0);
	}
	else if (S_IXOTH(mode) | S_IXUSR(mode) | S_IXGRP(mode))
	{
		if (S_ISGID(mode) | S_ISGID(mode))
			return ((S_ISUID(mode)) ? 14 : 16);
		return (8);
	}
	(!S_IFLNK(mode)) ? : return (2);
	(!S_IFSOCK(mode)) ? : return (4);
	(!S_IFIFO(mode)) ? : return (6);
	(!S_IFBLK(mode)) ? : return (10);
	(!S_IFCHR(mode)) ? : return (12);
	return (-1);
}

static char	*fmt_bcolor(char s)
{
	!(s == 'x') ? : return (BCOL_DEF);
	!(s == 'a') ? : return (BCOL_BLK);
	!(s == 'b') ? : return (BCOL_RED);
	!(s == 'c') ? : return (BCOL_GRN);
	!(s == 'd') ? : return (BCOL_BRW);
	!(s == 'e') ? : return (BCOL_BLU);
	!(s == 'f') ? : return (BCOL_MAG);
	!(s == 'g') ? : return (BCOL_CYA);
	!(s == 'h') ? : return (BCOL_LGR);
	return (NULL);
}

static char	*fmt_color(char s)
{
	!(s == 'x') ? : return (COL_DEF);
	!(s == 'a') ? : return (COL_BLK);
	!(s == 'b') ? : return (COL_RED);
	!(s == 'c') ? : return (COL_GRN);
	!(s == 'd') ? : return (COL_BRW);
	!(s == 'e') ? : return (COL_BLU);
	!(s == 'f') ? : return (COL_MAG);
	!(s == 'g') ? : return (COL_CYA);
	!(s == 'h') ? : return (COL_LGR);
	return (NULL);
}

char	get_suff(mode_t mode, int flag)
{
	if (flag & (OPT_SUF | OPT_SLH))
	{
		if (S_IFDIR(mode))
			return ('/');
		if (flag & OPT_SUF)
		{
			if (S_IFLNK(mode))
				return ('@');
			if (S_IFSOCK(mode))
				return ('=');
			if (S_IFWHT(mode))
				return ('%');
			if (S_IFIFO(mode))
				return ('|');
			if (S_IXUSR(mode) | S_IXGRP(mode) | S_IXOTH(mode))
				return ('*');
		}
	}
	return (0);
}

char	*get_ino(t_stat *stat)
{
	char	*out;

	if (!stat)
	{
		(out = ft_memalloc(0)) ? : exit(2);
		return (out);
	}
	out = ft_ntoa((uintmax_t)stat->st_ino, 10);
	return (out);
}

char	*get_color(t_stat *stat, char *lcol)
{
	char	*out;
	int		i;

	(out = ft_memalloc(sizeof(char) * 12)) ? : exit(2);
	i = get_col_offset(stat->st_mode);
	if (i == -1)
		return (out);
	ft_strcat(out, "\e[");
	if (*(lcol + i) <= 'a')
		ft_strcat(out, "1;");
	ft_strcat(out, fmt_color(*(lscol + i)));
	ft_strcat(out, fmt_bcolor(*(lscol + i + 1)));
	return(out);
}
