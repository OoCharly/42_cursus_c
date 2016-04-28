/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:56:46 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/28 15:58:38 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_render_numbers(va_list *ap, t_flag *f)
{
	if (f->alt_size == -2)
		return (ft_ntoa_base(va_arg(ap, char), f->base, f->sign));
	if (f->alt_size == -1)
		return (ft_ntoa_base(va_arg(ap, short), f->base, f->sign));
	if (f->alt_size == 0)
		return (ft_ntoa_base(va_arg(ap, int), f->base, f->sign));
	if (f->alt_size == 1)
		return (ft_ntoa_base(va_arg(ap, long), f->base, f->sign));
	if (f->alt_size == 2)
		return (ft_ntoa_base(va_arg(ap, long long), f->base, f->sign));
	if (f->alt_size == 3)
		return (ft_ntoa_base(va_arg(ap, intmax_t), f->base, f->sign));
	if (f->alt_size == 4)
		return (ft_ntoa_base(va_arg(ap, ssize_t), f->base, f->sign));
}

