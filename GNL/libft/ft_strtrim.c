/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:22:13 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/17 14:04:18 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	char	*tmp;

	i = 0;
	if (!s)
		return (NULL);
	while (ft_isspace(s[i]))
		i++;
	start = i;
	i = ft_strlen(s) - 1;
	while (ft_isspace(s[i]) && i > 0)
		i--;
	end = i;
	if (i == 0)
	{
		tmp = ft_strnew(1);
		return ((tmp == NULL) ? NULL : tmp);
	}
	i = end - start + 1;
	tmp = ft_strnew(i);
	return ((tmp == NULL) ? NULL : ft_strncpy(tmp, &s[start], i));
}
