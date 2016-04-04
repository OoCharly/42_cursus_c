/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:30:26 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/04 10:38:20 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*b;
	size_t			i;

	if (!(b = (unsigned char*)malloc(sizeof(unsigned char) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		b[i] = 0;
		i++;
	}
	return (b);
}
