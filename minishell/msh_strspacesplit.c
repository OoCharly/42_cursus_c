/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strspacesplit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:09:57 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/08 16:35:40 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*next_word(char *str)
{
	char	quote;

	while(!ft_isspace(*str) && *str)
	{
		if (*str == '\\')
			if (!*(++str))
				return (str);
			else
				str++;
		else if (*str == '"' || *str == '\'')
		{
			quote = *str++;
			while (*str != quote)
			{
				if (*str == '\\')
					str++;
				str++;
			}
			str++;
		}
		else
			str++;
	}
	return (str);
}

static int	get_size(char *str)
{
	int	out;

	out = 0;
	while (*str)
	{
		while (ft_isspace(*str))
			str++;
		if (!*str)
			return out;
		out++;
		str = next_word(str);
	}
	return (out);
}

char		**msh_strspacesplit(char *str)
{
	int		nwords;
	int		i;
	char	**out;
	char	*cp;

	nwords = get_size(str);
	if (!(out = ft_memalloc(sizeof(char*) * (nwords + 1))))
		return (NULL);
	i = 0;
	while (i < nwords)
	{
		while (ft_isspace(*str))
			str++;
		if (!*str)
			break ;
		cp = next_word(str);
		if (!(out[i] = ft_strndup(str, cp - str)))
			return (NULL);
		str = cp;
		i++;
	}
	out[i] = NULL;
	return (out);
}
