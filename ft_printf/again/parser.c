/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <cdesvern@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:58:50 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/02 15:00:26 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_arg_len(va_list *ap, char *fmt, t_flag flag)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*fmt == '%')
		return (0);
	while (*(fmt + i) && !ft_strchr(TYPE_LIST, *(fmt + i)))
		i++;
	if (*(fmt + i) == '\0')
		return (-1);
	while (j < i)
	{
		if (!ft_strchr(TYPE_LIST FLAG_LIST, *(fmt + j)))
			if (!isdigit(*(fmt + j)))
				return (-1);
		j++;
	}
	return (i);
}

int	parse_args(char *fmt, t_flag flag, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (isdigit(fmt + i) && *(fmt + i) != 0)
