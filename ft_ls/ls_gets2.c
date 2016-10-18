/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_gets2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 17:20:36 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/18 18:04:26 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_color_offset(mode_t mode)
{
	if ((S_IFDIR & mode))
	{
		if ((S_IWOTH & mode))
			return (((S_ISVTX & mode) ? 18 : 20));
		return (0);
	}
	else if ((S_IXOTH & mode) | (S_IXUSR & mode) | (S_IXGRP & mode))
	{
		if ((S_ISGID & mode) | (S_ISGID & mode))
			return (((S_ISUID & mode) ? 14 : 16));
		return (8);
	}
	if (S_ISLNK(mode))
		return (2);
	if (S_ISSOCK(mode))
		return (4);
	if (S_ISFIFO(mode))
		return (6);
	if (S_ISBLK(mode))
		return (10);
	if (S_ISCHR(mode))
		return (12);
	return (-1);
}

static char	*fmt_color(char s)
{
	if (s == 'x')
		return (COL_DEF);
	if (s == 'a')
		return (COL_BLK);
	if (s == 'b')
		return (COL_RED);
	if (s == 'c')
		return (COL_GRN);
	if (s == 'd')
		return (COL_BRW);
	if (s == 'e')
		return (COL_BLU);
	if (s == 'f')
		return (COL_MAG);
	if (s == 'g')
		return (COL_CYA);
	if (s == 'h')
		return (COL_LGR);
	return (NULL);
}

char	*get_suff(mode_t mode, int flag)
{
	if (S_ISDIR(mode))
		return ("/");
	if (flag & OPT_SUF)
	{
		if (S_ISLNK(mode))
			return ("@");
		if (S_ISSOCK(mode))
			return ("=");
		if (S_ISWHT(mode))
			return ("%");
		if (S_ISFIFO(mode))
			return ("|");
		if ((S_IXUSR & mode) | (S_IXGRP & mode) | (S_IXOTH & mode))
			return ("*");
	}
	return ("");
}

char	*get_color(t_stat *stat, char *lscol)
{
	char	*out;
	int		i;

	(out = ft_memalloc(sizeof(char) * 12)) ? : exit(2);
	i = get_color_offset(stat->st_mode);
	if (i == -1)
		return (out);
	ft_strcat(out, "\e[");
	if (*(lscol + i) < 'a')
		ft_strcat(out, "1");
	ft_strcat(out, fmt_color(ft_tolower(*(lscol + i))));
	ft_strcat(out, fmt_color(ft_tolower(*(lscol + i + 1))));
	out[ft_strlen(out) - 2]++;
	ft_strcat(out, "m");
	return(out);
}
