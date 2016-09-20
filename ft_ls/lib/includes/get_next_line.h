/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 19:27:18 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/09 09:54:00 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 1024

typedef struct		s_mem
{
	char			*buff;
	int				nb_nline;
	int				last_read;
	int				fd;
	int				next_nl;
}					t_mem;

int					get_next_line(const int fd, char **line);

#endif
