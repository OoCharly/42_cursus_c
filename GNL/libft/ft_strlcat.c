/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:21:03 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/26 22:00:10 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;

	i = 0;
	while (dst[i] && i < size)
		i++;
	x = i;
	while (src[i - x] && i < size - 1)
	{
		dst[i] = src[i - x];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	return (x + ft_strlen(src));
}
