/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:58:50 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/06 18:34:18 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_arg_len(char *fmt, t_flag *flag)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*fmt == '%')
		return (0);
	while (fmt[i] && !ft_strchr(TYPE_LIST, fmt[i]))
	{
		if (!ft_strchr(FLAG_LIST, fmt[i]) && !isdigit(fmt[i]))
			return (-1);
		i++;
	}
	if (fmt[i] == '\0')
		return (-1);
	if (fmt[i] == 'o' || fmt[i] == 'O')
		flag->base = 8;
	else if (fmt[i] == 'x' || fmt[i] == 'X' || fmt[i] == 'p')
		flag->base = 16;
	else if (fmt[i] == 'b')
		flag->base = 2;
	return (i);
}

void	parse_width(char *fmt, t_flag *flag, va_list *ap, int n)
{
	int	i;
	char	*tmp;

	i = 0;
	if (tmp = ft_strnrchr(fmt, '.', n))
	{
		if (*(tmp + 1) == '*')
			flag->precision = POS(va_arg(ap, int));
		else
			flag->precision = POS(ft_atoi(tmp + 1));
	}
	while (i < n)
	{
		if (isdigit(fmt[i]))
		{
			if (fmt[i - 1] != '.')
				flag->fw = ft_atoi(fmt + i);
			while (isdigit(fmt[i + 1])
				i++;
		}
		else if (fmt[i] == '*' && fmt[i - 1] != '.')
			flag->fw = va_arg(ap, int);
		i++;
	}
}

void	parse_flags(char *fmt, t_flag *flag, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (fmt[i] == '#')
			flag->alt = 1;
		else if (fmt[i] == '-')
			flag->pad_left = 1;
		else if (fmt[i] == ' ')
			flag->blank_sign = 1;
		else if (fmt[i] == '+')
			flag->force_sign = 1;
		else if (fmt[i] == ''')
			flag->format = 1;
		else if (fmt[i] == '0' && !isdigit(fmt + i - 1) ||
							fmt[i] == '.')
			flag->pad_0 = 1;
		i++;
	}
	if (flag->fw < 0)
	{
		flag->pad_left = 1;
		flag->fw = -1 * flag->fw;
	}
}

void	get_alt_size(char *fmt, t_flag *flag, int n)
{
	int	i;

 	if (fmt[n] == 'D' || fmt[n] == 'O' || fmt[n] == 'U')
		flag->alt_size = 1;
	else if (ft_strnoccur(fmt, 'z', n))
		flag->alt_size = 4;
	else if (ft_strnoccur(fmt, 'j', n))
		flag->alt_size = 3;
	else if (i = ft_strnoccur(fmt, 'l', n))
	{
		if (i % 2 == 0)
			flag->alt_size = 2;
		else
			flag->alt_size = 1;
	}
	else if (i = ft_strnoccur(fmt, 'h', n))
	{
		if (i % 2 == 0)
			flag->alt_size = -2;
		else
			flag->alt_size = -1;
	}
}

void	parse_em_all(char *fmt, va_list ap, t_flag *flag, t_list *list)
{
	int	len;
	char	*tmp;

	raz_flags(flag);
	len = get_arg_len(fmt, flag);
	parse_width(fmt, flag, ap, len);
	parse_flags(fmt, flag, len);
	get_alt_size(fmt, flag, len);

