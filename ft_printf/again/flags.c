/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:36:32 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/12 16:11:05 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*raz_flags(t_flag *flag)
{
	if (flag)
	{
		flag->alt = 0;
		flag->pad_0 = 0;
		flag->pad_left = 0;
		flag->signd = 0;
		flag->alt_size = 0;
		flag->sign_force = 0;
		flag->fw = 0;
		flag->precision = 0;
		flag->type = 0;
		flag->base = 10;
		return (flag);
	}
	else
	{
		flag = ft_memalloc(sizeof(t_flag));
		flag->base = 10;
		return (flag);
	}
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
