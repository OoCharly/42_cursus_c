/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 11:43:48 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/26 17:25:44 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(t_byte*)dst = *(t_byte*)src;
		if (*(t_byte*)src == (t_byte)c)
			return (++dst);
		i++;
		dst++;
		src++;
	}
	return (NULL);
}
