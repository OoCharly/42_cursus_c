/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 16:34:13 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/13 18:46:59 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstsort(t_list **alst, t_list *new, int (*f)(void *, void *))
{
	t_list	*cp;
	t_list	*mem;

	if (alst && new)
	{
		if (!*alst)
		{
			*alst = new;
			return ;
		}
		cp = *alst;
		while (cp)
		{
			if (f)
			{
				if ((*f)(cp->content, new->content) < 0)
				{
					new->next = cp->next;
					cp->next = new;
					return ;
				}
			}
			mem = cp;
			cp = cp->next;
		}
		mem->next = new;
	}
}
