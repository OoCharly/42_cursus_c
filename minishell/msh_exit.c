/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:54:41 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/18 16:42:59 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_exit(int ac, char **args, t_config *conf)
{
	if (conf)
	{
		msh_array_free(conf->env);
		free(conf);
	}
	if (ac > 1)
		exit(ft_atoi(args[1]));
	exit(0);
}
