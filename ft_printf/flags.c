/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:36:32 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/25 12:01:27 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*raz_flags(t_flag *flag)
{
	if (!flag)
	{
		if (!(flag = ft_memalloc(sizeof(t_flag))))
			exit(-1);
	}
	ft_memset(flag, 0, sizeof(flag));
	flag->precision = -1;
	flag->base = 10;
	return (flag);
}

char	*concat_full(t_list **list)
{
	char	*out;
	t_list	*tmp;

	if (!(out = ft_memalloc(ft_lstsumsize(list) + 1)))
		return (NULL);
	tmp = *list;
	while (tmp)
	{
		ft_strcat(out, (const char*)tmp->content);
		tmp = tmp->next;
	}
	return (out);
}
