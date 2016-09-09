/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:02:54 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/09 16:40:29 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <stdio.h>
# include <time.h>

# define SIX_MONTH 15778458L

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
# define OPT_WTIME 0x40000// T

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
typedef struct passwd	t_pwd;
typedef struct group	t_grp;
typedef struct		s_info
{
	char			*i_name;
	size_t			i_len;
	t_stat			*i_stat;
	char			*i_perm;
	char			*i_nlink;
	char			*i_usr;
	char			*i_grp;
	char			*i_size;
	char			*i_date;
	blkcnt_t		i_blocks;
}					t_info;
typedef int				(*t_pcmp)(t_info *, t_info *);
typedef int			(*t_fstat)(const char *, struct stat *);
typedef struct		s_util
{
	int				flag;
	t_pcmp			cmp;
	t_fstat			getstat;
}					t_util;

void	ls_erase_last_name(char *path, size_t len);
int		get_list(char *path, DIR *dir, t_util *util, t_list **plst);
void	ls_print(char *path, t_list **plst, t_util *util);
void	ls_del_node(void *content, size_t n);
int		ft_ls(char *path, DIR *dir, t_util *util);
int		ls_prelim(int ac, char **av, t_util **util);
t_list			**ls_multi_arg(char **av, t_util *util);
void	ls_free_util(t_util **util);
#endif
