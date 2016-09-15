/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_multiarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:37:47 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/14 17:51:19 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_insert_arg(t_list **plst, char *name, t_util *util)
{
	t_info	*new;
	t_stat	*st;
	t_list	*lstnew;
	t_info	*(*get)(char *, t_dirent*, t_util*);

	get = (util->flag & NO_STAT) ? &get_linfo : &get_info;
	new = (*get)(name, NULL, util);
	if (!(lstnew = ft_lstcreate(new, sizeof(t_list))))
		exit(2);
	ft_lstsort(plst, lstnew, util->cmp);
}

static t_list	**ls_sort_args(t_list **plst, char **av, t_util *util)
{
	t_pcmp	cmp;
	DIR		*dir;
	t_list	**flst;

	cmp = util->cmp;
	if (!(flst = ft_memalloc(sizeof(t_list*))))
		exit(2);
	while (*av)
	{
		if(!(dir = opendir(*av)) && errno != ENOTDIR)
				perror(*av);
		else if (!dir)
			ls_insert_arg(flst, *av, util);
		else
		{
			ls_insert_arg(plst, *av, util);
			closedir(dir);
		}
		av++;
	}
	return (flst);
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
			i++;
		}
		av++;
	}
}

t_list			**ls_multi_arg(char *path, char **av, t_util *util)
{
	t_list	**plst;
	t_list	**pflst;
	t_pcmp	cmp;

	if(!(plst = ft_memalloc(sizeof(t_list*))))
		exit(2);
	ls_reargv(av);
	pflst = ls_sort_args(plst, av, util);
	if (*pflst)
		ls_print("", pflst, util);
	ft_lstdel(pflst, &ls_del_node);
	free(pflst);
	return (plst);
}
