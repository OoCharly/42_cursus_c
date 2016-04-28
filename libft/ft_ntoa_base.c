/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:05:24 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/28 13:41:37 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ntoa_base(uintmax_t nb, unsigned int base, int s)
{
	int			i;
	char		*out;
	char		*tab;

	tab = "0123456789abcdef";
	i = 0;
	if (s == 1 && base == 10)
		return (ft_ntoa(nb));
	while ((nb / ft_pow(base, i)) >= base)
		i++;
	if (!(out = ft_memalloc(sizeof(char) * (i + 2))))
		return (NULL);
	s = 0;
	while (i >= 0)
	{
		out[s++] = tab[nb / ft_pow(base, i)];
		nb %= ft_pow(base, i--);
	}
	return (out);
}
