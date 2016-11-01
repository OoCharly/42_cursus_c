/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_entry_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 17:03:13 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/01 17:42:16 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cmd_line_parser.h"

static int	clp_ignore(int fd, char *buff, char **out, int i)
{
	int		ret;
	char	*cp;

	if (buff[i + 1] == 0)
	{
		cp = *out;
		*out = ft_strjoin(*out, buff);
		if (cp)
			free(cp);
		ret = read(fd, buff, CLP_BUFFSIZE);
		buff[ret] = 0;
		return (1);
	}
	else
		return (i + 2);
}

static int	clp_nextquote(int fd, char *buff, char **out, int i)
{
	int		ret;
	char	*cp;
	char	delim;

	delim = buff[i++];
	while (buff[i] != delim)
	{
		if (buff[i] == '\\')
			i = clp_ignore(fd, buff, out, i);
		else if (buff[i] == 0)
		{
			cp = *out;
			*out = ft_strjoin(*out, buff);
			if (cp)
				free(cp);
			ret = read(fd, buff, CLP_BUFFSIZE);
			buff[ret] = 0;
			i = 0;
		}
		else
			i++;
	}
	return (i + 1);
}

static char	*clp_buildline(int fd, char *buff, char	**out, int i)
{
	char	*cp;

	buff[i] = 0;
	cp = *out;
	*out = ft_strjoin(*out, buff);
	if (cp)
		free(cp);
	ft_memmove(buff, buff + i + 1, CLP_BUFFSIZE - i - 1);
	return (*out);
}

static char	*clp_getline(int fd, char *buff, char **out)
{
	char	*cp;
	int		i;
	int		ret;

	i = 0;
	while (buff[i] != '\n')
	{
		if (buff[i] == '\\')
			i = clp_ignore(fd, buff, out, i);
		else if (buff[i] == '"' || buff[i] == '\'')
			i = clp_nextquote(fd, buff, out, i);
		else if (buff[i] == 0)
		{
			cp = *out;
			*out = ft_strjoin(*out, buff);
			if (cp)
				free(cp);
			ret = read(fd, buff, CLP_BUFFSIZE);
			buff[ret] = 0;
			i = 0;
		}
		else
			i++;
	}
	clp_buildline(fd, buff, out, i);
	return (*out);
}

int		ft_cmd_parser(int fd, char **line)
{
	static char	buff[CLP_BUFFSIZE + 1];
	int			ret;
	char		**out;

	if (!line || fd < 0)
		return (-1);
	if (!*buff)
	{
		ret = read(fd, buff, CLP_BUFFSIZE);
		if (ret == 0)
			return (-1);
		buff[ret] = 0;
	}
	if (!(out = ft_memalloc(sizeof(char*))))
		exit(-1);
	*line = clp_getline(fd, buff, out);
	free(out);
	return (1);
}
