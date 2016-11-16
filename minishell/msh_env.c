/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 17:21:11 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/16 18:33:51 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
static int	msh_env_usage(char *str, int err)
{
	msh_error("env", str, err);
	ft_putendl_fd("usage: env [-i] [-u name] [name=value ...]", 2);
	ft_putendl_fd("           [utility [argument ...]]", 2);
	return (MSH_ERR_PTED);
}

static int	msh_env_del(char **args, t_config *conf, int *i)
{
	int			err;
	static char	*cmd[] = {"unsetenv", NULL, NULL};

	if (!args[0])
	{
		msh_array_free(conf->env);
		free(conf);
		return (msh_env_usage("u", MSH_ENV_MISARG));
	}
	else
	{
		cmd[1] = args[0];
		err = msh_unsetenv(2, cmd, conf);
		if (err)
		{
			msh_array_free(conf->env);
			free(conf);
		}
		(*i)++;
		return (err);
	}
}

static int	msh_env_reset(t_config *conf)
{
	msh_array_free(conf->env);
	conf->env = ft_memalloc(sizeof(char*));
	if (!conf->env)
		return (MSH_ERR_MEM);
	return (0);
}

static int	msh_env_opt(char **args, int *i, t_config *conf)
{
	char	*cp;
	int		err;

	cp = *args;
	err = 0;
	while (*(++cp))
	{
		if (*cp == 'i')
			err = msh_env_reset(conf);
		else if (*cp == 'u')
		{
			if (!*(cp + 1))
				err = msh_env_del(args + 1, conf, i);
		}
		else if (*cp == 'P' || *cp == 'v' || *cp == 's')
			err = msh_env_usage(ft_wchar_to_string((int)(*cp)), MSH_UNAVAIL);
		else
			err = MSH_INV_OPT;
		if (err)
			return (err);
	}
	return (0);
}

int		msh_env(int	ac, char **args, t_config *conf)
{
	t_config	*confex;
	int			i;
	char		*sep;
	int			err;

	err = 0;
	i = 0;
	if (!((confex = ft_memalloc(sizeof(t_config))) &&
			(confex->env = msh_arraydup(conf->env))))
		return (MSH_ERR_MEM);
	while ((args[++i]) && *args[i] == '-')
	{
		if (!args[i][1])
			err = msh_env_reset(confex);
		else
			err = msh_env_opt(args + i, &i, confex);
		if (err)
			return (err);
	}
	while (args[i] && (sep = ft_strchr(args[i], '=')))
		msh_export(2, args + i++ - 1, confex);
	(args[i]) ? msh_exec(args + i, confex) : msh_print_array(confex->env);
	msh_array_free(confex->env);
	free(confex);
	return (0);
}
