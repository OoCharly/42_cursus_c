/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:56:46 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/12 16:10:59 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_render_unsigned_integers(va_list ap, t_flag *f)
{
	if (f->alt_size == -2)
		return (ft_ntoa_base((unsigned char)va_arg(ap, int), f->base));
	if (f->alt_size == -1)
		return (ft_ntoa_base((unsigned short)va_arg(ap, int), f->base));
	if (f->alt_size == 0)
		return (ft_ntoa_base(va_arg(ap, unsigned int), f->base));
	if (f->alt_size == 1)
		return (ft_ntoa_base(va_arg(ap, unsigned long), f->base));
	if (f->alt_size == 2)
		return (ft_ntoa_base(va_arg(ap, unsigned long long), f->base));
	if (f->alt_size == 3)
		return (ft_ntoa_base(va_arg(ap, uintmax_t), f->base));
	if (f->alt_size == 4)
		return (ft_ntoa_base(va_arg(ap, size_t), f->base));
	return (0);
}

char	*ft_render_signed_integers(va_list ap, t_flag *f)
{
	if (f->alt_size == -2)
		return (ft_ntoa((char)va_arg(ap, int)));
	if (f->alt_size == -1)
		return (ft_ntoa((short)va_arg(ap, int)));
	if (f->alt_size == 0)
		return (ft_ntoa(va_arg(ap, int)));
	if (f->alt_size == 1)
		return (ft_ntoa(va_arg(ap, long)));
	if (f->alt_size == 2)
		return (ft_ntoa(va_arg(ap, long long)));
	if (f->alt_size == 3)
		return (ft_ntoa(va_arg(ap, intmax_t)));
	if (f->alt_size == 4)
		return (ft_ntoa(va_arg(ap, ssize_t)));
	return (0);
}

char	*ft_render_string(va_list ap, t_flag *f, int c)
{
	char	*out;

	if (!c)
	{
		if (f->alt_size == 1)
			return (ft_wstring_to_string(va_arg(ap, wchar_t*)));
		else
			return (va_arg(ap, char*));
	}
	else
	{
		if (f->alt_size == 1)
			return (ft_wchar_to_string(va_arg(ap, wchar_t)));
		else
		{
			if (!(out = ft_memalloc(sizeof(char) *2)))
				return (NULL);
			out [0] = (char)va_arg(ap, int);
			return (out);
		}
	}
}
