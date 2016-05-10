/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:36:32 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/10 15:47:08 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*raz_flags(t_flag *flag)
{
	if (flag)
	{
		flag->alt = 0;
		flag->pad_0 = 0;
		flag->pad_left = 0;
		flag->signd = 0;
		flag->alt_size = 0;
		flag->sign_force = 0;
		flag->fw = 0;
		flag->precision = 0;
		flag->type = 0;
		return (flag);
	}
	else
		return (ft_memalloc(sizeof(t_flag)));
}
