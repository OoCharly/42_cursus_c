/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 10:48:10 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/03 20:51:46 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_integer_final_size(char *s, t_flag *f)
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

void	get_string_final_size(char *s, t_flag *f)
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

void	ft_padding(t_flag *f, char *s)
{
	int		len;
	char	c;

	c = (f->pad_0) ? '0' : ' ';
	len = ft_strlen(s);
	if (f->fw > len)
	{
		if (f->pad_left)
			ft_memset(s + len, c, f->fw - len);
		else
		{
			ft_memmove(s + (f->fw - len), s, len);
			ft_memset(s, c, f->fw - len);
		}
	}
	if (f->pad_0 && f->sign_force)
		s[0] = f->sign_force;
	if (f->precision == -2)
	{
		len = ft_strlen(s);
		ft_memset(s + ((len - 1) * !f->pad_left), 0, 1);
		f->size = (f->fw) ? f->fw-- : 1;
	}
}

void	ft_alt_format(char *s, t_flag *f)
{
	int		len;

	len = ft_strlen(s);
	if (f->type == 'o' || f->type == 'O')
	{
		if (s[0] != '0')
		{
			ft_memmove(s + 1, s, len);
			ft_memset(s, '0', 1);
		}
		else if (s[0] == '0' && len == 1 && f->precision < 0)
			f->size--;
	}
	else if (f->type == 'x' || f->type == 'X' || f->type == 'p')
	{
		if (f->pad_0 && f->fw)
			ft_padding(f, s);
		ft_memmove(s + 2, s, len);
		s[0] = '0';
		s[1] = 'x';
	}
}

char	*ft_process(t_flag *flag, va_list ap)
{
	char	*out;
	int		len;

	if (!(out = ft_transform(flag, ap)))
		return (NULL);
	len = ft_strlen(out);
	if (flag->alt)
		ft_alt_format(out, flag);
	if (flag->type == 'X')
		ft_capitalize(out);
	if (flag->sign_force && !flag->pad_0)
	{
		ft_memmove(out + 1, out, len);
		out[0] = flag->sign_force;
		flag->sign_force = 0;
	}
	ft_padding(flag, out);
	return (out);
}
