/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:53:40 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/17 12:56:22 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dst;
	int		i;

	i = 0;
	dst = ft_strnew(ft_strlen(s));
	if (!(s && f) || !dst)
		return (NULL);
	while (*(s + i))
	{
		*(dst + i) = (*f)(*(s + i));
		i++;
	}
	return (dst);
}
