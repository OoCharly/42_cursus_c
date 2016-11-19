/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:05:19 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/19 15:24:55 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	msh_todel(char **args, char **env)
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

int			msh_unsetenv(int ac, char **args, t_config *conf)
{
	int		i;
	char	**tmp;
	char	**out;

	if (ac < 2)
		return (msh_error("unsetenv", NULL, MSH_ARGS_FEW));
	tmp = conf->env;
	if (!(i = msh_array_size(tmp)) ||
			!(ac = msh_todel(args, conf->env)) ||
			!(out = ft_memalloc(sizeof(char*) * (i - ac + 1))))
		return ((ac) ? msh_error(NULL, NULL, MSH_ERR_MEM) : 0);
	i = 0;
	ac++;
	while (ac)
	{
		if (*tmp)
			out[i++] = *tmp;
		else
			ac--;
		tmp++;
	}
	free(conf->env);
	conf->env = out;
	return (0);
}
