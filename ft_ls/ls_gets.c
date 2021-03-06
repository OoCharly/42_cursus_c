/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_gets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 17:07:05 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/19 20:33:58 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_usr(t_stat *st)
{
	t_pwd	*pwd;
	char	*out;

	if (!st)
	{
		if (!(out = ft_memalloc(sizeof(char))))
			exit(2);
	}
	else
	{
		pwd = getpwuid(st->st_uid);
		if (!(out = ft_strdup(pwd->pw_name)))
			exit(2);
	}
	return (out);
}

char	*get_grp(t_stat *st)
{
	t_grp	*grp;
	char	*out;

	if (!st)
	{
		if (!(out = ft_memalloc(sizeof(char))))
			exit(2);
	}
	else
	{
		grp = getgrgid(st->st_gid);
		if (!(out = ft_strdup(grp->gr_name)))
			exit(2);
	}
	return (out);
}

char	*get_size(t_stat *st)
{
	mode_t	mode;
	dev_t	rdev;
	char	*out;
	int		d;

	mode = st->st_mode;
	if (S_ISCHR(mode) || S_ISBLK(mode))
	{
		if (!(out = ft_memalloc(sizeof(char) * 8)))
			exit(2);
		rdev = st->st_rdev;
		ft_strfcat(out, ft_ntoa_base((uintmax_t)major(rdev), 10));
		d = 3 - ft_strlen(out);
		ft_memmove(out + d, out, 3 - d);
		ft_memset(out, ' ', d);
		ft_strcat(out, ", ");
		ft_strfcat(out, ft_ntoa_base((uintmax_t)minor(rdev), 10));
		d = 3 - (ft_strlen(out) - 5);
		ft_memmove(out + 5 + d, out + 5, 3 - d);
		ft_memset(out + 5, ' ', d);
	}
	else
		out = ft_ntoa_base((uintmax_t)st->st_size, 10);
	return (out);
}

time_t	get_time(t_stat *st, int flag)
{
	time_t	time;

	if (flag & BY_ATIME)
		time = (time_t)(st->st_atimespec.tv_sec);
	else if (flag & BY_CTIME)
		time = (time_t)(st->st_birthtimespec.tv_sec);
	else if (flag & BY_STIME)
		time = (time_t)(st->st_ctimespec.tv_sec);
	else
		time = (time_t)(st->st_mtimespec.tv_sec);
	return (time);
}

char	*get_date(t_stat *st, int flag)
{
	time_t	stime;
	time_t	now;
	char	*out;
	char	*tmp;
	char	*yolo;

	stime = get_time(st, flag);
	tmp = ctime(&stime);
	yolo = ft_strtrim(tmp + 19);
	if (flag & OPT_WTIME)
		out = ft_strndup(tmp + 4, ft_strlen(tmp + 4) - 1);
	else
	{
		if (!(out = ft_memalloc(sizeof(char) * 15)))
			exit(2);
		ft_memcpy(out, tmp + 4, 7);
		now = time(NULL);
		if ((now - stime) > SIX_MONTH || (now - stime) < -SIX_MONTH)
			ft_strcat(ft_strcat(out + ft_strlen(out), " "), yolo);
		else
			ft_memcpy(out + 7, tmp + 11, 5);
	}
	free(yolo);
	return (out);
}
