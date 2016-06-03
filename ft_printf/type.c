/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 10:48:03 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/03 20:52:17 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision_integer(t_flag *f, char *s)
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

void	ft_precision_string(t_flag *f, char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (f->precision >= 0 && ft_strchr("sScC", f->type))
		ft_memset(s + f->precision, 0, (len - f->precision));
}

char	*ft_integer_transform(t_flag *f, va_list ap)
{
	char	*out;

	if (ft_strchr(SINTEGER_TYPE, f->type))
	{
		if (!(out = ft_render_signed_integers(ap, f)))
			return (NULL);
		if (out[0] == '-')
		{
			f->sign_force = '-';
			ft_memmove(out, out + 1, ft_strlen(out));
		}
	}
	else
	{
		if (!(out = ft_render_unsigned_integers(ap, f)))
			return (NULL);
		if (out[0] == '0' && ft_tolower(f->type) == 'x')
			f->alt = 0;
	}
	get_integer_final_size(out, f);
	out = ft_precision_integer(f, out);
	return ((out) ? out : NULL);
}

char	*ft_transform(t_flag *f, va_list ap)
{
	char	*out;

	if (ft_strchr(INTEGER_TYPE, f->type) && f->type)
		return (ft_integer_transform(f, ap));
	else if (ft_tolower(f->type) == 's')
		out = ft_render_string(ap, f);
	else if (ft_tolower(f->type) == 'c')
		out = (ft_render_char(ap, f));
	else if (ft_strchr(DOUBLE_TYPE, f->type) && f->type)
		out = (ft_memalloc(0));
	else
		out = ft_wchar_to_string(f->type);
	get_string_final_size(out, f);
	ft_precision_string(f, out);
	return (out);
}
