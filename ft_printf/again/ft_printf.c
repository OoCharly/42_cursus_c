/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:47:23 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/25 17:12:34 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_do_stuff(char *fmt, va_list ap, t_flag *flag, t_list **lst)
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
			fmt = pc + ft_parse_em_all(pc, ap, flag, lst) + 1;
		}
		else
		{
			fmt += ft_parse_em_all(pc, ap, flag, lst) + 1;
		}
	}
}

int		ft_printf(char *fmt, ...)
{
	va_list	ap;
	t_list	**lst;
	t_flag	*flag;
	int		out;
	char	*all;

	flag = NULL;
	lst = ft_memalloc(sizeof(t_list*));
	va_start(ap, fmt);
	ft_do_stuff(fmt, ap, flag, lst);
	va_end(ap);
	print_lst(*lst);
	all = concat_full(lst);
	out = ft_lstsumsize(lst);
	write(1, all, out);
	
	return (out);
}
