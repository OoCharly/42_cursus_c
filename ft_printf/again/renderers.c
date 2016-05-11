/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:56:46 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/11 20:47:26 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_render_integers(va_list ap, t_flag *f)
{
	if (f->alt_size == -2)
		return (ft_ntoa_base((char)va_arg(ap, int), f->base, f->signd));
	if (f->alt_size == -1)
		return (ft_ntoa_base((short)va_arg(ap, int), f->base, f->signd));
	if (f->alt_size == 0)
		return (ft_ntoa_base(va_arg(ap, int), f->base, f->signd));
	if (f->alt_size == 1)
		return (ft_ntoa_base(va_arg(ap, long), f->base, f->signd));
	if (f->alt_size == 2)
		return (ft_ntoa_base(va_arg(ap, long long), f->base, f->signd));
	if (f->alt_size == 3)
		return (ft_ntoa_base(va_arg(ap, intmax_t), f->base, f->signd));
	if (f->alt_size == 4)
		return (ft_ntoa_base(va_arg(ap, ssize_t), f->base, f->signd));
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
