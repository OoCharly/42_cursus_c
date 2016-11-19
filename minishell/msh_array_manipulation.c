/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_array_manipulation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:42:56 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/19 15:21:09 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_array_free(char **array)
{
	char	**cp;

	if (!array)
		return ;
	cp = array;
	while (*cp)
	{
		free(*cp);
		*cp++ = NULL;
	}
	free(array);
}

void	msh_lstarray_free(void *array, size_t n)
{
	char	**cp;

	n = 0;
	if (!array)
		return ;
	cp = (char**)array;
	while (*cp)
	{
		free(*cp);
		*cp++ = NULL;
	}
	free(array);
}

char	**msh_array_add_elem(char **array, char *elem)
{
	int		size;
	int		len;
	char	**out;
	char	**cp;
	char	**start;

	start = array;
	size = msh_array_size(array);
	if (!(out = ft_memalloc(sizeof(char*) * (size + 2))))
		return (NULL);
	cp = out;
	while (*array)
		*cp++ = *array++;
	len = ft_strlen(elem);
	if (!(*cp = ft_strdup(elem)))
		return (NULL);
	free(array);
	return (out);
}

char	**msh_arraydup(char **array)
{
	char	**out;
	char	**cp;
	int		size;

	size = msh_array_size(array);
	if (!(out = ft_memalloc(sizeof(char*) * size + 1)))
		return (NULL);
	cp = out;
	while (*array)
	{
		*cp = ft_strdup(*array);
		cp++;
		array++;
	}
	*cp = NULL;
	return (out);
}
