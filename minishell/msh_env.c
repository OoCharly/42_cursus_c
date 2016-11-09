/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 17:21:11 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/09 18:00:52 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*          TENTATIVE -S (LONG ET CHIANT)
**			static int	msh_env_set(char *arg, char **env)
**			{
**			char	*elem;
**
**			if (*arg == '#')
**			return (0);
**			msh_strstrip
**			if (!(elem = ft_strdup(arg
*/
static int	msh_env_del(char **env, char *name)
{
	
}
static int	msh_env_set(char ***env, char *str, char *sep)
{
	char	**pos;
	char	*var;
	int		out;

	if (!(var = ft_strndup(str, sep - str + 1)))
		return (MSH_ERR_MEM);
	if (!(pos = msh_inarray(var, *env)))
	{
		msh_array_free(*env);
		if (!(*env = msh_array_add_elem(*env, elem)))
			return (NULL);
		return (0);
	}
	free(*pos);
	*pos = ft_strdup(str);
	return (0);
}

static int	msh_env_opt(char **args, int *i, char ***env)
{
	char	*cp;
	int		out;

	cp = arg[i];
	out = 0;
	while (*(++cp))
	{
		if (*cp == 'u')
		{
			out = msh_env_del(env, args[*(i + 1)]);
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
	char	**envex;
	int		i;
	char	*sep;

	i = 1;
	if (!(envex = msh_arraydup(conf->env)))
		return (MSH_ERR_MEM);
	if (ac == 1)
		return (msh_print_array(envex));	
	while (*args[i] = '-')
	{
		if (!args[i][1])
		{
			msh_array_free(envex);
			envex = ft_memalloc(sizeof(char*));
		}
		else
			msh_env_opt(args, &i, envex);
	}
	while ((sep = ft_strchr(args[i], "=")) && envex)
		msh_env_set(&envex, args[i], sep);
	return ((envex) ? msh_launch(args[i], envex) : MSH_ERR_MEM);
}
