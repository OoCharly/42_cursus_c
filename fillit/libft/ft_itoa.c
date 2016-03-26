/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 18:08:14 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/17 13:29:31 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_pow_ten(int i)
{
	if (i == 0)
		return (1);
	else
		return (10 * ft_pow_ten(i - 1));
}

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
	while (ln / ft_pow_ten(i))
		i++;
	if (ln == 0)
		i = 1;
	out = ft_strnew((size_t)(i + neg));
	if (out == NULL)
		return (NULL);
	if (neg)
		out[0] = '-';
	while (--i >= 0)
		out[neg++] = (char)((ln / ft_pow_ten(i)) % 10 + 48);
	return (out);
}
