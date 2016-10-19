/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 14:37:17 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/19 20:22:07 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_append_path(char *path, char *name)
{
	int	len;

	len = ft_strlen(path);
	ft_strcpy(&path[len], name);
	len += ft_strlen(name);
	path[len] = '\0';
}

void		ls_del_node(void *content, size_t n)
{
	t_info	*tmp;
	size_t	norme;

	norme = n;
	tmp = (t_info*)content;
	if (tmp->i_stat)
	{
		free(tmp->i_stat);
		free(tmp->i_perm);
		free(tmp->i_nlink);
		free(tmp->i_usr);
		free(tmp->i_grp);
		free(tmp->i_size);
		free(tmp->i_date);
		free(tmp->i_link);
	}
	free(tmp->i_blocks);
	free(tmp->i_name);
	if (tmp->i_color)
		free(tmp->i_color);
	if (tmp->i_ino)
		free(tmp->i_ino);
	free(content);
}

char		*get_link(char *path)
{
	char	*link;
	char	*out;

	if (!path)
	{
		if (!(out = ft_memalloc(sizeof(char))))
			exit(2);
		return (out);
	}
	if (!(link = ft_memalloc(sizeof(char) * NAME_MAX + 1)))
		exit(2);
	if ((readlink(path, link, NAME_MAX)) < 0)
	{
		perror(path);
		*link = 0;
	}
	out = ft_strjoin(" -> ", link);
	free(link);
	return (out);
}

void		ls_erase_last_name(char *path, size_t len)
{
	char	*slash;

	slash = ft_strrchr(path, '/');
	ft_memset(slash + 1, 0, len);
}

blkcnt_t	ls_sum_blocks(t_list **plst)
{
	long long int	out;
	t_list			*tmp;

	out = 0;
	tmp = *plst;
	while (tmp)
	{
		out += ((t_info*)tmp->content)->i_stat->st_blocks;
		tmp = tmp->next;
	}
	return (out);
}
