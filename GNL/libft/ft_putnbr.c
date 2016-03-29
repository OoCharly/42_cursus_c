/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 18:32:59 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/29 13:28:13 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		i;
	long	tmp;

	i = 0;
	tmp = n;
	if (tmp < 0)
	{
		ft_putchar('-');
		tmp = -tmp;
	}
	while (tmp / ft_pow(10, i) > 9)
		i++;
	while (i >= 0)
	{
		ft_putchar('0' + (char)(tmp / ft_pow(10, i)));
		tmp = tmp % ft_pow(10, i);
		i--;
	}
}
