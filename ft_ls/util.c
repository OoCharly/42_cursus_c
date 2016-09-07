/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 14:37:17 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/05 15:50:32 by cdesvern         ###   ########.fr       */
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
