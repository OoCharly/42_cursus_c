/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_gets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 17:07:05 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/08 18:42:00 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_usr(t_stat st)
{
	t_pwd	*pwd;
	char	*out;

	pwd = getpwuid(st->st_uid);
	if(!(out = ft_strdup(pwd->pw_name)))
		exit(2);
	return (out);
}

char	*get_grp(t_stat st)
{
	t_grp	*grp;
	char	*out;

	grp = getgrgid(st->st_gid);
	if(!(out = ft_strdup(grp->gr_name)))
		exit(2);
	return (out);
}

char	*get_size(t_stat st, int flag)
{
	mode_t	mode;
	rdev_t	rdev;
	char	*out;

	mode = st->st_mode;
	if (S_ISCHR(mode) || S_ISBLK(mode))
	{
		if(!(out = ft_memalloc(sizeof(char) * 13)))
			exit (2);
		rdev = st->st_rdev;
		ft_strfcat(out, ft_ntoa_base((uintmax_t)minor(rdev), 10));
		ft_strcat(out, ", ");
		ft_strfcat(out, ft_ntoa_base((uintmax_t)major(rdev), 10));
	}
	else
		out = ft_ntoa_base((uintmax_t)st->size, 10);
	return (out);
}

char	*get_date(t_stat st, int flag)
{
	time_t	time;
	time_t	now;
	char	*out;
	char	*tmp;

	if (flag & BY_ATIME)
		time = (time_t)(st->st_mtimespec.tv_sec);
	else if (flag & BY_CTIME)
		time = (time_t)(st->st_birthtimespec.tv_sec);
	else if (flag & BY_STIME)
		time = (time_t)(st->st_stimespec.tv_sec);
	else
		time = (time_t)(st->st_mtimespec.tv_sec);
	if (flag & OPT_WTIME)
	{
		tmp = ctime(time);
		out = ft_strdup(tmp + 4);
	}
	else
	{
		tmp = ctime(time);
		if(!(out = ft_memalloc(sizeof(char) * 13)))
			exit(2);
		ft_memcpy(out, tmp + 4, 7);
		now = time(NULL);
		((now - time) > SIX_MONTH) ? ft_strcat(out, tmp + 20) : ft_memcpy(out + 7, tmp + 11, 5);
			ft_strcat(out, tmp + 20);
		else
			ft_memcpy(out + 7, tmp + 11, 5);
	}
	return (out);
}
	
