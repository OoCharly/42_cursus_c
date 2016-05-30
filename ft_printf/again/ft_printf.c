/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:47:23 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/30 17:57:38 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_do_stuff(char *fmt, va_list ap, t_list **lst)
{
	char	*pc;
	t_list	*tmp;
	int		res;

	while (*fmt)
	{
		pc = ft_strchr(fmt, '%');
		if (!pc)
		{
			tmp = ft_lstcreate(ft_strdup(fmt), ft_strlen(fmt));
			ft_lstadd_end(lst, tmp);
			return ;
		}
		else if (pc > fmt)
		{
			tmp = ft_lstcreate(ft_strndup(fmt, pc - fmt), pc - fmt);
			ft_lstadd_end(lst, tmp);
			fmt = pc + ft_parse_em_all(pc, ap, lst) + 1;
		}
		else
		{
			fmt += ft_parse_em_all(pc, ap, lst) + 1;
		}
	}
}

int		ft_printf(char *fmt, ...)
{
	va_list	ap;
	t_list	**lst;
	int		out;
	char	*all;

	lst = ft_memalloc(sizeof(t_list*));
	va_start(ap, fmt);
	ft_do_stuff(fmt, ap, lst);
	va_end(ap);
	all = concat_full(lst);
	out = ft_lstsumsize(lst);
	write(1, all, out);
	free(all);
	ft_lstdel(lst, *ft_del_node);
	free(lst);
	return (out);
}
