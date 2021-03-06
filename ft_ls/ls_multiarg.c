/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_multiarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:37:47 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/20 16:24:13 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_insert_arg(t_list **plst, char *name, t_util *util)
{
	t_info	*new;
	t_list	*lstnew;
	t_fetch	fetch;

	fetch = util->fetch;
	new = (*fetch)(name, NULL, util->flag);
	if (!(lstnew = ft_lstcreate(new, sizeof(t_list))))
		exit(2);
	ft_lstsort(plst, lstnew, util->cmp);
	if (util->flag & NO_SUPP)
		fetch_info_supp(new, util->flag, util->lscol);
}

static t_list	**ls_sort_largs(t_list **plst, char **av, t_util *util)
{
	DIR		*dir;
	t_list	**flst;

	if (!(flst = ft_memalloc(sizeof(t_list*))))
		exit(2);
	while (*av)
	{
		if (readlink(*av, NULL, 0) > -1)
			ls_insert_arg(flst, *av, util);
		else if ((dir = opendir(*av)))
			ls_insert_arg(plst, *av, util);
		else if (errno == ENOTDIR)
			ls_insert_arg(flst, *av, util);
		else if (errno == EACCES)
			ls_insert_arg(plst, *av, util);
		else
		{
			util->flag |= SML_ERR;
			ls_error(*av);
		}
		av++;
	}
	return (flst);
}

static t_list	**ls_sort_args(t_list **plst, char **av, t_util *util)
{
	DIR		*dir;
	t_list	**flst;

	if (!(flst = ft_memalloc(sizeof(t_list*))))
		exit(2);
	while (*av)
	{
		if ((dir = opendir(*av)))
		{
			ls_insert_arg(plst, *av, util);
			closedir(dir);
		}
		else if (errno == EACCES)
			ls_insert_arg(plst, *av, util);
		else if (errno == ENOTDIR ||
				(errno == ENOENT && (readlink(*av, NULL, 0) > -1)))
			ls_insert_arg(flst, *av, util);
		else
		{
			util->flag |= SML_ERR;
			ls_error(*av);
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
		i = 0;
		while (av[i])
		{
			if (ft_strcmp(*av, *(av + i)) > 0)
			{
				tmp = *av;
				*av = *(av + i);
				*(av + i) = tmp;
			}
			i++;
		}
		av++;
	}
}

t_list			**ls_multi_arg(char **av, t_util *util)
{
	t_list	**plst;
	t_list	**pflst;

	if (!(plst = ft_memalloc(sizeof(t_list*))))
		exit(2);
	ls_reargv(av);
	if (util->flag & OPT_LNG)
		pflst = ls_sort_largs(plst, av, util);
	else
		pflst = ls_sort_args(plst, av, util);
	if (*pflst)
		ls_print("", pflst, util);
	ft_lstdel(pflst, &ls_del_node);
	free(pflst);
	return (plst);
}
