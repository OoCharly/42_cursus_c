/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 10:48:03 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/31 19:08:51 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getbase(t_flag *flag)
{
	if (ft_tolower(flag->type) == 'p')
	{
		flag->base = 16;
		flag->alt = 1;
		flag->alt_size = 1;
	}
	if (ft_tolower(flag->type) == 'x')
		flag->base = 16;
	else if (ft_tolower(flag->type) == 'o')
		flag->base = 8;
	else if (ft_tolower(flag->type) == 'b')
		flag->base = 2;
}

char	*ft_precision_string(t_flag *f, char *s)
{
	int		len;
	char    *out;

	len = ft_strlen(s);
	if (f->precision >= 0 && f->precision < (int)len)
	{
		if (!(out = ft_strndup(s, (size_t)f->precision)))
			exit(-1);
		free(s);
	}
	else
		out = s;
	return (out);
}

char    *ft_precision_integer(t_flag *f, char *s)
{
	int             len;
	char    *out;

	len = ft_strlen(s);
	if (f->precision == 0 && s[0] == '0' && !f->pad_0)
	{
		s[0] = f->sign_force;
		f->sign_force = '\0';
		return (s);
	}
	else if (POS(f->precision - len))
	{
		out = ft_memset(ft_strnew(f->precision - len), '0', f->precision - len);
		out = ft_strfjoin(out, s);
		if (!out)
			exit(-1);
	}
	else
		out = s;
	return (out);
}

char	*ft_integer_transform(t_flag *f, va_list ap)
{
	char	*out;
	char	*tmp;

	if (ft_strchr(INTEGER_TYPE, f->type))
	{
		out = ft_render_signed_integers(ap, f);
		if (out[0] == '-')
		{
			f->sign_force = '-';
			tmp = out;
			out = ft_strdup(out + 1);
			free(tmp);
		}
		out = ft_precision_integer(f, out);
	}
	else
	{
		f->sign_force = '\0';
		ft_getbase(f);
		out = ft_render_unsigned_integers(ap, f);
		if (out[0] == '0' && ft_tolower(f->type) == 'x')
			f->alt = 0;
		out = ft_precision_integer(f, out);
	}
	return (out);
}

char    *ft_transform(t_flag *f, va_list ap)
{
	char    *out;
	
	if (f->type == '%')
		return (ft_wchar_to_string('%'));
	else if (ft_strchr(INTEGER_TYPE UINTEGER_TYPE, f->type) && f->type)
		return (ft_integer_transform(f, ap));
	else if (ft_tolower(f->type) == 's')
	{
		out = ft_render_string(ap, f);
		out = ft_precision_string(f, out);
		return (out);
	}
	else if (ft_tolower(f->type == 'c'))
		return (ft_render_char(ap, f));
	else if (ft_strchr(DOUBLE_TYPE, f->type) && f->type)
	{
		return (ft_memalloc(0));
	}
	else
		return (ft_wchar_to_string(f->type));
}
