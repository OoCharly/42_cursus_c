/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 12:57:17 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/26 15:11:13 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_getenv(const char *name, const char	**env)
{
	const char			*np;
	const char			**p;
	const char			*cp;
	int					len;

	if (!(np = name) || !env)
		return (NULL);
	while (*np && *np != '=')
		np++;
	len = (int)(np - name) + 1;
	p = env;
	while ((cp = *p) != NULL)
	{
		np = name;
		if (strncmp(cp, np, len) == 61)
			return (cp + len);
		else
			p++;
	}
	return (NULL);
}
