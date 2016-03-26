/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:59:28 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/17 10:28:50 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	len;

	if (*s2 == '\0')
		return ((char*)s1);
	len = ft_strlen(s2);
	while (*s1)
	{
		if (!ft_memcmp(s1, s2, len))
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
