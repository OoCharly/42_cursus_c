/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 17:21:11 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/08 18:50:38 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		msh_env(int	ac, char **args, char **env)
{
	if (ac == 1)
	{
		while (*env)
			ft_putendl(*env++);
		return (0);
	}
	while (args[i])
	{
		if (*args[i] == '-')
	}
}

char	**msh_addenv(char **env, char *name, char *val)
{
	char	*elem;
	int		len;

	len = ft_strlen(name) + ft_strlen(val) + 2;
	if (!(elem = ft_memalloc(sizeof(char) * len)))
		return (NULL);
	ft_strcat(ft_strcat(ft_strcat(elem, name), "="), val);
	return (msh_array_add_elem(env, elem));
}

int		msh_setenv(int ac, char **args, t_config *conf)
{
	int		len;
	char	*str;
	char	*cp;
	char	**out;

	if (ac < 2 || ac > 3)
		return ((ac == 1) ? msh_env(conf->env) : MSH_ARGS_MANY);
	if (!*(cp = args[1]))
		return (4);
	while (*cp)
		if (!ft_isalnum(*cp) && *cp != '_')
			return (MSH_ENV_NALNUM);
	len = ft_strlen(args[1]) + ft_strlen(args[2]);
	if ((out = msh_inarray(args[1], conf->env)))
	{
		if(!(str = ft_memalloc(sizeof(char) * (len + 2))))
			return (2);
		ft_strcat(ft_strcat(ft_strcat(str, args[1]), "="), args[2]);
		free(*out);
		*out = str;
	}
	else if(!(conf->env = msh_addenv(conf->env, args[1], args[2])))
			return (2);
	return (0);
}

int		msh_unsetenv(int ac, char **args, t_config *conf)
{
	char	**cp;
	char	**out;
	char	**env;
	char	*targets[ac];

	if (ac == 1)
		return (MSH_ARGS_FEW);
	cp = args;
	env = conf->env;
	while (*(++cp))
		if (msh_inarray(*cp, env))
			*out++ = *cp;
	*out = NULL;
	if (!(out = ft_memalloc(sizeof(char*) * (msh_array_size(env) -
										msh_array_size(targets)))))
		return (9);
	cp = out;
	while (*env)
	{
		if (!msh_inarray(*env, targets))
			*cp++ = *env;
		env++;
	}
	msh_array_free(targets);
	return (0);
}
