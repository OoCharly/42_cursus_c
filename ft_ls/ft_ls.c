/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 12:26:11 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/20 16:02:29 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

DIR		*ls_next_dir(char *path, t_list **plst, t_util *util)
{
	DIR		*ret;
	t_info	*info;
	char	*slash;

	info = (t_info*)((*plst)->content);
	if (!ft_strcmp(info->i_name, ".") || !ft_strcmp(info->i_name, ".."))
		return (NULL);
	ft_strcat(path, info->i_name);
	if ((ret = opendir(path)))
	{
		if (readlink(path, NULL, 0) == -1)
			return (ret);
		else
			closedir(ret);
	}
	else
	{
		if (!((errno == ENOTDIR) | (errno == ENOENT)))
		{
			ft_printf("%s%s:\n", (util->flag & PRTD) ? "\n" : "", path);
			ls_error(ft_strrchr(path, '/') + 1);
			util->flag |= SML_ERR;
		}
	}
	ls_erase_last_name(path, info->i_len);
	return (NULL);
}

void	ft_ls(char *path, DIR *dir, t_util *util)
{
	t_list		**plst;
	char		*cp;

	if (*(path + ft_strlen(path) - 1) != '/')
		*(path + ft_strlen(path)) = '/';
	if (!(plst = ft_memalloc(sizeof(t_list*))))
		exit(2);
	get_list(path, dir, util, plst);
	closedir(dir);
	ls_print(path, plst, util);
	if ((util->flag & OPT_REC))
		while (*plst)
		{
			cp = ft_strdup(path);
			if ((dir = ls_next_dir(path, plst, util)))
			{
				ft_ls(path, dir, util);
				ft_memset(path, 0, _POSIX_PATH_MAX);
				ft_strcat(path, cp);
			}
			ft_lstdelfst(plst, &ls_del_node);
			free(cp);
		}
	ft_lstdel(plst, &ls_del_node);
	free(plst);
}
