/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_array_manipulation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:42:56 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/08 18:23:52 by cdesvern         ###   ########.fr       */
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

void	msh_array_free(char **array)
{
	char	**cp;

	cp = array;
	while (*cp)
		free(*cp++);
	free(array);
}

char	**msh_array_add_elem(char **array, char *elem)
{
	int		size;
	int		len;
	char	**out;
	char	**cp;

	size = msh_array_size(array);
	if (!(out = ft_memalloc(sizeof(char*) * (size + 2))))
		return (NULL);
	while (*array)
		*cp++ = *array++;
	len = ft_strlen(elem);
	if (!(*cp = ft_memalloc(sizeof(char) * len)))
		return (NULL);
	free(array - size);
	return (out);
}

int		msh_print_array(char **array)
{
	while (*array)
		ft_putendl(*array++);
	return (0);
}
