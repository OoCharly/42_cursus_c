/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:05:57 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/12 16:11:02 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ntoa(intmax_t n)
{
	int			i;
	int			j;
	char		*out;
	uintmax_t	tmp;

	i = 0;
	tmp = (n < 0) ? 0 - n: 0 + n;
	while ((tmp / ft_pow(10, i)) >= 10)
		i++;
	if (!(out = ft_memalloc(sizeof(char) * (i + 2))))
		return (NULL);
	j = 0;
	if (n < 0)
		out[j++] = '-';
	while (i >= 0)
	{
		out[j++] = '0' + (tmp / ft_pow(10, i));
		tmp %= ft_pow(10, i);
		i--;
	}
	return (out);
}
