/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:02:54 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/18 18:04:38 by cdesvern         ###   ########.fr       */
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
# include <sys/acl.h>
# include <sys/xattr.h>
# include <sys/syslimits.h>
# include <errno.h>
# include <stdio.h>
# include <time.h>

# define SIX_MONTH 15778458L

# define COL_DEF	";39"
# define COL_BLK	";30"
# define COL_RED	";31"
# define COL_GRN	";32"
# define COL_BRW	";33"
# define COL_BLU	";34"
# define COL_MAG	";35"
# define COL_CYA	";36"
# define COL_LGR	";37"
# define COL_END	"\e[0m"
# define LS_COLOR_DEFAULT "exfxcxdxbxegedabagacad"

# define OPT_LNG	0x000001//  l done
# define BY_SIZE	0x000002//  S done
# define OPT_SUF	0x000004//  F
# define OPT_INO	0x000008//  i
# define OPT_SLH	0x000010//  p
# define OPT_BLK	0x000020//  s
# define BY_TIME	0x000040//  t done
# define OPT_CLR	0x200000//  G

# define NO_SUPP	0x20003C//  F, i, p, G
# define NO_STAT	0x20007F//  t, l, S, F, i, p, s, G
# define GOT_PREFIX	0x000028//	i, s
# define OPT_REC	0x000080//  R done
# define OPT_ALL	0x000100//  a done
# define OPT_REV	0x000200//  r done
# define OPT_DIR	0x000400//  d
# define OPT_GRP	0x000800//  g done
# define NO_SORT	0x001000//  f done
# define BY_CTIME	0x002000//  U done
# define BY_ATIME	0x004000//  u done
# define BY_STIME	0x008000//  c done
# define OPT_SCOL	0x020000//  1 ~done
# define OPT_WTIME	0x040000//  T done

# define SML_ERR	0x010000//  if small error occur
# define MULTIARG	0x080000//  case multiple args
# define PRTD		0x100000//  Printed at least one line

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
	char			*i_link;
	char			*i_blocks;
	char			*i_color;
	char			*i_ino;
	char			*i_suff;
}					t_info;
typedef int			(*t_pcmp)(void *, void *);
typedef int			(*t_fstat)(const char *, struct stat *);
typedef void		(*t_print)(t_list **, int, unsigned int *);
typedef	t_info		*(*t_fetch)(char *, t_dirent *, int); 
typedef void		(*t_sfetch)(t_info *, int, char *);
typedef struct		s_util
{
	int				flag;
	t_pcmp			cmp;
	t_fstat			getstat;
	t_fetch			fetch;
	t_print			print;
	char			*lscol;
}					t_util;
int			usage(void);
void		get_util(t_util *util, int flag);
void		ls_erase_last_name(char *path, size_t len);
void		get_list(char *path, DIR *dir, t_util *util, t_list **plst);
void		ls_print(char *path, t_list **plst, t_util *util);
void		ls_del_node(void *content, size_t n);
void		ft_ls(char *path, DIR *dir, t_util *util);
int			ls_prelim(int ac, char **av, t_util *util);
t_list		**ls_multi_arg(char *path, char **av, t_util *util);
char		*get_type_n_rights(char *path,mode_t mode);
char		*get_usr(t_stat *st);
char		*get_grp(t_stat *st);
char		*get_blocks(t_stat *st);
char		*get_size(t_stat *st, int flag);
time_t		get_time(t_stat *st, int flag);
char		*get_date(t_stat *st, int flag);
blkcnt_t	ls_sum_blocks(t_list **plst);
t_info		*get_linfo(char *path, t_dirent *tdir, t_util *util);
t_info		*get_info(char *path, t_dirent *tdir, t_util *util);
char		*get_link(char *path);
void		ls_error(char *file);
void		icolor_error(char c);
char		*get_suff(mode_t mode, int flag);
char		*get_color(t_stat *stat, char *lscol);
void		color_error(char c);
t_pcmp		get_cmpfunction(int flag);
t_info		*fetch_info_simple(char *path, t_dirent *tdir, int flag);
t_info		*fetch_info_long(char *path, t_dirent *tdir, int flag);
void		fetch_info_supp(t_info *info, int flag, char *lscol);
int			ls_by_size(void *old, void *new);
int			ls_by_mtime(void *old, void *new);
int			ls_by_atime(void *old, void *new);
int			ls_by_stime(void *old, void *new);
int			ls_by_ctime(void *old, void *new);
int			ls_by_rsize(void *old, void *new);
int			ls_by_rmtime(void *old, void *new);
int			ls_by_ratime(void *old, void *new);
int			ls_by_rstime(void *old, void *new);
int			ls_by_rctime(void *old, void *new);
int			ls_by_name(void *old, void *new);
int			ls_by_rname(void *old, void *new);
void		ls_print_simple(t_list	**plst, int flag, unsigned int *pad);
void		ls_print_prefix(t_list **plst, int flag, unsigned int *pad);
void		ls_print_long(t_list **plst, int flag, unsigned int *pad);
void		ls_print_long_prefix(t_list **plst, int flag, unsigned int *pad);
void		ls_clrprint_long_prefix(t_list **plst, int flag, unsigned int *pad);
void		ls_clrprint_simple(t_list	**plst, int flag, unsigned int *pad);
void		ls_clrprint_prefix(t_list **plst, int flag, unsigned int *pad);
void		ls_clrprint_long(t_list **plst, int flag, unsigned int *pad);

#endif
