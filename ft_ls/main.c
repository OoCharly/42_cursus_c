/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 16:14:48 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/14 18:20:52 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_start(char *path, t_list **plst, t_util *util)
{
	DIR 	*dir;
	t_info	*info;

	while (*plst)
	{
		info = (t_info*)((*plst)->content);
		if (!(dir = opendir(info->i_name)))
			perror(info->i_name);
		else
		{
			ft_memcpy(path, info->i_name, info->i_len);
			ft_ls(path, dir, util);
			ft_memset(path, 0, info->i_len);
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

	if (!(path = ft_memalloc(sizeof(char) * _POSIX_PATH_MAX)))
		exit (2);
	if(!(util = ft_memalloc(sizeof(t_info))))
		exit (2);
	if (!(out = ls_prelim(ac, av, util)))
		return (2);
	if (ac == out)
	{
		ft_strcat(path, ".");
		if(!(dir = opendir(path)))
			perror("main");
		ft_ls(path, dir, util);
	}
	else
	{
		util->flag |= ((ac - out) > 1) ? MULTIARG : 0;
		plst = ls_multi_arg(path, av + out, util);
		ls_start(path, plst, util);
	}
	free(util);
	return (0);
}
