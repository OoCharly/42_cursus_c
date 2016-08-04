/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 12:57:17 by cdesvern          #+#    #+#             */
/*   Updated: 2016/07/29 15:36:49 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getenv(const char *name)
{
	const char	*np;
	char		**p;
	char		*cp;
	int		i;
	int		len;

	i = 0;
	if (!(np = name) || !__environ)
		return (NULL);
	while(*np && *np != '=')
		np++;
	len = (int)(np - name);
	p = __environ;
	while((cp = *p) != NULL)
	{
		np = name;
		i = len + 1;
		while (--i && *cp)
			if (*cp++ != *np++)
				break ;
		if (!i && *cp++ == '=')
			return (cp);
		p++;
	}
	return (NULL);
}
