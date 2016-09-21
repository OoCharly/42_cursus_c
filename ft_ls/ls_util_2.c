/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_util_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 15:54:38 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/21 15:30:40 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

blkcnt_t	ls_sum_blocks(t_list **plst)
{
	long long int	out;
	t_list			*tmp;

	out = 0;
	tmp = *plst;
	while (tmp)
	{
		out += ((t_info*)tmp->content)->i_stat->st_blocks;
		tmp = tmp->next;
	}
	return (out);
}

int			ls_by_rname(void *old, void *new)
{
	return (ft_strcmp(((t_info*)old)->i_name, ((t_info*)new)->i_name));
}

int			ls_by_name(void *old, void *new)
{
	return (ft_strcmp(((t_info*)new)->i_name, ((t_info*)old)->i_name));
}

void		ls_error(char *file)
{
	write(2, "ft_ls: ", 7);
	perror(file);
}
