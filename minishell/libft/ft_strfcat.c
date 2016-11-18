/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:05:04 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/08 18:05:58 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfcat(char *s1, char *s2)
{
	size_t	len;
	size_t	i;

	if (!s2)
		return (s1);
	len = ft_strlen(s1);
	i = 0;
	while (*(s2 + i))
	{
		*(s1 + len + i) = *(s2 + i);
		i++;
	}
	*(s1 + len + i) = '\0';
	free(s2);
	return (s1);
}
