/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 11:53:40 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/17 10:50:07 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			*(t_byte*)(dst + (i - 1)) = *(t_byte*)(src + (i - 1));
			i--;
		}
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}
