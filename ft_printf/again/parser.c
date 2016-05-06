/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:58:50 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/04 12:40:31 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_arg_len(va_list *ap, char *fmt, t_flag flag)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*fmt == '%')
		return (0);
	while (*(fmt + i) && !ft_strchr(TYPE_LIST, *(fmt + i)))
		i++;
	if (*(fmt + i) == '\0')
		return (-1);
	while (j < i)
	{
		if (!ft_strchr(TYPE_LIST FLAG_LIST, *(fmt + j)))
			if (!isdigit(*(fmt + j)))
				return (-1);
		j++;
	}
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
			flag->precision = va_arg(ap, int);
		else
			flag->precision = ft_atoi(tmp + 1);
	}
	while (i < n)
	{
		if (isdigit(fmt + i))
		{
			if (*(fmt + i - 1) != '.')
				flag->fw = ft_atoi(fmt + i);
			while (isdigit(fmt + i + 1))
				i++;
		}
		else if (*(fmt + i) == '*' && *(fmt + i - 1) != '.')
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
		if (*(fmt + i) == '#')
			flag->alt = 1;
		else if (*(fmt + i) == '-')
			flag->pad_left = 1;
		else if (*(fmt + i) == ' ')
			flag->blank_sign = 1;
		else if (*(fmt + i) == '+')
			flag->force_sign = 1;
		else if (*(fmt + i) == ''')
			flag->format = 1;
		else if (*(fmt + i) == '0' && !isdigit(fmt + i - 1) ||
														*(fmt + i) == '.')
			flag->pad_0 = 1;
		i++;
	}
}

void	get_alt_size(char *fmt, t_flag *flag, int n)
{
	int	i;

	if (ft_strnoccur(fmt, 'z', n))
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
			flqg->alt_size = -2;
		else
			flag->alt_size = -1;
	}
}
