/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 17:25:58 by cdesvern          #+#    #+#             */
/*   Updated: 2016/08/24 18:49:11 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_ls_by_name(t_info *new, t_info *old)
{
	return (ft_strcmp(old->i_dirent->d_name, new->i_dirent->d_name);
}

int	ft_ls_by_mtime(t_info *new, t_info *old)
{
	return ((int)(old->i_stat->st_mtime - new->i_stat->st_mtime));
}

