/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 12:43:35 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/15 16:01:17 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_args(char **args)
{
	while (*args)
	{
		msh_strstrip(*args);
		args++;
	}
}

t_list	**msh_parse(char *cmd)
{
	char	**scargs;
	char	**args;
	t_list	**lcmd;

	if (!(lcmd = ft_memalloc(sizeof(t_list*))))
		exit(2);
	scargs = msh_strsplit(cmd, ';');
	while (*scargs)
	{
		args = msh_strspacesplit(*scargs);
		clean_args(args);
		if (!*args)
			*lcmd = NULL;
		else
			ft_lstadd_end(lcmd, ft_lstcreate(args, sizeof(args)));
		scargs++;
	}
	return (lcmd);
}
