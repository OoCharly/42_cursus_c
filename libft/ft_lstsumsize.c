/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsumsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:18:16 by cdesvern          #+#    #+#             */
/*   Updated: 2016/05/11 12:14:32 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsumsize(t_list **lst)
{
	size_t	out;
	t_list	*tmp;

	if (!lst)
		return (0);
	if (!*lst)
		return (0);
	out = 0;
	tmp = *lst;
	while (tmp->next)
	{
		out += tmp->content_size;
		tmp = tmp->next;
	}
	return (out + tmp->content_size);
}
