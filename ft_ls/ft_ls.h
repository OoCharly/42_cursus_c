/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:02:54 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/01 18:10:52 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/types.h>
# include <sys/stat.h>

# define OPT_LNG 0x0001 //  l
# define BY_SIZE 0x0002 //  S
# define OPT_SUF 0x0004 //  F
# define OPT_INO 0x0008 //  i
# define OPT_SLH 0x0010 //  p
# define OPT_BLK 0x0020 //  s
# define BY_TIME 0x0040 //  t
# define NO_STAT 0x007F //  case no t,l,S,F,i,p or s
# define OPT_REC 0x0080 //  R
# define OPT_ALL 0x0100 //  a
# define OPT_REV 0x0200 //  r
# define OPT_DIR 0x0400 //  d
# define OPT_GRP 0x0800 //  g
# define NO_SORT 0x1000 //  f
# define BY_CTIME 0x2000//  U
# define BY_ATIME 0x4000//  u
# define BY_STIME 0x8000//  c
# define SML_ERR 0x10000//  if small error occur
# define BIG_ERR 0x20000//  if big error occur

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
typedef struct passwd	t_pswd;
typedef struct group	t_grp;
typedef struct		s_info
{
	char			*name;
	size_t			len;
	t_stat			*i_stat;
}					t_info;
typedef int				(*t_pcmp)(t_info *, t_info *);
typedef t_stat			(*t_fstat)(const char *, struct stat *);
typedef struct		s_util
{
	int				flag;
	t_pcmp			cmp;
	t_fstat			getstat;
}					t_util;

#endif
