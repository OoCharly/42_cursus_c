/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:02:54 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/15 17:34:52 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct dirent	t_dirent;

typedef struct		s_file
{
	char			*fn;
	struct stat		*ls_stat;
}					t_file;

typedef struct		s_lsflag
{
	char			l : 1;
	char			R : 1;
	char			a : 1;
	char			t : 1;
	char			r : 1;
	void			*(test)(t_file*, t_file*, int);
}					t_lsflag;
#endif
