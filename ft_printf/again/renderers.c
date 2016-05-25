/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:56:46 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/25 17:12:32 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_render_unsigned_integers(va_list ap, t_flag *f)
{
	char	*out;

	out = NULL;
	if (f->alt_size == -2)
		out = (ft_ntoa_base((unsigned char)va_arg(ap, int), f->base));
	else if (f->alt_size == -1)
		out = (ft_ntoa_base((unsigned short)va_arg(ap, int), f->base));
	else if (f->alt_size == 0)
		out = (ft_ntoa_base(va_arg(ap, unsigned int), f->base));
	else if (f->alt_size == 1)
		out = (ft_ntoa_base(va_arg(ap, unsigned long), f->base));
	else if (f->alt_size == 2)
		out = (ft_ntoa_base(va_arg(ap, unsigned long long), f->base));
	else if (f->alt_size == 3)
		out = (ft_ntoa_base(va_arg(ap, uintmax_t), f->base));
	else if (f->alt_size == 4)
		out = (ft_ntoa_base(va_arg(ap, size_t), f->base));
	if (!out)
		exit(-1);
	return (out);
}

char	*ft_render_signed_integers(va_list ap, t_flag *f)
{
	char	*out;

	if (f->alt_size == -2)
		out = (ft_ntoa((char)va_arg(ap, int)));
	else if (f->alt_size == -1)
		out = (ft_ntoa((short)va_arg(ap, int)));
	else if (f->alt_size == 0)
		out = (ft_ntoa(va_arg(ap, int)));
	else if (f->alt_size == 1)
		out = (ft_ntoa(va_arg(ap, long)));
	else if (f->alt_size == 2)
		out = (ft_ntoa(va_arg(ap, long long)));
	else if (f->alt_size == 3)
		out = (ft_ntoa(va_arg(ap, intmax_t)));
	else if (f->alt_size == 4)
		out = (ft_ntoa(va_arg(ap, ssize_t)));
	if (!out)
		exit(-1);
	return (out);
}

char	*ft_render_string(va_list ap, t_flag *f, int c)
{
	char	*out;
	char	*tmp;

	if (!c)
		if (f->alt_size == 1)
			out = (ft_wstring_to_string(va_arg(ap, wchar_t*)));
		else
			out = (ft_strdup(va_arg(ap, char*)));
	else
		if (f->alt_size == 1)
			out = (ft_wchar_to_string(va_arg(ap, wchar_t)));
		else
		{
			if (!(out = ft_memalloc(sizeof(char) * 2)))
				exit(-1);
			out[0] = (char)va_arg(ap, int);
		}
	if (!out)
		exit(-1);
	if (f->precision >= 0 && ft_strlen(out) > f->precision)
	{
		tmp = out;
		out = ft_strndup(out, f->precision);
		free(tmp);
		f->precision = -1;
	}
	return (out);
}
