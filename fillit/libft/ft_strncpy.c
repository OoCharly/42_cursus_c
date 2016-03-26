/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 12:33:06 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/25 12:48:43 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && *(src + i))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dst + i) = '\0';
		i++;
	}
	return (dst);
}
