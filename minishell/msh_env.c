/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 17:21:11 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/26 17:21:43 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_env(const char **env)
{
	while (*env)
		ft_putendl(*env++);
}

char	**msh_addenv(char **env, char *name, char *val, int	ssize)
{
	int		size;
	char	**cp;
	char	**out;

	cp = env;
	size = 0;
	while (*cp++)
		size++;
	if (!(out = ft_memalloc(sizeof(char*) * (size + 2))))
		return (NULL);
	cp = env;
	size = 0;
	while (*cp)
		out[size++] = *cp++;
	if (!(out[size] = ft_memalloc(sizeof(char) * (ssize + 2))))
		return (NULL);
	t_strcat(ft_strcat(ft_strcat(out[size], name), "="), val);
	return (out);
}

char	*msh_inarray(const char *name, const char **env)
{
	const char			*np;
	const char			*cp;
	int					len;

	if (!(np = name) || !env)
		return (NULL);
	while (*np && *np != '=')
		np++;
	len = (int)(np - name) + 1;
	while ((cp = *env) != NULL)
	{
		np = name;
		if (ft_strncmp(cp, np, len) == 61)
			return (cp + len);
		else
			env++;
	}
	return (NULL);
}

int		msh_setenv(int ac, char **args, t_config *conf)
{
	int		i;
	char	*str;

	if (ac == 1)
	{
		msh_env(env);
		return (0);
	}
	if (ac > 3)
		return (1);
	i = ft_strlen(args[1]) + ft_strlen(args[2]);
	if (msh_getenv(args[1]))
	{
		if(!(str = ft_memalloc(sizof(char) * (i + 2))))
			return (2);
		ft_strcat(ft_strcat(ft_strcat(str, args[1]), "="), args[2]);
		while (!ft_strncmp(*env, args[1], ft_strlen(args[1])))
			env++;
		free(*env);
		*env = str;
	}
	else
		env = msh_addenv(env, args[1], args[2], i);
	return (0);
}

int		msh_unsetenv(int ac, char **args, t_config *conf)
{
	char	*targets[ac];
	char	**cp;
	char	**new;
	
	if (ac < 2)
		return (1);
	cp = targets;
	while (*args)
		if ((*cp = msh_getenv(*args++)))
			cp++;
	*targets = NULL;
	ac = arsize(conf->env) - arsize(targets);
	cp = conf->env;
	if (!(new = ft_memalloc(conf->env, sizeof(char*) * (size_t)ac)))
		return (2);
	while (*cp)
	{
		if (!msh_inarray(*cp, targets))
			*new++ = *cp;
		cp++;
	}
	free(conf->env);
	conf->env = new;
	return (0);
}
