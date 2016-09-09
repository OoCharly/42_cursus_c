/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_multiarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:37:47 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/09 16:04:28 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_insert_arg(t_list **plst, char *name, t_util util)
{
	t_info	*new;
	t_stat	*st;
	t_list	*lstnew;

	if(!(new = ft_memalloc(sizeof(t_info))))
		exit(2);
	new->i_name = name;
	new->i_len = ft_strlen(name);
	if (util->getstat)
	{
		if((st = util->getstat(name, st)))
			perror(errno);
		new->i_stat = st;
	}
	else
		new->i_stat = NULL;
	if (!(lstnew = ft_lstnew(new, sizeof(new))))
		exit(2);
	ft_lstsort(plst, lstnew, util->cmp);
}

static t_list	**ls_sort_args(t_list **plst, char **av, t_util util)
{
	t_pcmp	cmp;
	DIR		*dir;
	t_list	**flst;

	cmp = util->cmp;
	if (!(flst = ft_plstnew(NULL, 0)))
		exit(2);
	while (*av)
	{
		if(!(dir = opendir(*av)))
		{
			if (errno == ENOTDIR)
				ls_insert_arg(flst, *av, util);
			else
				perror(errno);
		}
		else
		{
			ls_insert_arg(plst, *av, util);
			closedir(dir);
		}
		av++;
	}
}

static void		ls_reargv(char **av)
{
	char	*tmp;
	int		i;

	while (*(av + 1))
	{
		i = 1;
		while (av[i])
		{
			if (ft_strcmp(*av, *(av + i)) > 0)
			{
				tmp = *av;
				*av = *(av + i);
				*av = tmp;
			}
		}
		av++;
	}
}

t_list			**ls_multi_arg(char **av, t_util *util)
{
	t_list	**plst;
	t_list	**pflst;
	t_pcmp	cmp;

	if(!(plst = ft_lstpnew(NULL, 0)))
		exit(2);
	ls_reargv(av);
	pflst = ls_sort_arg(plst, argv, cmp);
	if(*pflst)
		ls_print(pflst, util);
	ls_del_lst(pflst);
	free(pflst);
	return (plst);
}
