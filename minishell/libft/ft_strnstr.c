/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:04:41 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/17 10:30:49 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	if (*s2 == '\0')
		return ((char*)s1);
	len = ft_strlen(s2);
	while (*s1 && n-- >= len)
	{
		if (!ft_memcmp(s1, s2, len))
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
