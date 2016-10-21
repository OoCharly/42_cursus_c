/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 11:36:54 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/21 16:55:10 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_loop()
{
	int		status;
	char	*cmd;
	char	**args;

	status = 1;
	while (status)
	{
		ft_putstr("$>");
		cmd = msh_read_cmd();
		args = msh_parse(cmd);
		if (*args)
			status = msh_launch(args);
	}
}

int		main(int ac, char **av)
{
	msh_loop();
	return (EXIT_SUCCESS);
}
