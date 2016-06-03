/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:36:32 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/03 18:24:16 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*new_flag(void)
{
	t_flag	*flag;

	if (!(flag = ft_memalloc(sizeof(t_flag))))
		exit(-1);
	ft_memset(flag, 0, sizeof(*flag));
	flag->precision = -1;
	flag->base = 10;
	return (flag);
}

size_t	ft_concat_full(t_list **list, char *buff)
{
	t_list	*tmp;
	size_t	ret;

	ret = 0;
	if (!*list)
		return (0);
	while (*list && ret < BUFF_SIZE)
	{
		tmp = *list;
		if (tmp->content_size < (BUFF_SIZE - ret))
		{
			ft_memcpy((buff + ret), tmp->content, tmp->content_size);
			ret += tmp->content_size;
			ft_lstdelfst(list, &ft_del_node);
		}
		else
		{
			ft_memcpy((buff + ret), tmp->content, (BUFF_SIZE - ret));
			ret = BUFF_SIZE;
			ft_memmove(tmp->content, tmp->content, (BUFF_SIZE - ret));
			tmp->content_size -= (BUFF_SIZE - ret);
			return (ret);
		}
	}
	return (ret);
}
