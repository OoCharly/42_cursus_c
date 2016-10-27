/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 17:07:06 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/27 15:06:52 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**func(void)
{
	char	*func_name[6];

	func_name = {"cd", "echo", "setenv", "unsetenv", "env", "exit"};
	return (func_name);
}

char	**pfunc(void)
{
	t_bin	pfunc[6];

	pfunc = {&msh_cd, &msh_echo, &msh_setenv, &msh_unsetenv, &msh_env,
			&msh_exit};
	return (pfunc);
}

t_bin	*get_builtin(char *name, t_config *config)
{
	char	**cp;
	int		i;

	i = 0;
	cp = config->pbin;
	while (i < 6)
	{
		if (!(ft_strcmp(name, cp[i])))
			return ((config->pbin)[i]);
		i++;
	}
	return (NULL);
}
