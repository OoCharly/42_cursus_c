/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 16:34:13 by cdesvern          #+#    #+#             */
/*   Updated: 2016/08/31 17:04:29 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **alst, t_list *new, int (*f)(void *, void *))
{
	t_list	*cp;

	if (alst && new)
	{
		cp = *alst;
		while (cp->next)
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
			cp = cp->next;
		}
		cp->next = new;
	}
}
