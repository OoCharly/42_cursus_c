/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 11:12:45 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/26 18:15:27 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	t_byte	*tmp;

	i = 0;
	tmp = (t_byte*)b;
	while (i < len)
	{
		tmp[i] = (t_byte)c;
		i++;
	}
	return (b);
}
