/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:05:19 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/16 18:23:27 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		msh_todel(char **args, char **env)
{
	int		del;
	char	**tmp;

	del = 0;
	while (*(++args))
	{
		if ((tmp = msh_inarray(*args, env)))
		{
			free(*tmp);
			*tmp = NULL;
			del++;
		}
	}
	return (del);
}

int		msh_unsetenv(int ac, char **args, t_config *conf)
{
	int		i;
	int		del;
	char	**tmp;
	char	**out;
	
	if (ac < 2)
		return (MSH_ARGS_FEW);
	tmp = conf->env;
	del = 0;
	if (!(i = msh_array_size(tmp)) || !(del = msh_todel(args, conf->env)) ||
				!(out = ft_memalloc(sizeof(char*) * (i - del + 1))))
		return ((del) ? MSH_ERR_MEM : 0);
	i = 0;
	del++;
	while (del)
	{
		if (*tmp)
			out[i++] = *tmp;
		else
			del--;
		tmp++;
	}
	free(conf->env);
	conf->env = out;
	return (0);
}
