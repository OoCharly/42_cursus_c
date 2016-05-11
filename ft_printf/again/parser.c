/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:58:50 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/11 20:47:16 by cdesvern         ###   ########.fr       */
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
			return (-i);
		i++;
	}
	if (fmt[i] == '\0')
		return (-i);
	flag->type = fmt[i];
	return (i);
}

void	parse_width(char *fmt, t_flag *flag, va_list ap, int n)
{
	int	i;
	char	*tmp;

	i = 0;
	if ((tmp = ft_strnrchr(fmt, '.', n)))
	{
		flag->pad_0 = 0;
		if (*(tmp + 1) == '*')
			flag->precision = POS(va_arg(ap, int));
		else
			flag->precision = POS(ft_atoi(tmp + 1));
	}
	while (i < n)
	{
		if (ft_isdigit(fmt[i]))
		{
			if (fmt[i - 1] != '.')
				flag->fw = ft_atoi(fmt + i);
			while (ft_isdigit(fmt[i + 1]))
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
		else if (fmt[i] == ' ' && !flag->sign_force)
			flag->sign_force = 1;
		else if (fmt[i] == '+')
			flag->sign_force = 2;
		else if (fmt[i] == '\'')
			flag->format = 1;
		else if ((fmt[i] == '0' && !ft_isdigit(fmt[i - 1])))
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

int		ft_parse_em_all(char *fmt, va_list ap, t_flag *flag, t_list **list)
{
	int	len;
	char	*tmp;

	flag = raz_flags(flag);
	len = get_arg_len(fmt, flag);
	if (len <= 0)
		return (-len);
	parse_flags(fmt, flag, len);
	parse_width(fmt, flag, ap, len);
	get_alt_size(fmt, flag, len);
	if (ft_tolower(flag->type) == 'o')
		flag->base = 8;
	if (ft_tolower(flag->type) == 'x' || flag->type == 'p')
		flag->base = 16;
	tmp = ft_process(flag, list, ap);
	ft_lstadd_end(list, ft_lstcreate(tmp, ft_strlen(tmp)));
	return (len);
}
