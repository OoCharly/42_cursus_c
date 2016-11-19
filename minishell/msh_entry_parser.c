/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_entry_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 17:03:13 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/19 14:19:45 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	clp_ignore(int fd, char *buff, char **out, int *i)
{
	int		ret;

	if (buff[*i + 1] == 0)
	{
		*out = ft_strfjoin(*out, buff, 1);
		if ((ret = read(fd, buff, CLP_BUFFSIZE)) == 0)
			return (CLP_FLUSH);
		buff[ret] = 0;
		*i = 1;
		return (0);
	}
	else
	{
		*i += 2;
		return (0);
	}
}

static int	clp_nextquote(int fd, char *buff, char **out, int *i)
{
	int		ret;
	char	delim;

	delim = buff[(*i)++];
	while (buff[*i] != delim)
	{
		if (buff[*i] == '\\')
		{
			ret = clp_ignore(fd, buff, out, i);
			if (ret)
				return (CLP_FLUSH);
		}
		else if (buff[*i] == 0)
		{
			*out = ft_strfjoin(*out, buff, 1);
			if ((ret = read(fd, buff, CLP_BUFFSIZE)) == 0)
				return (CLP_FLUSH);
			buff[ret] = 0;
			*i = 0;
		}
		else
			(*i)++;
	}
	(*i)++;
	return (0);
}

static char	*clp_buildline(char *buff, char **out, int i)
{
	buff[i] = 0;
	*out = ft_strfjoin(*out, buff, 1);
	ft_memmove(buff, buff + i + 1, CLP_BUFFSIZE - i - 1);
	return (*out);
}

static int	clp_getline(int fd, char *buff, char **out)
{
	int		i;
	int		ret;

	i = 0;
	while (buff[i] != '\n')
		if (buff[i] == '\\' || buff[i] == '"' || buff[i] == '\'')
		{
			ret = (buff[i] == '\\') ? clp_ignore(fd, buff, out, &i) :
									clp_nextquote(fd, buff, out, &i);
			if (ret)
				return (CLP_FLUSH);
		}
		else if (buff[i] == 0)
		{
			*out = ft_strfjoin(*out, buff, 1);
			ret = read(fd, buff, CLP_BUFFSIZE);
			if (ret == 0)
				return (CLP_FLUSH);
			buff[ret] = 0;
			i = 0;
		}
		else
			i++;
	clp_buildline(buff, out, i);
	return (1);
}

int			msh_cmd_parser(int fd, char **line)
{
	static char	buff[CLP_BUFFSIZE + 1];
	int			ret;

	if (!line || fd < 0)
		return (-1);
	if (!*buff)
	{
		ret = read(fd, buff, CLP_BUFFSIZE);
		if (ret == 0)
			return (-1);
		buff[ret] = 0;
	}
	ret = clp_getline(fd, buff, line);
	return (ret);
}
