/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 12:26:11 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/01 14:01:27 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_del_node(t_info *info, size_t size)
{
	if(info->i_stat)
	{
		free(info->i_stat);
		info->i_stat = NULL;
	}
	free(info);
}

DIR		*ls_next_dir(char *path, t_lst **plst, int *out)
{
	DIR 		*ret;
	t_dirent	*tdir;

	tdir = (*plst)->content->i_dirent;
	path = memcpy(path + ft_strlen(path), tdir->d_name, (size_t)tdir->d_namlen);
	if (ret = opendir(path))
		return (ret);
	else
	{
		path = ls_erase_last_name(path, (size_t)tdir->d_namlen);
		if (errno != 20)
		{
			perror(errno);
			*out = 1;
			return (NULL);
		}
		else
			return (NULL);
	}
}

int		ft_ls(char *path, DIR *dir, t_util *util)
{
	t_list		**plst;
	int			out;

	*(path + ft_strlen(path)) = '/';
	if (!(plst = ft_lstpnew(NULL, 0)))
		return (2);
	out = get_list(path, dir, util, plst);
	util->flag |= (out == 2) ? BIG_ERR : 0;
	closedir(dir);
	ls_print(plst);
	if ((util->flag & OPT_REC))
		while (*plst)
		{
			if (dir = ls_next_dir(path, plst, &out))
				out = ft_ls(path, dir, util);
			else if (out)
				util->flag |= (out == 2) ? BIG_ERR : SML_ERR;
			ft_lstdelfst(plst, &ls_del_node);
		}
	else
		ft_lstdel(plst, &ls_del_node);
	return (out);
}
