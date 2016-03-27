/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 19:27:18 by cdesvern          #+#    #+#             */
/*   Updated: 2016/03/27 19:14:22 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# define BUFF_SIZE 32

typedef struct		s_mem
{
	char		*buff;
	int			nb_nline;
	int			last_read;
	int			fd;
	int			next_nl;
}			t_mem;

int				get_next_line(const int fd, char **line);

#endif
