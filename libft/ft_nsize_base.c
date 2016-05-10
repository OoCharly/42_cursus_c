/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nsize_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:15:19 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/10 10:15:22 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nsize_base(uintmax_t nb, int base)
{
	int	i;

	i = 0;
	while (nb / ft_pow(base, i))
		i++;
	return (i);
}
