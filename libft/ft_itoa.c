/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 18:08:14 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/26 16:55:46 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_itoa(int n)
{
	int		neg;
	int		i;
	long	ln;
	char	*out;

	neg = (n < 0) ? 1 : 0;
	i = 0;
	ln = n;
	if (neg)
		ln = -ln;
	while (ln / ft_pow(10,i))
		i++;
	if (ln == 0)
		i = 1;
	out = ft_strnew((size_t)(i + neg));
	if (out == NULL)
		return (NULL);
	if (neg)
		out[0] = '-';
	while (--i >= 0)
		out[neg++] = (char)((ln / ft_pow(10,i)) % 10 + '0');
	return (out);
}
