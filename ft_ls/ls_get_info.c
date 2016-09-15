/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 15:36:07 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/15 16:07:35 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_util(int flag, t_pcmp cmp, t_util *util)
{
	util->cmp = cmp;
	util->flag = flag;
	if (!(flag & NO_STAT))
		util->getstat = NULL;
	else
		util->getstat = &lstat;
}

t_info	*get_linfo(char *path, t_dirent *tdir, t_util *util)
{
	t_info	*out;
	t_stat	*stat;
	int		flag;
	char *wtf;

	flag = util->flag;
	(out = ft_memalloc(sizeof(t_info))) ? : exit(2);
	out->i_name = (tdir) ? ft_strdup(tdir->d_name) : ft_strdup(path);
	out->i_len = (tdir) ? tdir->d_namlen : ft_strlen(path);
	if (!(stat = ft_memalloc(sizeof(t_stat))))
		exit (2);
	(*(util->getstat))(path, stat);
	out->i_perm = get_type_n_rights(path, stat->st_mode);
	out->i_nlink = ft_ntoa_base((uintmax_t)stat->st_nlink, 10);
	out->i_usr = get_usr((flag & OPT_GRP) ? NULL : stat);
	out->i_grp = get_grp(stat);
	out->i_size = get_size(stat, flag);
	out->i_date = get_date(stat, flag);
	out->i_blocks = stat->st_blocks;
	out->i_stat = stat;
	out->i_link = get_link((*(out->i_perm) == 'l') ? path : NULL);
	return (out);
}

t_info	*get_info(char *path, t_dirent *tdir, t_util *util)
{
	t_info	*out;
	t_stat	*stat;
	t_fstat	fstat;

	(out = ft_memalloc(sizeof(t_info))) ? : exit (2);
	out->i_name = (tdir) ? ft_strdup(tdir->d_name) : ft_strdup(path);
	out->i_len = (tdir) ? tdir->d_namlen : ft_strlen(path);
	out->i_stat = NULL;
	out->i_perm = NULL;
	out->i_nlink = NULL;
	out->i_usr = NULL;
	out->i_grp = NULL;
	out->i_size = NULL;
	out->i_date = NULL;
	out->i_link = NULL;
	return (out);
}

int		get_list(char *path, DIR *dir, t_util *util, t_list **plst)
{
	t_list		*new;
	t_dirent	*tdir;
	t_info		*(*get)(char *, t_dirent*, t_util*);	
	t_pcmp		cmp;
	int			flag;

	flag = util->flag;
	cmp = util->cmp;
	get = (flag & NO_STAT) ? &get_linfo : &get_info;
	while ((tdir = readdir(dir)))
		if ((flag & OPT_ALL) || (*(tdir->d_name) != '.'))
		{
			path = ft_strcat(path, tdir->d_name);
			if (!(new = ft_lstcreate((*get)(path, tdir, util), sizeof(t_info))))
				exit (2);
			ft_lstsort(plst, new, cmp);
			ls_erase_last_name(path, (size_t)tdir->d_namlen);
		}
	return (0);
}
