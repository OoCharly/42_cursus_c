/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 17:58:28 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/15 17:34:54 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_get_path(char *path, char *dirname)
{
	if (!path)
	{
		if (!(path = ft_memalloc(sizeof(char) * _POSIX_PATH_MAX)))
			return ;
		ft_strcat(path, dirname);
	}
	else
		strcat(strcat(path, "/"), dirname);
}


