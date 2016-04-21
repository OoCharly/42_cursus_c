/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 14:58:53 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/21 12:38:05 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*ft_init_flags(void)
{
	t_flag	*flag;

	if (!(flag = ft_memalloc(sizeof(t_flag))))
		return (NULL);
/*	useless ?
 *
 *	flag->alt = 0;
 *	flag->pad_0 = 0;
 *	flag->pad_left = 0;
 *	flag->alt_size = 0;
 *	flag->min_fw = 0;
 *	flag->precision = 0;
 */
	flag->sign_force = "";
	return(flag);
}

void	get_min_width(char *fmt, size_t n, t_flag flag)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (isnum(fmt + i) && *(fmt + i) != '0')
		{
			flag->min_fw = ft_atoi(fmt + i);
			return ;
		}
		else if (*(fmt + i) == '0')
		{
			if (!flag->pad_left)
				flag->pad_0 = 1;
		}
		i++;
	}
}

void	get_modif_size(char *fmt, size_t n, t_flag flag)
{
	char	*tmp;
	int		i;

	if ((i = ft_strnoccur(fmt, 'h', n)) == 1)
	{
		flag->alt_size = -i;
		if (i > 1)
			flag->alt_size = -2;
	}
	if ((i = ft_strnoccur(fmt, 'l', n)) == 1)
	{
		flag->alt_size = i;
		if (i > 1)
			flag->alt_size = 2;
	}
	if ((i = ft_strnoccur(fmt, 'j', n)))
		flag->alt_size = 3;
	if ((i = ft_strnoccur(fmt, 'z', n)))
		flag->alt_size = 4;
}

size_t	get_arg_len(char *fmt)
{
	size_t	i;

	i = 0;
	if (!*fmt)
		return (0);
	while (!ft_strchr(LIST_FORMAT, *fmt))
	{
		i++;
		fmt++;
	}
	return (i);
}

t_flag	*ft_get_flags(char *fmt)
{
	size_t	n;
	t_flag	*flag;

	if (!(flag = ft_init_flag()))
		return (NULL);
	n = get_arg_len(fmt);
	if (!check_args(fmt, n))
		return (NULL)
	if (ft_strnchr(fmt, '#', n))
		flag->alt = 1;
	if (ft_strnchr(fmt, '-', n))
		flag->pad_left = 1;
	if (ft_strnchr(fmt, '+', n))
		flag->sign_force = '+';
	if (ft_strnchr(fmt, ' ', n))
	{
		if (!flag->sign_force)
			flag->sign_force = ' ';
	}
	get_min_width(fmt, n, flag);
	get_modif_size(fmt, n, flag);
	flag->type = fmt[n - 1];
	return (flag);
}
