/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:24:36 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/15 17:50:39 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		msh_env_valid(char *arg)
{
	if (!*arg)
		return (4);
	while (*arg)
	{
		if (!ft_isalnum(*arg) && *arg != '_')
			return (MSH_ENV_NALNUM);
		arg++;
	}
	return (0);
}
char	**msh_addenv(char **env, char *name, char *val)
{
	int		size;
	int		i;
	char	**cp;
	char	**out;

	cp = env;
	i = 0;
	while (*cp++)
		i++;
	size = i;
	if (!(out = ft_memalloc(sizeof(char*) * (size + 2))))
		return (NULL);
	cp = env;
	i = 0;
	while (*cp)
		out[i++] = *cp++;
	size = ft_strlen(name) + ft_strlen(val) + 2;
	if (!(out[i] = ft_memalloc(sizeof(char) * (size + 2))))
		return (NULL);
	ft_strcat(ft_strcat(ft_strcat(out[i], name), "="), val);
	msh_array_free(env);
	return (out);
}

int		msh_setenv(int ac, char **args, t_config *conf)
{
	int		len;
	char	*str;
	char	**out;
	int		err;

	if (ac != 3)
		return ((ac == 1) ? msh_print_array(conf->env) : MSH_ARGS_MANY);
	if ((err = msh_env_valid(args[1])))
		return (err);
	len = ft_strlen(args[1]) + ft_strlen(args[2]);
	if ((out = msh_inarray(args[1], conf->env)))
	{
		if(!(str = ft_memalloc(sizeof(char) * (len + 2))))
			return (MSH_ERR_MEM);
		ft_strcat(ft_strcat(ft_strcat(str, args[1]), "="), args[2]);
		free(*out);
		*out = str;
	}
	else if(!(conf->env = msh_addenv(conf->env, args[1], args[2])))
			return (MSH_ERR_MEM);
	return (0);
}

static int		msh_todel(char **args, char **env)
{
	int		del;
	char	**tmp;

	del = 0;
	while (*(++args))
		if ((tmp = msh_inarray(*args, env)))
		{
			free(*tmp);
			*tmp = NULL;
			del++;
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
	if (!((i = msh_array_size(tmp)) && (del = msh_todel(args, conf->env)) &&
				((out = ft_memalloc(sizeof(char*) * (i - del + 1))))))
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
