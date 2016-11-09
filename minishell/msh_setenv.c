/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:24:36 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/09 17:28:20 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.c"

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
			return (MSH_ERR_MEM);
		ft_strcat(ft_strcat(ft_strcat(str, args[1]), "="), args[2]);
		free(*out);
		*out = str;
	}
	else if(!(conf->env = msh_addenv(conf->env, args[1], args[2])))
			return (MSH_ERR_MEM);
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
		return (MSH_ERR_MEM);
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
