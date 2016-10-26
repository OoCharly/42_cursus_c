/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parse_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 12:43:35 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/26 12:27:40 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	**msh_parse(char *cmd)
{
	char	**scargs;
	char	**args;
	t_list	**lcmd;

	if (!(lcmd = ft_memalloc(sizeof(t_list*))))
		exit(2);
	scargs = ft_strsplit(cmd, ';');
	while (*scargs)
	{
		args = ft_strsplitspace(*scargs);
		ft_lstadd_end(lcmd, ft_lstcreate(args, sizeof(args)));
		scargs++;
	}
	return (lcmd);
}

