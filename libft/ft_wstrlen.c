/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 19:40:02 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/02 19:41:32 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(wchar_t *ws)
{
	int	i;

	i = 0;
	if (!ws)
		return (0);
	while (*ws)
	{
		i++;
		ws++;
	}
	return (i);
}
