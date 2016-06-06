/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:50:17 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/06 10:58:26 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	get_integer_final_size(char *s, t_flag *f)
{
	size_t	out;

	out = ft_strlen(s);
	if (f->alt && f->base == 8)
		out++;
	if ((int)out < f->precision)
		out = f->precision;
	if (f->alt && f->base == 16)
		out += 2;
	if (f->sign_force && ft_strchr(SINTEGER_TYPE, f->type))
		out++;
	if (out <= f->fw)
		out = f->fw;
	else
	{
		f->fw = 0;
		f->pad_0 = 0;
	}
	f->size = out;
}

static	void	get_string_final_size(char *s, t_flag *f)
{
	size_t	out;

	out = ft_strlen(s);
	if (f->precision > -1)
	{
		if (ft_strchr("sScC", f->type) && f->type && f->precision < out)
			out = f->precision;
		else
			f->precision = -1;
	}
	if (f->fw > out)
		out = f->fw;
	else
		f->fw = 0;
	f->size = out;
}

static	char	*ft_precision_integer(t_flag *f, char *s)
{
	size_t	len;
	size_t	diff;
	char	*out;

	if (!(out = ft_memalloc(f->size)))
		return (NULL);
	len = ft_strlen(s);
	ft_memcpy(out, s, len);
	free(s);
	diff = POS((int)(f->precision - len));
	if (!f->precision && *out == '0')
	{
		*out = f->sign_force;
		f->sign_force = '\0';
		f->fw = (f->fw) ? f->fw + 1 : --f->size;
	}
	if (!diff)
		return (out);
	else
	{
		ft_memmove(out + diff, out, len);
		ft_memset(out, '0', diff);
	}
	return (out);
}

static	char	*ft_integer_transform(t_flag *f, va_list ap)
{
	char	*out;

	if (ft_strchr(SINTEGER_TYPE, f->type))
	{
		if (!(out = ft_printf_render_signedint(ap, f)))
			return (NULL);
		if (out[0] == '-')
		{
			f->sign_force = '-';
			ft_memmove(out, out + 1, ft_strlen(out));
		}
	}
	else
	{
		if (!(out = ft_printf_render_unsignedint(ap, f)))
			return (NULL);
		if (out[0] == '0' && ft_tolower(f->type) == 'x')
			f->alt = 0;
	}
	get_integer_final_size(out, f);
	out = ft_precision_integer(f, out);
	return ((out) ? out : NULL);
}

char			*ft_printf_transform(t_flag *f, va_list ap)
{
	size_t	len;
	char	*out;

	if (ft_strchr(INTEGER_TYPE, f->type) && f->type)
		return (ft_integer_transform(f, ap));
	else if (ft_tolower(f->type) == 's')
		out = ft_printf_render_string(ap, f);
	else if (ft_tolower(f->type) == 'c')
		out = (ft_printf_render_char(ap, f));
	else if (ft_strchr(DOUBLE_TYPE, f->type) && f->type)
		out = (ft_memalloc(0));
	else
		out = ft_wchar_to_string(f->type);
	get_string_final_size(out, f);
	len = ft_strlen(out);
	if (f->precision >= 0 && ft_strchr("sScC", f->type))
		ft_memset(out + f->precision, 0, (len - f->precision));
	return (out);
}
