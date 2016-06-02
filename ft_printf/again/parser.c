/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:58:50 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/02 19:54:41 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_arg_len(char *fmt, t_flag *flag)
{
	size_t	i;

	i = 1;
	while (fmt[i] && !ft_strchr(ARGS_LIST, fmt[i]))
	{
		if (!ft_strchr(FLAG_LIST, fmt[i]) && !ft_isdigit(fmt[i]))
		{
			flag->type = fmt[i];
			return (i);
		}
		i++;
	}
	flag->type = fmt[i];
	if (fmt[i] == '\0')
		return (i - 1);
	if (ft_strchr(SINTEGER_TYPE, flag->type))
		flag->signd = 1;
	return (i);
}

void	get_alt_size(char *fmt, t_flag *flag, int n)
{
	int	i;

	if ((i = ft_strnoccur(fmt, 'h', n)))
	{
		if (i % 2 == 0)
			flag->alt_size = -2;
		else
			flag->alt_size = -1;
	}
	if (ft_strchr(OBSOLETE_TYPE, fmt[n]))
		flag->alt_size = 1;
	if (ft_strnoccur(fmt, 'z', n))
		flag->alt_size = 4;
	else if (ft_strnoccur(fmt, 'j', n))
		flag->alt_size = 3;
	else if ((i = ft_strnoccur(fmt, 'l', n)))
	{
		if (i % 2 == 0)
			flag->alt_size = 2;
		else
			flag->alt_size = 1;
	}
}

void	reparse_flags(t_flag *f)
{
	if (f->fw < 0)
	{
		f->pad_left = 1;
		f->fw = -f->fw;
	}
	if (f->pad_left)
		f->pad_0 = 0;
	if (ft_strchr(INTEGER_TYPE, f->type) && f->precision >= 0
			&& f->type)
		f->pad_0 = 0;
}

int		ft_parse_em_all(char *fmt, va_list ap, t_list **list)
{
	int		len;
	char	*tmp;
	t_flag	*flag;
	int		wildcase;

	flag = new_flag();
	len = get_arg_len(fmt, flag);
	get_alt_size(fmt, flag, len);
	ft_printf_field_parser(fmt, ap, flag, len);
	reparse_flags(flag);
	tmp = ft_process(flag, ap);
	wildcase = (flag->precision == -2) ? 1 : 0;
	ft_lstadd_end(list, ft_lstcreate(tmp, ft_strlen(tmp) + wildcase));
	free(flag);
	return (len);
}
