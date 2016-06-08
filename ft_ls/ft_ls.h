/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:02:54 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/08 19:20:43 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct dirent	t_dirent;

typedef struct		s_lsflag
{
	char			l : 1;
	char			R : 1;
	char			a : 1;
	char			t : 1;
	char			r : 1;
	void			*(f)();
}					t_lsflag;

typedef struct		s_path
{
	char			*p_name;
	struct s_path	*next;
	struct s_lsstat	*p_stats;
}

typedef struct		s_lsdir
{
	char			fn;
	struct stat		*ls_stat;
	struct s_lsdir	*next;
}					t_lsdir;



#endif
