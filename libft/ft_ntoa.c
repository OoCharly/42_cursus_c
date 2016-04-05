/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:05:57 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/05 16:12:21 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ntoa(intmax_t n)
{
	int			i;
	int			j;
	char		*out;
	uintmax_t	tmp;

	tmp = 0;
	i = 1;
	if (n < 0)
		tmp -= n;
	else
		tmp = n;
	while ((tmp / ft_pow(10, i)) >= 10)
		i++;
	if (!(out = ft_memalloc(sizeof(char) * (i + 3))))
		return (NULL);
	j = 0;
	if (n < 0)
		out[j++] = '-';
	while (tmp)
	{
		out[j] = tmp / ft_pow(tmp, i);
		tmp %= ft_pow(tmp, i--);
		j++;
	}
	return (out);
}
