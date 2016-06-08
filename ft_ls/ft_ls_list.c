/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 17:58:28 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/08 19:20:33 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_insert_cond(t_lsdir *in, t_lsdir **ldir, t_lsflag *f)
{
	t_lsdir	*tmp;

	tmp = *ldir;
	if (tmp)
	{
		while (tmp->next)
		{
			if ((*f->test)(in, tmp->next) < 0)
			{
				in->next = tmp->next;
				tmp->next = in;
				return ;
			}
			tmp = tmp->next;
		}
		tmp->next = in;
		return ;
	}
	*ldir = in;
}

void	ft_get_path(t_path *path, char *dname)
{
	t_path	new;
	char	*tmp;

	if (!(new = ft_memalloc(sizeof(t_path))))
		return ;
	path->next = new;
	tmp = ft_strjoin(path->p_name, "/");
	new->p_name = ft_strjoin(tmp, dname);
	free(tmp);
}

