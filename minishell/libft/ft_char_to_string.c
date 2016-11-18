/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:16:06 by cdesvern          #+#    #+#             */
/*   Updated: 2016/06/02 16:17:41 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_char_to_string(int c)
{
	char	*out;

	if (!(out = ft_memalloc(2)))
		return (NULL);
	else
		out[0] = (char)c;
	return (out);
}
