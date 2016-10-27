/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:29:18 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/27 18:10:56 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

staticic char	*clp_getline(int fd, char *buff)
{
	int		i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\\')
			i += clp_ignore(fd, buff);
		else if (buff[i] == '"')
			i += clp_nextquote(fd, buff);
		else if (buff[i] == '\n')
			return (clp_buildline(buff));
		else
			i++;
	}
}

int		ft_cmd_parser(int fd, char **line)
{
	static char	buff[CLP_BUFFSIZE + 1];
	int			ret;
	char		*out;

	if (!line || fd < 0)
		return (-1);
	if (!*buff)
	{
		ret = read(fd, buff, CLP_BUFFSIZE);
		if (ret = 0)
			return (-1);
		buff[ret] = 0;
	}
	out = clp_getline(fd, buff);
	*line = out;
	return (1);
}
