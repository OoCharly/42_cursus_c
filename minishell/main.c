/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 11:36:54 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/18 17:54:59 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_config	*msh_config(char **env)
{
	t_config	*conf;

	if ((conf = ft_memalloc(sizeof(t_config))) &&
			(conf->env = msh_arraydup(env)))
		return (conf);
	return (NULL);
}

void		msh_loop(t_config *conf)
{
	int		status;
	char	*cmd;
	t_list	**lcmd;
	t_list	*tmp;

	status = 1;
	while (1)
	{
		ft_putstr("$>");
		cmd = msh_read_cmd();
		lcmd = msh_parse(cmd);
		tmp = *lcmd;
		while (tmp)
		{
			status = msh_exec(tmp->content, conf);
			tmp = tmp->next;
		}
		ft_lstdel(lcmd, &msh_lstarray_free);
	}
}

int			main(int ac, char **av, char **env)
{
	t_config	*conf;

	if (ac && av)
	{
		if (!(conf = msh_config(env)))
			return (MSH_ERR_MEM);
		msh_loop(conf);
		return (EXIT_SUCCESS);
	}
}
