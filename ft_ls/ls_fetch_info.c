/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fetch_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:42:15 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/18 15:56:19 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_attr(char *path, char *out)
{
	acl_t	acl;

	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
		*out = '@';
	else if((acl = acl_get_file(path, ACL_TYPE_EXTENDED)))
	{
		*out = '+';
		acl_free(acl);
	}
	else
		*out = ' ';
}

void	get_rights(mode_t mode, char *out)
{
	*out++ = (mode & S_IRUSR) ? 'r' : '-';
	*out++ = (mode & S_IWUSR) ? 'w' : '-';
	if (mode & S_ISUID)
		*out++ = (mode & S_IXUSR) ? 's' : 'S';
	else
		*out++ = (mode & S_IXUSR) ? 'x' : '-';
	*out++ = (mode & S_IRGRP) ? 'r' : '-';
	*out++ = (mode & S_IWGRP) ? 'w' : '-';
	if (mode & S_ISGID)
		*out++ = (mode & S_IXGRP) ? 's' : 'S';
	else
		*out++ = (mode & S_IXGRP) ? 'x' : '-';
	*out++ = (mode & S_IROTH) ? 'r' : '-';
	*out++ = (mode & S_IWOTH) ? 'w' : '-';
	if (mode & S_ISVTX)
		*out++ = (mode & S_IXOTH) ? 't' : 'T';
	else
		*out++ = (mode & S_IXOTH) ? 'x' : '-';
}

char	*get_type_n_rights(char *path, mode_t mode)
{
	char	*out;

	if (!(out = ft_memalloc(sizeof(char) * 12)))
		exit(2);
	if (S_ISBLK(mode))
		*out = 'b';
	else if (S_ISCHR(mode))
		*out = 'c';
	else if (S_ISDIR(mode))
		*out = 'd';
	else if (S_ISLNK(mode))
		*out = 'l';
	else if (S_ISSOCK(mode))
		*out = 's';
	else if (S_ISFIFO(mode))
		*out = 'p';
	else if (S_ISREG(mode))
		*out = '-';
	get_rights(mode, out + 1);
	get_attr(path, out + 10);
	return (out);
}

t_info	*fetch_info_simple(char *path, t_dirent *tdir, int flag)
{
	t_info	*out;
	t_stat	*stat;
	t_fstat	fstat;

	(out = ft_memalloc(sizeof(t_info))) ? : exit (2);
	out->i_name = (tdir) ? ft_strdup(tdir->d_name) : ft_strdup(path);
	out->i_len = (tdir) ? tdir->d_namlen : ft_strlen(path);
	return (out);
}

t_info	*fetch_info_long(char *path, t_dirent *tdir, int flag)
{
	t_info	*out;
	t_stat	*stat;

	(out = ft_memalloc(sizeof(t_info))) ? : exit(2);
	if (!(stat = ft_memalloc(sizeof(t_stat))))
		exit (2);
	lstat(path, stat);
	out->i_perm = get_type_n_rights(path, stat->st_mode);
	out->i_nlink = ft_ntoa_base((uintmax_t)stat->st_nlink, 10);
	out->i_usr = get_usr(stat);
	out->i_grp = get_grp(stat);
	out->i_size = get_size(stat, flag);
	out->i_date = get_date(stat, flag);
	out->i_stat = stat;
	out->i_link = get_link((*(out->i_perm) == 'l') ? path : NULL);
	out->i_name = (tdir) ? ft_strdup(tdir->d_name) : ft_strdup(path);
	out->i_len = (tdir) ? tdir->d_namlen : ft_strlen(path);
	return (out);
}
