/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:31:07 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/26 15:58:37 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(void *old, size_t size)
{
	t_byte	*b;
	size_t	i;

	if (!(b = (t_byte*)ft_memalloc(t_byte) * size))
		return (NULL);
	i = 0;
	while (old[i] && (i < size))
	{
		b[i] = old[i];
		i++;
	}
	free(old);
	old = NULL;
	return (b);
}
