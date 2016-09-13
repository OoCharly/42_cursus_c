/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 12:26:11 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/13 18:36:50 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

DIR		*ls_next_dir(char *path, t_list **plst, int *out)
{
	DIR 	*ret;
	t_info	*info;

	info = (t_info*)((*plst)->content);
	path = memcpy(path + ft_strlen(path), info->i_name, info->i_len);
	if ((ret = opendir(path)))
		return (ret);
	else
	{
		ls_erase_last_name(path, info->i_len);
		if (errno != 20)
		{
			perror("yolo");
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

	ft_putendl("start ft_ls");
	*(path + ft_strlen(path)) = '/';
	if (!(plst = ft_memalloc(sizeof(t_list*))))
		exit(2);
	ft_putendl("get_list start");
	out = get_list(path, dir, util, plst);
	ft_putendl("get_list done");
	util->flag |= (out == 2) ? BIG_ERR : 0;
	closedir(dir);
	ls_print(path, plst, util);
	if ((util->flag & OPT_REC))
		while (*plst)
		{
			if ((dir = ls_next_dir(path, plst, &out)))
				out = ft_ls(path, dir, util);
			else if (out)
				util->flag |= (out == 2) ? BIG_ERR : SML_ERR;
			ft_lstdelfst(plst, &ls_del_node);
		}
	else
		ft_lstdel(plst, &ls_del_node);
	return (out);
}
