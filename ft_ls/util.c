/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 14:37:17 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/01 18:12:39 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_append_path(char *path, char *name)
{
	int	len;

	len = ft_strlen(path);
	ft_strcpy(&path[len], name);
	len += ft_strlen(name);
	path[len] = '\0';
}

int		usage(void)
{
	ft_printf("usage: ls [Radlrt] [file ...]");
	exit (2);
}

t_util	*get_util(int flag, t_pcmp cmp);
{
	t_util	*out;

	if (!(out = malloc(sizeof(t_util))))
		return (NULL);
	out->cmp = cmp;
	out->flag = flag;
	if ((flag & NO_STAT))
		out->getstat = NULL;
	else
		out->getstat = &lstat;
	return (out);
}

void	ls_sort_arg(t_list **plst, char **av)
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


int		ls_multi_arg(char **av, char *path, t_util util)
{
	t_list	*plst;
	t_pcmp	cmp;

	cmp = util->cmp;
	if(!(plst = ft_lstpnew(NULL, 0)))
		return (2);
	ls_sort_arg(plst, argv);
