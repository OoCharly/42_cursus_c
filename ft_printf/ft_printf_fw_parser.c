/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fw_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 17:11:27 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/03 18:40:31 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	wildcase_parse(char *fmt, t_flag *f, va_list ap, int n)
{
	int	i;
	int	p;

	i = 0;
	while (i < n)
	{
		if (fmt[i] == '*')
		{
			p = va_arg(ap, int);
			if (fmt[i - 1] == '.')
			{
				if (p >= 0)
					f->precision = p;
			}
			else
				f->fw = p;
		}
		i++;
	}
}

static void	parse_width(char *fmt, t_flag *flag, int n)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	while (i < n)
	{
		if (ft_isdigit(fmt[i]) && fmt[i] != '0' && fmt[i - 1] != '.')
			f = ft_atoi(fmt + i);
		if (fmt[i] == '*' && fmt[i - 1] != '.')
			f = flag->fw;
		if (fmt[i] != '0' && ft_isdigit(fmt[i]))
		{
			while (ft_isdigit(fmt[i]))
				i++;
		}
		else
			i++;
	}
	flag->fw = f;
}

static void	parse_precision(char *fmt, t_flag *f, int n)
{
	int	i;
	int	p;

	i = 0;
	p = -1;
	while (i < n)
	{
		if (fmt[i] == '.')
		{
			i++;
			if (fmt[i] == '*')
				p = f->precision;
			else
				p = ft_atoi(fmt + i);
			while (ft_isdigit(fmt[i]))
				i++;
		}
		else
			i++;
	}
	if (p >= 0)
		f->precision = p;
}

static void	parse_flags(char *fmt, t_flag *flag, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (fmt[i] == '#')
			flag->alt = 1;
		else if (fmt[i] == '-')
			flag->pad_left = 1;
		else if (fmt[i] == ' ' && !flag->sign_force)
			flag->sign_force = ' ';
		else if (fmt[i] == '+')
			flag->sign_force = '+';
		else if (fmt[i] == '0' && !ft_isdigit(fmt[i - 1]) && fmt[i - 1] != '.')
			flag->pad_0 = 1;
		i++;
	}
}

void		ft_printf_field_parser(char *fmt, va_list ap, t_flag *f, int n)
{
	wildcase_parse(fmt, f, ap, n);
	parse_width(fmt, f, n);
	parse_precision(fmt, f, n);
	parse_flags(fmt, f, n);
}
