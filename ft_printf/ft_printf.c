/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:47:23 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/02 19:01:50 by cdesvern         ###   ########.fr       */
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
			res = ft_parse_em_all(pc, ap, lst);
			fmt = pc + res + 1;
		}
		else
		{
			fmt += ft_parse_em_all(pc, ap, lst) + 1;
		}
	}
}

void	ft_print(t_list **lst)
{
	char	*buff;
	size_t	r;

	buff = ft_memalloc(BUFF_SIZE);
	while ((r = ft_concat_full(lst, buff)))
		write(1, buff, r);
	free(buff);
	free(lst);
}

int		ft_printf(char *fmt, ...)
{
	va_list	ap;
	t_list	**lst;
	int		out;

	lst = ft_memalloc(sizeof(t_list*));
	va_start(ap, fmt);
	ft_do_stuff(fmt, ap, lst);
	va_end(ap);
	out = ft_lstsumsize(lst);
	ft_print(lst);
	return (out);
}
