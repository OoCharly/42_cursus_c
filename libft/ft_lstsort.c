/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 16:34:13 by cdesvern          #+#    #+#             */
/*   Updated: 2016/09/19 17:03:45 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **alst, t_list *new, int (*f)(void *, void *))
{
	t_list	*cp;
	t_list	*mem;

	if (!(cp = *alst))
	{
		*alst = new;
		return ;
	}
	mem = NULL;
	while (cp)
	{
		if (f)
		{
			if ((*f)(cp->content, new->content) < 0)
			{
				if (mem)
					mem->next = new;
				else
					*alst = new;
				new->next = cp;
				return ;
			}
		mem = cp;
		cp = cp->next;
	}}
	mem->next = new;
}
