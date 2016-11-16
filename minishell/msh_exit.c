/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:54:41 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/16 18:42:24 by cdesvern         ###   ########.fr       */
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
	exit(0);
}
