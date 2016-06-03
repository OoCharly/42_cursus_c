/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:56:46 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/03 20:55:42 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*wstring_precision(wchar_t *ws, t_flag *f)
{
	char	*out;
	char	*tmp;

	if (!(out = ft_memalloc(sizeof(char) * f->precision)))
		return (NULL);
	tmp = ft_wchar_to_string(*ws);
	while ((ft_strlen(tmp) + ft_strlen(out)) <= f->precision && *ws)
	{
		ft_strcat(out, tmp);
		free(tmp);
		ws++;
		tmp = ft_wchar_to_string(*ws);
	}
	free(tmp);
	f->precision = -1;
	return (out);
}

char	*ft_render_unsigned_integers(va_list ap, t_flag *f)
{
	char	*out;

	out = NULL;
	if (f->alt_size == -2)
		out = (ft_ntoa_base((unsigned char)va_arg(ap, int), f->base));
	else if (f->alt_size == -1)
		out = (ft_ntoa_base((unsigned short)va_arg(ap, int), f->base));
	else if (f->alt_size == 1)
		out = (ft_ntoa_base(va_arg(ap, unsigned long), f->base));
	else if (f->alt_size == 2)
		out = (ft_ntoa_base(va_arg(ap, unsigned long long), f->base));
	else if (f->alt_size == 3)
		out = (ft_ntoa_base(va_arg(ap, uintmax_t), f->base));
	else if (f->alt_size == 4)
		out = (ft_ntoa_base(va_arg(ap, size_t), f->base));
	else
		out = (ft_ntoa_base(va_arg(ap, unsigned int), f->base));
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
	else if (f->alt_size == 1)
		out = (ft_ntoa(va_arg(ap, long)));
	else if (f->alt_size == 2)
		out = (ft_ntoa(va_arg(ap, long long)));
	else if (f->alt_size == 3)
		out = (ft_ntoa(va_arg(ap, intmax_t)));
	else if (f->alt_size == 4)
		out = (ft_ntoa(va_arg(ap, ssize_t)));
	else
		out = (ft_ntoa(va_arg(ap, int)));
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
		{
			if (f->precision >= 0)
				out = wstring_precision(wtmp, f);
			else
				out = ft_wstring_to_string(wtmp);
		}
	}
	else
	{
		if (!(tmp = va_arg(ap, char*)))
			out = ft_strdup("(null)");
		else
			out = (ft_strdup(tmp));
	}
	return ((out) ? out : NULL);
}

char	*ft_render_char(va_list ap, t_flag *f)
{
	char	*out;

	if (f->alt_size == 1)
		out = ft_wchar_to_string(va_arg(ap, int));
	else
		out = ft_char_to_string(va_arg(ap, int));
	if (!out)
		return (NULL);
	if (!*out)
		f->precision = -2;
	return (out);
}
