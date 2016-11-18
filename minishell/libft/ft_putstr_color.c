/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 09:53:53 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/06 11:49:28 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_colors.h"

void	ft_putstr_color(char *str, char *color)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(CEND);
}
