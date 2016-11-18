/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 12:17:02 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/25 20:19:09 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(t_byte*)(s1 + i) != *(t_byte*)(s2 + i))
			return ((int)((*(t_byte*)(s1 + i)) - (*(t_byte*)(s2 + i))));
		i++;
	}
	return (0);
}
