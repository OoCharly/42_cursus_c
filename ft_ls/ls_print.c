/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 11:29:46 by cdesvern          #+#    #+#             */
/*   Updated: 2016/10/19 20:41:14 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		repad(unsigned int *pad, int flag)
{
	pad[0] += (pad[0] && pad[6]);
	pad[1]++;
	pad[2] += (flag & (OPT_USR | OPT_GRP)) ? 0 : 2;
	pad[4] += 2;
	pad[5]++;
}

unsigned int	*get_padding(t_list **plst)
{
	unsigned int		*pad;
	t_list				*cplst;
	t_info				*tmp;

	if (!(pad = ft_memalloc(sizeof(int) * 8)))
		exit(2);
	cplst = *plst;
	while (cplst)
	{
		tmp = cplst->content;
		pad[0] = (unsigned int)ft_umax(ft_strlen(tmp->i_blocks), pad[0]);
		pad[1] = (unsigned int)ft_umax(ft_strlen(tmp->i_nlink), pad[1]);
		pad[2] = (unsigned int)ft_umax(ft_strlen(tmp->i_usr), pad[2]);
		pad[3] = (unsigned int)ft_umax(ft_strlen(tmp->i_grp), pad[3]);
		pad[4] = (unsigned int)ft_umax(ft_strlen(tmp->i_size), pad[4]);
		pad[5] = (unsigned int)ft_umax(ft_strlen(tmp->i_date), pad[5]);
		pad[6] = (unsigned int)ft_umax(ft_strlen(tmp->i_ino), pad[6]);
		pad[7] = (unsigned int)ft_umax(ft_strlen(tmp->i_suff), pad[7]);
		cplst = cplst->next;
	}
	return (pad);
}

void			ls_print(char *path, t_list **plst, t_util *util)
{
	int				flag;
	unsigned int	*pad;
	t_print			print;

	flag = util->flag;
	pad = get_padding(plst);
	repad(pad, flag);
	print = util->print;
	if (*path && ((flag & (OPT_LNG | OPT_BLK))) && !(flag & OPT_DIR))
		ft_printf("total %lld\n", ls_sum_blocks(plst));
	(*print)(plst, pad);
	free(pad);
	util->flag |= (PRTD | MULTIARG);
}
