/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_array_manipulation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:42:56 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/09 15:50:32 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	free(array - size + 1);
	return (out);
}

char	**msh_arraydup(char **array)
{
	char	**out;
	int		size;

	size = msh_array_size(array);
	if (!(out = ft_memalloc(sizeof(char*) * size)))
		return (NULL);
	while (*array)
		*out++ = ft_strdup(*array++);
	*out = NULL;
	return (out - size + 1);
}
