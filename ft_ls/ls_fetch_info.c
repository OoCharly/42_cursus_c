/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fetch_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:42:15 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/29 18:58:43 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info	*fetch_info_simple(char *path, t_dirent *tdir, int flag)
{
	t_info	*out;
	t_stat	*stat;
	t_fstat	fstat;

	(out = ft_memalloc(sizeof(t_info))) ? : exit (2);
	out->i_name = (tdir) ? ft_strdup(tdir->d_name) : ft_strdup(path);
	out->i_len = (tdir) ? tdir->d_namlen : ft_strlen(path);
	out->i_blocks = get_blocks((util->flag & OPT_BLK) ? stat : NULL);
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

void	*fetch_info_sup(t_info *info, int flag)
{
	t_stat	*stat;

	stat = info->i_stat;
	info->i_blocks = get_blocks((flag & OPT_BLK) ? stat : NULL);
	info->i_suff = get_suff(stat->st_mode, flag)
	info->i_ino = get_ino((flag & OPT_INO) ? stat : NULL);
	info->color = get_color((flag & OPT_CLR) ? stat : NULL);
}
