/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_strsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:00:20 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/18 18:24:20 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*next_word(char *str, char c)
{
	char	quote;

	while (*str != c && *str)
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

static int	get_size(char *str, char c)
{
	int	out;

	out = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (!*str)
			return (out);
		out++;
		str = next_word(str, c);
	}
	return (out);
}

char		**msh_strsplit(char *str, char c)
{
	int		nwords;
	int		i;
	char	**out;
	char	*cp;

	nwords = get_size(str, c);
	if (!(out = ft_memalloc(sizeof(char*) * (nwords + 1))))
		return (NULL);
	i = 0;
	while (i < nwords)
	{
		while (*str == c)
			str++;
		if (!*str)
			break ;
		cp = next_word(str, c);
		if (!(out[i] = ft_strndup(str, cp - str)))
			return (NULL);
		i++;
		str = cp;
	}
	out[i] = NULL;
	return (out);
}

void		msh_strstrip(char *str)
{
	char	quote;

	while (*str)
	{
		if (*str == '\\')
			ft_memmove(str, str + 1, ft_strlen(str + 1) + 1);
		else if (*str == '\'' || *str == '"')
		{
			quote = *str;
			ft_memmove(str, str + 1, ft_strlen(str + 1) + 1);
			ft_putendl(str);
			while (*str != quote)
			{
				if (*str == '\\')
					ft_memmove(str, str + 1, ft_strlen(str + 1) + 1);
				str++;
			}
			ft_memmove(str, str + 1, ft_strlen(str + 1) + 1);
		}
		str++;
	}
}
