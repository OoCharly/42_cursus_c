/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_rsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 11:27:12 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/20 17:30:46 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ls_by_rsize(void *new, void *old)
{
	off_t	size_old;
	off_t	size_new;

	size_old = ((t_info*)old)->i_stat->st_size;
	size_new = ((t_info*)new)->i_stat->st_size;
	if (size_old == size_new)
		return (ls_by_name(old, new));
	else if (size_old < size_new)
		return (-1);
	else
		return (1);
}

int	ls_by_ratime(void *new, void *old)
{
	struct timespec	time_old;
	struct timespec	time_new;

	time_old = ((t_info*)old)->i_stat->st_atimespec;
	time_new = ((t_info*)new)->i_stat->st_atimespec;
	if (time_old.tv_sec == time_new.tv_sec)
	{
		if (time_old.tv_nsec < time_new.tv_nsec)
			return (-1);
		else if (time_old.tv_nsec == time_new.tv_nsec)
			return (ls_by_name(old, new));
		else
			return (1);
	}
	else
		return (time_old.tv_sec - time_new.tv_sec);
}

int	ls_by_rmtime(void *new, void *old)
{
	struct timespec	time_old;
	struct timespec	time_new;

	time_old = ((t_info*)old)->i_stat->st_mtimespec;
	time_new = ((t_info*)new)->i_stat->st_mtimespec;
	if (time_old.tv_sec == time_new.tv_sec)
	{
		if (time_old.tv_nsec < time_new.tv_nsec)
			return (-1);
		else if (time_old.tv_nsec == time_new.tv_nsec)
			return (ls_by_name(old, new));
		else
			return (1);
	}
	else
		return (time_old.tv_sec - time_new.tv_sec);
}

int	ls_by_rctime(void *new, void *old)
{
	struct timespec	time_old;
	struct timespec	time_new;

	time_old = ((t_info*)old)->i_stat->st_birthtimespec;
	time_new = ((t_info*)new)->i_stat->st_birthtimespec;
	if (time_old.tv_sec == time_new.tv_sec)
	{
		if (time_old.tv_nsec < time_new.tv_nsec)
			return (-1);
		else if (time_old.tv_nsec == time_new.tv_nsec)
			return (ls_by_name(old, new));
		else
			return (1);
	}
	else
		return (time_old.tv_sec - time_new.tv_sec);
}

int	ls_by_rstime(void *new, void *old)
{
	struct timespec	time_old;
	struct timespec	time_new;

	time_old = ((t_info*)old)->i_stat->st_ctimespec;
	time_new = ((t_info*)new)->i_stat->st_ctimespec;
	if (time_old.tv_sec == time_new.tv_sec)
	{
		if (time_old.tv_nsec < time_new.tv_nsec)
			return (-1);
		else if (time_old.tv_nsec == time_new.tv_nsec)
			return (ls_by_name(old, new));
		else
			return (1);
	}
	else
		return (time_old.tv_sec - time_new.tv_sec);
}
