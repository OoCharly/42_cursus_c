/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:02:54 by cdesvern          #+#    #+#             */
/*   Updated: 2016/08/24 18:49:10 by cdesvern         ###   ########.fr       */
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
typedef struct stat		t_stat;
typedef struct passwd	t_pswd;
typedef struct group	t_grp;

typedef struct		s_flags
{
	int				f_accesstime : 1;
	int				f_grouponly : 2;
	int				f_longform : 1;
	int				f_listdot : 1;
	int				f_mtimesort : 1;
	int				f_recursive : 1;
	int				f_reversesort : 1;
	int				f_singlecol : 1;
}					t_flags;

typedef struct		s_info
{
	t_stat			i_stat;
	t_pswd			i_pswd;
	t_grp			i_grp;
	t_dirent		i_dirent;
}					t_info;

typedef struct		s_flag
{
	int				(sort)(t_info*, t_info*);
	t_info			(get_info)(char*);
	void			(render)(t_list*, char*);
}					t_flag;

#endif
