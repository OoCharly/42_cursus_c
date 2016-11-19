/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc_manip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 20:30:06 by cdesvern          #+#    #+#             */
/*   Updated: 2016/11/19 20:34:23 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_dclist	**dc_create(char *elem)
{
	t_dclist	**lst;

	if (!(lst = ft_memalloc(sizeof(t_dclist*))) &&
			!(*lst = ft_memalloc(sizeof(t_dlist))))
		return (NULL);
	(*lst)->elem = elem;
	(*lst)->DC_PREV = NULL;
	(*lst)->DC_NEXT = NULL;
	return (lst);
}
