/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 12:25:06 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/31 11:30:47 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	if (!(s2 = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}
