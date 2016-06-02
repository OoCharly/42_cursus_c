/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 10:48:10 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/02 19:54:44 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_integer_padding(t_flag *f, char *s)
{
	int		len;
	char	*out;
	char	c;

	c = (f->pad_0) ? '0' : ' ';
	len = ft_strlen(s);
	if (f->fw > len)
	{
		if (!(out = ft_memset(ft_strnew(f->fw - len), c, f->fw - len)))
			return (NULL);
		if (f->pad_left)
			out = ft_strfjoin(s, out);
		else
			out = ft_strfjoin(out, s);
		if (!out)
			return (NULL);
		if (f->pad_0 && ft_strchr(SINTEGER_TYPE, f->type) && f->sign_force)
			out[0] = f->sign_force;
	}
	else
		out = ft_strfjoin(ft_wchar_to_string(f->sign_force), s);
	return (out);
}

char	*ft_padding(t_flag *f, char *s)
{
	int		len;
	char	*out;
	char	c;

	c = (f->pad_0) ? '0' : ' ';
	len = ft_strlen(s);
	if (f->fw > len)
	{
		if (!(out = ft_memset(ft_strnew(f->fw - len), c, f->fw - len)))
			return (NULL);
		if (f->pad_left)
			out = ft_strfjoin(s, out);
		else
			out = ft_strfjoin(out, s);
		if (!out)
			return (NULL);
	}
	else
		out = s;
	return (out);
}

char	*ft_alt_format(char *s, t_flag *f)
{
	char	*out;

	if ((f->type == 'o' || f->type == 'O') && s[0] != '0')
	{
		out = ft_strjoin("0", s);
		free(s);
	}
	else if (f->type == 'x' || f->type == 'X' || f->type == 'p')
	{
		if (f->pad_0 && f->precision <= 0 && f->fw)
		{
			f->fw = POS(f->fw - 2);
			out = ft_integer_padding(f, s);
			s = out;
		}
		out = ft_strjoin("0x", s);
		free(s);
	}
	else
		out = s;
	return (out);
}

char	*ft_process(t_flag *flag, va_list ap)
{
	char	*out;

	if (!(out = ft_transform(flag, ap)))
		return (NULL);
	if (flag->alt)
	{
		if (!(out = ft_alt_format(out, flag)))
			return (NULL);
	}
	if (flag->type == 'X')
		ft_capitalize(out);
	if (ft_strchr(INTEGER_TYPE, flag->type) && flag->type)
	{
		if (flag->sign_force && !flag->pad_0)
		{
			if (!(out = ft_strfjoin(ft_wchar_to_string(flag->sign_force), out)))
				return (NULL);
			flag->sign_force = 0;
		}
		out = ft_integer_padding(flag, out);
	}
	else
		out = ft_padding(flag, out);
	return (out);
}
