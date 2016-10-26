/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 12:44:00 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/26 13:04:24 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_error(char *path)
{
	char	*exe;

	exe = path + (ft_strrchr(path, '/') - path);
	if (acces(path, F_OK))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(exe, 2);
		ft_putendl(": command not found");
	}
	else if(access(path, x_OK))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(path, 2);
		ft_putendl(": Permission denied");
	}
	return ;
}
