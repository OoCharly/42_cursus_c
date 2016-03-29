/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 18:38:59 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/29 13:28:27 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	long	tmp;

	i = 0;
	tmp = n;
	if (tmp < 0)
	{
		ft_putchar_fd('-', fd);
		tmp = -tmp;
	}
	while (tmp / ft_pow(10, i) > 9)
		i++;
	while (i >= 0)
	{
		ft_putchar_fd('0' + (char)(tmp / ft_pow(10, i)), fd);
		tmp = tmp % ft_pow(10, i);
		i--;
	}
}
