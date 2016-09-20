/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 10:08:31 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/09 10:12:10 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnrchr(const char *s, int c, size_t n)
{
	int i;

	i = n - 1;
	while (i >= 0)
	{
		if (*(s + i) == (char)c)
			return ((char*)(s + i));
		i--;
	}
	return (NULL);
}
