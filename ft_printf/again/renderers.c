/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:56:46 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/01 23:55:48 by cdesvern         ###   ########.fr       */
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
	else
		return (NULL);
	if (!out)
		return (NULL);
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
	else
		return (NULL);
	if (!out)
		return (NULL);
	return (out);
}

char	*ft_render_string(va_list ap, t_flag *f)
{
	char	*out;
	char	*tmp;
	wchar_t	*wtmp;

	if (f->alt_size == 1)
	{
		if (!(wtmp = va_arg(ap, wchar_t*)))
			out = ft_strdup("(null)");
		else
			out = (ft_wstring_to_string(wtmp));
	}
	else
	{
		if (!(tmp = va_arg(ap, char*)))
			out = ft_strdup("(null)");
		else
			out = (ft_strdup(tmp));
	}
	if (!out)
		return (NULL);
	return (out);
}

char	*ft_render_char(va_list ap, t_flag *f)
{
	char	*out;

	if (!(out = ft_wchar_to_string(va_arg(ap, int))))
		return (NULL);
	if (!*out)
	{
		f->fw = POS(f->fw - 1);
		f->precision = -2;
	}
	return (out);
}
