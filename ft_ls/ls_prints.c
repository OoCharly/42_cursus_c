/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:40:10 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/19 20:17:10 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_print_simple(t_list **plst, unsigned int *pad)
{
	t_list	*tmp;
	t_info	*cpinfo;

	tmp = *plst;
	while (tmp)
	{
		cpinfo = tmp->content;
		ft_printf("%s%.*s\n", cpinfo->i_name, pad[7], cpinfo->i_suff);
		tmp = tmp->next;
	}
}

void	ls_print_prefix(t_list **plst, unsigned int *pad)
{
	t_list	*tmp;
	t_info	*cpinfo;

	tmp = *plst;
	while (tmp)
	{
		cpinfo = tmp->content;
		ft_printf("%*.*s%*.*s %s%.*s\n",
				pad[6], pad[6], cpinfo->i_ino,
				pad[0], pad[0], cpinfo->i_blocks,
				cpinfo->i_name, pad[7], cpinfo->i_suff);
		tmp = tmp->next;
	}
}

void	ls_print_long(t_list **plst, unsigned int *pad)
{
	t_list	*tmp;
	t_info	*cpinfo;

	tmp = *plst;
	while (tmp)
	{
		cpinfo = tmp->content;
		ft_printf("%s%*s %-*s%-*s%*s%*s %s%.*s%s\n",
				cpinfo->i_perm,
				pad[1], cpinfo->i_nlink,
				pad[2], cpinfo->i_usr,
				pad[3], cpinfo->i_grp,
				pad[4], cpinfo->i_size,
				pad[5], cpinfo->i_date,
				cpinfo->i_name, pad[7], cpinfo->i_suff, cpinfo->i_link);
		tmp = tmp->next;
	}
}

void	ls_print_long_prefix(t_list **plst, unsigned int *pad)
{
	t_list	*tmp;
	t_info	*cpinfo;

	tmp = *plst;
	while (tmp)
	{
		cpinfo = tmp->content;
		ft_printf("%*.*s%*.*s %s%*s %-*s%-*s%*s%*s %s%.*s%s\n",
				pad[6], pad[6], cpinfo->i_ino,
				pad[0], pad[0], cpinfo->i_blocks,
				cpinfo->i_perm,
				pad[1], cpinfo->i_nlink,
				pad[2], cpinfo->i_usr,
				pad[3], cpinfo->i_grp,
				pad[4], cpinfo->i_size,
				pad[5], cpinfo->i_date,
				cpinfo->i_name, pad[7], cpinfo->i_suff, cpinfo->i_link);
		tmp = tmp->next;
	}
}
