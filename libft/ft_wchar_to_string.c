/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_to_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:19:12 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/10 10:19:26 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_wchar_malloc(int size, int *i)
{
	if (size <= 7)
	{
		*i = 0;
		return (ft_memalloc(sizeof(char) * 2));
	}
	if (size <= 11)
	{
		*i = 1;
		return (ft_memalloc(sizeof(char) * 3));
	}
	if (size <= 16)
	{
		*i = 2;
		return (ft_memalloc(sizeof(char) * 4));
	}
	*i = 3;
	return (ft_memalloc(sizeof(char) * 5));
}

char		*ft_wchar_to_string(int c)
{
	char	*out;
	int		size;
	int		i;

	size = ft_nsize_base(c, 2);
	if (!(out = ft_wchar_malloc(size, &i)))
		return (NULL);
	size = 240;
	if (!i)
		out[0] = (char)c;
	else
		out[0] = (((c >> (8 * i)) << (26 + i)) >> 26) | (size << (4 - i));
	size = 1;
	while (i)
	{
		i--;
		out[size] = ((c >> (8 * i) << 26) >> 26) | 128;
	}
	return (out);
}
