/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 15:36:07 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/01 18:12:36 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void	ls_erase_last_name(char *path, size_t len)
{
	char	*slash;

	slash = ft_strrchr(path, '/');
	ft_memset(tar + 1, 0, len);
}

t_info	*get_info(char *path, t_dirent *tdir, t_util *util)
{
	t_info	*out;
	t_stat	*stat;

	(out = malloc(sizeof(t_info))) ? : return (NULL);
	out->i_dirent = tdir;
	if (util->fstat)
	{
		if(!(stat = malloc(sizeof(t_stat))))
			return (NULL);
		out->i_stat = (*(util->getstat))(path, stat);
	}
	else
		out->i_stat = NULL;
	return (out);
}

int		get_list(char *path, DIR *dir, t_util *util, t_list **plst)
{
	t_list		*new;
	t_dirent	*tdir;
	t_info		*info;
	t_pcmp		cmp;

	cmp = util->cmp;
	while ((tdir = readdir(dir)))
	{
		path = ft_strcat(path, tdir->d_name);
		if(!(info = get_info(path, tdir, util)))
			return (2);
		if (!(new = ft_lstnew(info, sizeof(*info))))
			return (2);
		ft_lstsort(plst, new, cmp);
		ls_erase_last_name(path, (size_t)tdir->d_namlen);
	}
	return (0);
}
