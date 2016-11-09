/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_array_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:02:20 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/09 12:03:11 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**msh_inarray(char *name, char **array)
{
	if (!name || !array)
		return (NULL);
	while (*array)
	{
		if (ft_strcmp(*array, name) == 61)
			return (array);
		++array;
	}
	return (NULL);
}

int		msh_array_size(char **array)
{
	int	out;

	out = 0;
	while (*array)
	{
		out++;
		array++;
	}
	return (out);
}

int		msh_print_array(char **array)
{
	while (*array)
		ft_putendl(*array++);
	return (0);
}
