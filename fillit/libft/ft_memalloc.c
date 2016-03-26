/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:30:26 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/26 19:19:12 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	t_byte	*b;
	size_t	i;

	if (!(b = (t_byte*)malloc(sizeof(t_byte) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(b + i) = 0;
		i++;
	}
	return (b);
}
