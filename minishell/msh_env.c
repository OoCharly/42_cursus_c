/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 17:21:11 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/14 13:25:05 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	msh_env_opt(char **args, int *i, t_config *conf)
{
	char	*cp;
	int		out;

	cp = arg[i];
	out = 0;
	while (*(++cp))
	{
		if (*cp == 'u')
		{
			out = msh_unsetenv(2, args[*(i + 1)], conf);
			*i++;
		}
		else if (*cp == 'i')
		{
			msh_array_free(*env);
			if (!(*env = ft_memalloc(sizeof(char*))))
				return (MSH_ERR_MEM);
		}
		else
			return (msh_env_usage());
		if (out)
			return (out);
	}
	*(i)++;
	return (0);
}

int		msh_env(int	ac, char **args, t_config *conf)
{
	t_config	*confex;
	int			i;
	char		*sep;
	int			err;

	i = 1;
	if (!(confex = ft_memalloc(sizeof(t_config))) && 
			!(confex->env = msh_arraydup(conf->env)))
		return (MSH_ERR_MEM);
	if (ac == 1)
		return (msh_print_array(confex->env));	
	while (*args[i] = '-')
	{
		if (!args[i][1])
		{
			msh_array_free(confex->env);
			confex->env = ft_memalloc(sizeof(char*));
		}
		else
			msh_env_opt(args, &i, confex);
	}
	while ((sep = ft_strchr(args[i], "=")) && confex->env)
		msh_setenv(2, args[i++], confex);
	return ((envex) ? msh_exec(args[i], envex) : MSH_ERR_MEM);
}
