/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:05:24 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/05 15:09:42 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ntoa_base(uintmax_t nb, unsigned int base, int s)
{
	int			i;
	intmax_t	tmp;
	char		*out;
	char		*tab;

	tab = "0123456789abcdef";
	i = 1;
	if (s == 1 && base == 10)
	{
		tmp  = (intmax_t)nb;
		return (ft_itoa(tmp));
	}
	while ((nb / ft_pow(base, i)) >= base)
		i++;
	if (!(out = ft_memalloc(sizeof(char) * (i + 2))))
		return (NULL);
	s = 0;
	while (nb)
	{
		out[s++] = tab[nb / ft_pow(base, i)];
		nb %= ft_pow(base, i);
		i--;
	}
	return (out);
}
