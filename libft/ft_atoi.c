/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:34:01 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/17 13:59:50 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long		out;

	if (!str)
		return (0);
	out = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		out *= 10;
		out += ((*str) - '0');
		str++;
	}
	if (out > LONG_MAX && sign > 0)
		return (-1);
	if (out > LONG_MAX && sign < 0)
		return (0);
	return ((int)(out * sign));
}
