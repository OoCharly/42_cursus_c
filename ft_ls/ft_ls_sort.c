/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 13:26:21 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/08 18:37:58 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_by_name(t_lsdir *l_st, t_lsflag *f)
{
	char	*tmp;
	if (!l_st->next)
		return ;
	else
	{
		if ((f->r * -1) * ft_strcmp(l_st->fn, (l-st->next)->fn) > 0)
		{
			tmp = l_st->fn;
			l_st->fn = (l_st->next)->fn;
			(l_st->next)->fn = tmp;
		}
	}
}
