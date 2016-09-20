/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:55:47 by cdesvern          #+#    #+#             */
/*   Updated: 2016/02/26 09:48:48 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	mem;

	i = 0;
	mem = -1;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			mem = i;
		i++;
	}
	if (*(s + i) == (char)c)
		return ((char*)(s + i));
	if (mem < 0)
		return (NULL);
	else
		return ((char*)(s + mem));
}
