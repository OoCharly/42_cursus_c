/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:14:44 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/16 18:24:14 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		msh_export(int ac, char **args, t_config *conf)
{
	static char	*cmd[] = {"unsetenv", NULL, NULL, NULL};
	char		*sep;
	int			i;
	int			err;

	if (ac < 2)
		return (MSH_ARGS_FEW);
	i = 0;
	err = 0;
	while (++i < ac && !err)
	{
		sep = ft_strchr(args[i], '=');
		*sep = 0;
		cmd[1] = args[i];
		cmd[2] = sep + 1;
		err = msh_setenv(3, cmd, conf);
	}
	return (err);
}
