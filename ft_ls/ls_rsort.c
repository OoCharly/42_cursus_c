/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_rsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 11:27:12 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/07 11:30:41 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ls_by_rsize(void *old, void *new)
{
	off_t	old;
	off_t	new;

	old = (t_info*)(old)->i_stat->st_size;
	new = (t_info*)(new)->i_stat->st_size;
	if (old = new)
		return (ls_by_name(old, new));
	else if (old < new)
		return (-1);
	else
		return (1);
}

int	ls_by_ratime(void *old, void *new)
{
	struct timespec	time_old;
	struct timespec	time_new;
	
	time_old = (t_info*)(old)->i_stat->st_atimespec;
	time_new = (t_info*)(new)->i_stat->st_atimespec;
	if (time_old->tv_sec == time_new->tv_sec)
	{
		if (time_old->tv_nsec < time_new->tv_nsec)
			return (-1);
		else if (time_old->tv_nsec == time_new->tv_nsec)
			return (ls_by_name(new, old));
		else
			return (1);
	}
	else
		return (time_old->tv_sec - time_new->tv_sec);
}

int	ls_by_rmtime(void *old, void *new)
{
	struct timespec	time_old;
	struct timespec	time_new;
	
	time_old = (t_info*)(old)->i_stat->st_mtimespec;
	time_new = (t_info*)(new)->i_stat->st_mtimespec;
	if (time_old->tv_sec == time_new->tv_sec)
	{
		if (time_old->tv_nsec < time_new->tv_nsec)
			return (-1);
		else if (time_old->tv_nsec == time_new->tv_nsec)
			return (ls_by_name(new, old));
		else
			return (1);
	}
	else
		return (time_old->tv_sec - time_new->tv_sec);
}

int	ls_by_rctime(void *old, void *new)
{
	struct timespec	time_old;
	struct timespec	time_new;
	
	time_old = (t_info*)(old)->i_stat->st_birthtimespec;
	time_new = (t_info*)(new)->i_stat->st_birthtimespec;
	if (time_old->tv_sec == time_new->tv_sec)
	{
		if (time_old->tv_nsec < time_new->tv_nsec)
			return (-1);
		else if (time_old->tv_nsec == time_new->tv_nsec)
			return (ls_by_name(new, old));
		else
			return (1);
	}
	else
		return (time_old->tv_sec - time_new->tv_sec);
}

int	ls_by_rstime(void *old, void *new)
{
	struct timespec	time_old;
	struct timespec	time_new;
	
	time_old = (t_info*)(old)->i_stat->st_ctimespec;
	time_new = (t_info*)(new)->i_stat->st_ctimespec;
	if (time_old->tv_sec == time_new->tv_sec)
	{
		if (time_old->tv_nsec < time_new->tv_nsec)
			return (-1);
		else if (time_old->tv_nsec == time_new->tv_nsec)
			return (ls_by_name(new, old));
		else
			return (1);
	}
	else
		return (time_old->tv_sec - time_new->tv_sec);
}