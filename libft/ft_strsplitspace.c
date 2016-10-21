/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 14:15:49 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/21 14:32:58 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nwords(const char *s)
{
	int	w;

	w = 0;
	while (*s)
	{
		while (ft_isspace(*s))
			s++;
		if (!*s)
			return (w);
		while (!ft_isspace(*s) && *s)
			s++;
		w++;
	}
	return (w);
}

char		**ft_strsplitspace(const char *s)
{
	char	**out;
	int		i;
	int		n;

	if (!(out = ft_memalloc(sizeof(char*) * (ft_nwords(s) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		n = 0;
		while (ft_isspace(*s))
			s++;
		if (!*s)
			break ;
		while (!ft_isspace(s[n]) && s[n])
			n++;
		if (!(out[i] = ft_strndup(s, n)))
			return (NULL);
		s += n;
		i++;
	}
	out[i] = NULL;
	return (out);
}
