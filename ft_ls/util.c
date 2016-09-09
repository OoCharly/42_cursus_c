/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 14:37:17 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/09 16:34:16 by cdesvern         ###   ########.fr       */
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

void	ls_free_util(t_util **util)
{
	free((*util)->cmp);
	if ((*util)->getstat)
		free((*util)->getstat);
	free(*util);
}

void	ls_del_node(void *content, size_t n)
{
	t_info	*tmp;
	size_t	norme;

	norme = n;
	tmp = (t_info*)content;
	free(tmp->i_name);
	if (tmp->i_stat)
	{
		free(tmp->i_stat);
		free(tmp->i_perm);
		free(tmp->i_nlink);
		free(tmp->i_usr);
		free(tmp->i_grp);
		free(tmp->i_size);
		free(tmp->i_date);
	}
}

int		usage(void)
{
	ft_printf("usage: ls [Radlrt] [file ...]");
	exit (2);
}

t_util	*get_util(int flag, t_pcmp cmp)
{
	t_util	*out;

	if (!(out = ft_memalloc(sizeof(t_util))))
		return (NULL);
	out->cmp = cmp;
	out->flag = flag;
	if ((flag & NO_STAT))
		out->getstat = NULL;
	else
		out->getstat = &lstat;
	return (out);
}
