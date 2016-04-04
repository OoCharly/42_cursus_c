/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 17:10:19 by cdesvern          #+#    #+#             */
/*   Updated: 2016/04/04 17:20:36 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**ft_lstpnew(void const *content, size_t content_size)
{
	t_list	**out;

	if (!(out = (t_list**)ft_memalloc(sizeof(t_list*))))
		return (NULL);
	if (!(*out = ft_lstnew(content, content_size)))
	{
		free(out);
		return (NULL);
	}
	return (out);
}
