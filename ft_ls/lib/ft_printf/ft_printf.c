/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:47:23 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/06 10:59:00 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag			*ft_printf_new_flag(void)
{
	t_flag	*flag;

	if (!(flag = ft_memalloc(sizeof(t_flag))))
		exit(-1);
	ft_memset(flag, 0, sizeof(*flag));
	flag->precision = -1;
	flag->base = 10;
	return (flag);
}

static	size_t	ft_concat_full(t_list **list, char *buff)
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

static	void	ft_get_fmt(char *fmt, va_list ap, t_list **lst)
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
			res = ft_printf_parse(pc, ap, lst);
			fmt = pc + res + 1;
		}
		else
		{
			fmt += ft_printf_parse(pc, ap, lst) + 1;
		}
	}
}

static	void	ft_print(t_list **lst)
{
	char	*buff;
	size_t	r;

	buff = ft_memalloc(BUFF_SIZE);
	while ((r = ft_concat_full(lst, buff)))
		write(1, buff, r);
	free(buff);
	free(lst);
}

int				ft_printf(char *fmt, ...)
{
	va_list	ap;
	t_list	**lst;
	int		out;

	lst = ft_memalloc(sizeof(t_list*));
	va_start(ap, fmt);
	ft_get_fmt(fmt, ap, lst);
	va_end(ap);
	out = ft_lstsumsize(lst);
	ft_print(lst);
	return (out);
}
