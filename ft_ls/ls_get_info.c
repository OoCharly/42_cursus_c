/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 15:36:07 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/19 19:58:36 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_relevance(char *name, int flag)
{
	if (flag & OPT_ALL)
		return (1);
	if (*name == '.')
	{
		if (!(flag & OPT_AAL))
			return (0);
		else if (!ft_strcmp(name, ".") || !ft_strcmp(name, ".."))
			return (0);
		else
			return (1);
	}
	return (1);
}

void	fetch_info_supp(t_info *info, int flag, char *lscol)
{
	t_stat	*stat;

	stat = info->i_stat;
	if (flag & OPT_BLK)
		info->i_blocks = ft_ntoa_base((uintmax_t)stat->st_blocks, 10);
	else
		info->i_blocks = NULL;
	if (flag & (OPT_SUF | OPT_SLH))
		info->i_suff = get_suff(stat->st_mode, flag);
	else
		info->i_suff = 0;
	info->i_ino = (flag & OPT_INO) ? ft_ntoa((uintmax_t)stat->st_ino) : NULL;
	info->i_color = (flag & OPT_CLR) ? get_color(stat, lscol) : NULL;
}

void	get_only_dir(char *path, DIR *dir, t_util *util, t_list **plst)
{
	t_list		*new;
	int			flag;

	flag = util->flag;
	if (!(new = ft_lstcreate((*(util->fetch))(path, NULL, util->flag),
											sizeof(t_info))))
		exit(2);
	*plst = new;
	if (flag & NO_SUPP)
		fetch_info_supp((t_info*)(new->content), flag, util->lscol);
	closedir(dir);
}

void	get_list(char *path, DIR *dir, t_util *util, t_list **plst)
{
	t_list		*new;
	t_dirent	*tdir;
	t_fetch		fetch;
	t_pcmp		cmp;
	int			flag;

	flag = util->flag;
	if (flag & OPT_DIR)
		return (get_only_dir(path, dir, util, plst));
	cmp = util->cmp;
	fetch = util->fetch;
	while ((tdir = readdir(dir)))
		if (ls_relevance(tdir->d_name, flag))
		{
			ft_strcat(path, tdir->d_name);
			if (!(new = ft_lstcreate((*fetch)(path, tdir, flag),
											sizeof(t_info))))
				exit(2);
			ft_lstsort(plst, new, cmp);
			if (flag & NO_SUPP)
				fetch_info_supp((t_info*)(new->content), flag, util->lscol);
			ls_erase_last_name(path, (size_t)tdir->d_namlen);
		}
	closedir(dir);
}
