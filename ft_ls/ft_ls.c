/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 12:26:11 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/15 17:19:22 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

DIR		*ls_next_dir(char *path, t_list **plst, t_util *util)
{
	DIR 	*ret;
	t_info	*info;
	char	*slash;

	info = (t_info*)((*plst)->content);
	ft_strcat(path, info->i_name);
	if ((ret = opendir(path)))
		return (ret);
	else
	{
		ls_erase_last_name(path, (size_t)info->i_len);
		if (!(errno & (ENOTDIR | ENOENT)))
		{
			perror(path);
			util->flag |= SML_ERR;
		}
		return (NULL);
	}
}

int		ft_ls(char *path, DIR *dir, t_util *util)
{
	t_list		**plst;
	int			out;

	*(path + ft_strlen(path)) = '/';
	if (!(plst = ft_memalloc(sizeof(t_list*))))
		exit(2);
	out = get_list(path, dir, util, plst);
	util->flag |= (out == 2) ? BIG_ERR : 0;
	closedir(dir);
	ls_print(path, plst, util);
	if ((util->flag & OPT_REC))
		while (*plst)
		{
			if ((dir = ls_next_dir(path, plst, util)))
				out = ft_ls(path, dir, util);
			else if (out)
				util->flag |= SML_ERR;
			ft_lstdelfst(plst, &ls_del_node);
		}
	else
	{
		ft_lstdel(plst, &ls_del_node);
	}
	return (out);
}
