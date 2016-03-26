/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:30:22 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/17 13:33:01 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*(t_byte*)s1 == *(t_byte*)s2 && *(t_byte*)s1 && *(t_byte*)s2 && --n)
	{
		s1++;
		s2++;
	}
	return ((int)(*(t_byte*)s1 - *(t_byte*)s2));
}
