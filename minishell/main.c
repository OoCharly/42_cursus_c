/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 11:36:54 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/26 13:19:02 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void	msh_loop()
{
	int		status;
	char	*cmd;
	t_list	**lcmd;
	t_list	*tmp;

	status = 1;
	while (status)
	{
		ft_putstr("$>");
		cmd = msh_read_cmd();
		lcmd = msh_parse(cmd);
		tmp = *lcmd;
		while (tmp)
		{
			status = msh_launch(tmp->content);
			tmp = tmp->next;
		}
	}
}

int		main(int ac, char **av, char **env)
{
	//msh_config();
	msh_loop();
	return (EXIT_SUCCESS);
}
