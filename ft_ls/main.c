/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 16:14:48 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/19 19:55:53 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_postlim(t_util *util, char *path)
{
	int	out;

	out = (util->flag & SML_ERR) ? 1 : 0;
	free(util->lscol);
	free(util);
	free(path);
	return (out);
}

void	ls_start(char *path, t_list **plst, t_util *util)
{
	DIR		*dir;
	t_info	*info;

	while (*plst)
	{
		info = (t_info*)((*plst)->content);
		if (!(dir = opendir(info->i_name)))
		{
			if (util->flag & MULTIARG)
				ft_printf("%s%s:\n", (util->flag & SML_ERR) ? "\n" : "",
									info->i_name);
			util->flag |= SML_ERR;
			ls_error(ft_strchr(info->i_name, '/') + 1);
			ft_lstdelfst(plst, &ls_del_node);
		}
		else
		{
			ft_memcpy(path, info->i_name, info->i_len);
			ft_ls(path, dir, util);
			ft_memset(path, 0, PATH_MAX + NAME_MAX);
			ft_lstdelfst(plst, &ls_del_node);
		}
	}
	free(plst);
}

int		main(int ac, char **av)
{
	t_util	*util;
	char	*path;
	DIR		*dir;
	t_list	**plst;
	int		out;

	if (!(path = ft_memalloc(sizeof(char) * (PATH_MAX + NAME_MAX))))
		exit(2);
	if (!(util = ft_memalloc(sizeof(t_util))))
		exit(2);
	out = ls_prelim(ac, av, util);
	if (ac == out)
	{
		ft_strcat(path, ".");
		dir = opendir(path);
		ft_ls(path, dir, util);
	}
	else
	{
		util->flag |= ((ac - out) > 1) ? MULTIARG : 0;
		plst = ls_multi_arg(av + out, util);
		ls_start(path, plst, util);
	}
	return (ls_postlim(util, path));
}
