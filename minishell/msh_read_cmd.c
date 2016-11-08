/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_read_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 12:43:36 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/08 15:05:39 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*msh_read_cmd(void)
{
	char	**line;

	*line = NULL;
	if (msh_cmd_parser(0, line) >= 0)
		return (*line);
	else
		msh_exit();
}
