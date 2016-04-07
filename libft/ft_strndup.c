/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 15:22:44 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/07 15:34:08 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*out;
	size_t	i;

	i = 0;
	if (!(out = (char*)ft_memalloc(sizeof(char) * n + 1)))
			return (NULL);
	while (i < n)
	{
		out[i] = *src;
		i++;
		src++;
	}
	return (out);
}
