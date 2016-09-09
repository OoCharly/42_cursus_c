/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 15:36:07 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/09 13:53:58 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void	ls_erase_last_name(char *path, size_t len)
{
	char	*slash;

	slash = ft_strrchr(path, '/');
	ft_memset(slash + 1, 0, len);
}

t_info	*get_linfo(char *path, t_dirent *tdir, t_util *util)
{
	t_info	*out;
	t_stat	*stat;
	t_fstat *fstat;
	int		flag;

	flag = util->flag;
	(out = ft_memalloc(sizeof(t_info))) ? : exit(2);
	out->i_name = tdir->d_name;
	out->i_len = tdir->d_namlen;
	if (!(stat = ft_memalloc(sizeof(t_stat))))
		exit (2);
	out->i_stat = (*fstat)(path, stat);
	out->i_perm = get_type_n_rights(path, out->st_mode);
	out->i_nlink = ft_ntoa_base((uintmax_t)stat->nlink, 10);
	out->i_usr = (flag & OPT_GRP) ? NULL : get_usr(stat);
	out->i_grp = get_grp(stat);
	out->i_size = get_size(stat, flag);
	out->i_date = get_date(stat, flag);
	out->i_blocks = stat->st_blocks;
}

t_info	*get_info(char *path, t_dirent *tdir, t_util *util)
{
	t_info	*out;
	t_stat	*stat;
	t_fstat	fstat;	

	(out = ft_memalloc(sizeof(t_info))) ? continue : exit (2);
	out->i_name = tdir->d_name;
	out->i_len = tdir->d_namlen;
	out->i_stat = NULL;
	out->i_perm = NULL;
	out->i_nlink = NULL;
	out->i_usr = NULL;
	out->i_grp = NULL;
	out->i_size = NULL;
	out->i_date = NULL;
	return (out);
}

int		get_list(char *path, DIR *dir, t_util *util, t_list **plst)
{
	t_list		*new;
	t_dirent	*tdir;
	t_info		*info;
	t_pcmp		cmp;
	int			flag;

	flag = util->flag;
	cmp = util->cmp;
	while ((tdir = readdir(dir)))
	{
		if ((flag & OPT_ALL) || (*(tdir->d_name) != '.'))
		{
			path = ft_strcat(path, tdir->d_name);
			if((info = get_info(path, tdir, util)))
			{
				if (!(new = ft_lstnew(info, sizeof(*info))))
					exit (2);
				ft_lstsort(plst, new, cmp);
			}
			ls_erase_last_name(path, (size_t)tdir->d_namlen);
		}
	}
	return (0);
}
