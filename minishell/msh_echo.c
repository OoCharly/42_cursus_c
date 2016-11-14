/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:25:44 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/14 13:56:39 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_echo(int ac, char **args, t_config *conf)
{
	int		i;
	char	*env;

	i = 1;
	while (i < ac)
	{
		if (*args[i] == '$')
		{
			if (!*(args[i] + 1))
				ft_putstr("$ ");
			else if ((env = ft_getenv(args[i] + 1, conf->env)))
			{
				ft_putstr(env);
				write(1, " ", 1);
			}
		}
		else
			ft_putstr(args[i]);
		write(1, " ", 1);
		i++;
	}
	ft_putendl("");
	return (0);
}
