/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 17:48:31 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/08 19:20:51 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	get_finfo(t_lsdir **ldir, t_lsflag *f, DIR *dir)
{
	t_dirent	dd;
	t_lsdir		lsdir;

	while ((dd = readdir(dir)))
	{
		if (!(lsdir = ft_memalloc(sizeof(t_lsdir))))
			return ;
		if (!(lsdir->ls_stat = ft_memalloc(sizeof(struct stat))))
			return ;
		lsdir->fn = dd->d_name;
		lsdir->next = NULL;
		stat(dd->d_name, lsdir->lstat);


		

