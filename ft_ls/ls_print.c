/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 11:29:46 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/21 17:43:27 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_attr(char *path, char *out)
{
	acl_t	acl;

	if ((acl = acl_get_file(path, ACL_TYPE_EXTENDED)))
	{
		*out = '+';
		acl_free(acl);
	}
	else if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
		*out = '@';
	else
		*out = 0;
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

unsigned int		*get_padding(int flag, t_list **plst)
{
	unsigned int		*pad;
	t_list				*cplst;
	t_info				*tmp;

	(pad = ft_memalloc(sizeof(int) * 7)) ? : exit(2);
	cplst = *plst;
	while (cplst)
	{
		tmp = cplst->content;
		pad[0] = (unsigned int)ft_umax(ft_strlen(tmp->i_perm), pad[0]);
		pad[1] = (unsigned int)ft_umax(ft_strlen(tmp->i_nlink), pad[1]);
		pad[2] = (unsigned int)ft_umax(ft_strlen(tmp->i_usr), pad[2]);
		pad[3] = (unsigned int)ft_umax(ft_strlen(tmp->i_grp), pad[3]);
		pad[4] = (unsigned int)ft_umax(ft_strlen(tmp->i_size), pad[4]);
		pad[5] = (unsigned int)ft_umax(ft_strlen(tmp->i_date), pad[5]);
		pad[6] = (unsigned int)ft_umax(ft_strlen(tmp->i_blocks), pad[6]);
		cplst = cplst->next;
	}
	return (pad);
}

void	ls_print_simple(t_list **plst, int flag, unsigned int *pad)
{
	t_list	*tmp;
	int		blk;

	blk = (flag & OPT_BLK) ? 1 : 0;
	if (blk)
		ft_printf("total %lld\n", ls_sum_blocks(plst));
	tmp = *plst;
	while (tmp)
	{
		ft_printf("%*s%.*s%s\n", pad[6], ((t_info*)tmp->content)->i_blocks,
							blk, " ", ((t_info *)tmp->content)->i_name);
		tmp = tmp->next;
	}
}

void	ls_print_long(t_list **plst, int flag, unsigned int *pad)
{
	t_list	*tmp;
	t_info	*cpinfo;
	int		grp;

	grp = (flag & OPT_GRP) ? 0 : 2;
	tmp = *plst;
	while (tmp)
	{
		cpinfo = tmp->content;
		ft_printf("%*s%.*s%-*s%*s %-*s%-*s%*s%*s %s%s\n", 
				pad[6], cpinfo->i_blocks,
				(flag & OPT_BLK), " ",
				pad[0] + 1, cpinfo->i_perm,
				pad[1] + 1, cpinfo->i_nlink,
				pad[2] + grp, cpinfo->i_usr,
				pad[3], cpinfo->i_grp,
				pad[4] + 2, cpinfo->i_size,
				pad[5] + 1, cpinfo->i_date,
				cpinfo->i_name, cpinfo->i_link);
		tmp = tmp->next;
	}
}

void	ls_print(char *path, t_list **plst, t_util *util)
{
	int				flag;
	unsigned int	*pad;

	pad = get_padding(flag, plst);
	flag = util->flag;
	if (!(flag & OPT_LNG))
		ls_print_simple(plst, flag, pad);
	else
	{
		if (*path)
			ft_printf("total %lld\n", ls_sum_blocks(plst));
		ls_print_long(plst, flag, pad);
	}
	free(pad);
	util->flag |= (PRTD | MULTIARG);
}
