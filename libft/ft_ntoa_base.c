/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:05:24 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/12 13:31:33 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ntoa_base(uintmax_t nb, unsigned int base)
{
	int		i;
	int		j;
	char	*out;
	char	*tab;

	tab = "0123456789abcdef";
	i = 0;
	while ((nb / ft_pow(base, i)) >= base)
		i++;
	if (!(out = ft_memalloc(sizeof(char) * (i + 2))))
		return (NULL);
	j = 0;
	while (i >= 0)
	{
		out[j++] = tab[nb / ft_pow(base, i)];
		nb %= ft_pow(base, i--);
	}
	return (out);
}
